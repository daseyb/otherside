using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using HtmlAgilityPack;

namespace SpecParser
{
  class Program
  {
    struct Parameter
    {
      public bool IsList;
      public string Type;
      public string Name;

      public override string ToString()
      {
        return Name + ":" + Type + (IsList ? "[1..n]" : "");
      }
    }

    struct Op
    {
      public string Name;
      public int Index;
      public List<Parameter> Parameters;

      public Op(string name = "", int index = -1)
      {
        Name = name;
        Index = index;
        Parameters = new List<Parameter>();
      }

      public override string ToString()
      {
        var ret = Name + "(" + Index + "): ";
        foreach (var param in Parameters)
        {
          ret += param + " | ";
        }
        return ret;
      }

      public string GenerateHandlerDecleration()
      {
        return "static void Handle" + Name + " (void* op, Program* prog)";
      }

      public string GenerateStructCode()
      {
        string paramList = "";
        foreach (var param in Parameters)
        {
          var typename = param.Type;

          switch (param.Type)
          {
            case "LiteralNumber":
            case "Id": typename = "uint32"; break;
            case "LiteralString": typename = "char*"; break;
          }

          if (param.IsList)
          {
            paramList += String.Format("\n  uint32 {0}Count;", param.Name);
            typename = typename + "*";
          }

          paramList += String.Format("\n  {0} {1};", typename, param.Name);
        }

        return string.Format("struct S{0} {{{1}\n}};\n", Name, paramList);
      }

      public string GenerateLookupCode()
      {
        string paramList = "";
        foreach (var param in Parameters)
        {
          paramList += String.Format("\n  WordType::T{0},", param.Type + (param.IsList ? "List" : ""));
        }

        return string.Format("static WordType {0}WordTypes[] {{\n  WordType::TOp,{1}\n}};\nstatic uint32 {2}WordTypesCount = {3};\n", Name, paramList, Name, Parameters.Count + 1);
      }
    }

    static void Main(string[] args)
    {
      string htmlCode = null;
      using (WebClient client = new WebClient()) // WebClient class inherits IDisposable
      {
        htmlCode = client.DownloadString("http://www.khronos.org/registry/spir-v/specs/1.0/SPIRV.html");
      }

      if (htmlCode == null)
      {
        return;
      }

      HtmlDocument doc = new HtmlDocument();
      doc.LoadHtml(htmlCode);
      var nodes = doc.DocumentNode.SelectNodes(@"html[1]/body[1]/div[2]/div[4]/div[1]/div[28]/div/table");

      var ops = new List<Op>();

      foreach (var node in nodes)
      {
        var opNode = node.SelectSingleNode("tbody/tr[1]/td/p/a");
        var defNodes = node.SelectNodes("tbody/tr[2]/td/p");
        var wordCount = int.Parse(defNodes[0].InnerText.Split(' ')[0]);

        Op op = new Op(opNode.Attributes[0].Value.Substring(2), int.Parse(defNodes[1].InnerText));

        for (int i = 2; i < defNodes.Count; i++)
        {
          var defNodeText = defNodes[i].InnerText;
          var paramType = "";
          var paramName = (i - 2).ToString();
          bool isList = defNodeText.Contains("&#8230");

          if (defNodeText.Contains("&lt;id&gt;"))
          {
            paramType = "Id";
            if (defNodeText.Contains("Result &lt;id&gt;"))
            {
              paramName = "ResultId";
            }
            else
            {
              var strings = defNodeText.Split('\n');
              if (strings.Length > 1)
              {
                paramName = strings[1].Split(',')[0].Replace(" ", "").Trim('[', ']') + "Id";
              }
              else
              {
                paramName = "Id" + paramName;
              }
            }

          }
          else
          {
            var strings = defNodeText.Split('\n');
            paramType = strings[0].Split(',')[0].Replace(" ", "");

            if (strings.Length > 1)
            {
              paramName = strings[1].Split(',')[0].Replace(" ", "").Trim('[', ']');
            }
            else
            {
              paramName = paramType;
            }

            if (paramType == "literal")
            {
              paramType = "LiteralNumber";
              paramName = paramName.Replace("See", "").Replace(".", "").Trim('[', ']');
            }
          }

          if (isList)
          {
            paramName = paramName.Replace("0", "").Replace("1", "").Replace(",", "").Trim('[', ']');
            if (!paramName.EndsWith("s"))
            {
              paramName += "s";
            }
          }

          switch (paramName)
          {
            case "Thenameoftheopaquetype.": paramName = "OpaqueTypeName"; break;
          }

          op.Parameters.Add(new Parameter() { Type = paramType, Name = paramName, IsList = isList });
        }
        ops.Add(op);
      }

      ops = ops.OrderBy(o => o.Index).ToList();

      ops.ForEach(o => Console.WriteLine(o));

      StringBuilder fileContents = new StringBuilder();

      fileContents.AppendLine("#pragma once");
      fileContents.AppendLine("#include \"lookups.h\"");
      fileContents.AppendLine("#include \"parser_definitions.h\"");
      fileContents.AppendLine("");

      foreach (var op in ops)
      {
        fileContents.AppendLine(op.GenerateHandlerDecleration() + ";");
        fileContents.AppendLine(op.GenerateStructCode());
      }

      fileContents.AppendLine("");
      foreach (var op in ops)
      {
        fileContents.AppendLine(op.GenerateLookupCode());
      }

      fileContents.AppendLine("static void* LUTOpWordTypes[] {");
      foreach (var op in ops)
      {
        fileContents.AppendLine(string.Format("  &{0}WordTypes,", op.Name));
      }
      fileContents.AppendLine("};");
      fileContents.AppendLine("");

      fileContents.AppendLine("static uint32 LUTOpWordTypesCount[] {");
      foreach (var op in ops)
      {
        fileContents.AppendLine(string.Format("  {0}WordTypesCount,", op.Name));
      }
      fileContents.AppendLine("};");
      fileContents.AppendLine("");

      fileContents.AppendLine("typedef void(*OpHandler)(void*, Program*);");
      fileContents.AppendLine("static OpHandler LUTHandlerMethods[] {");
      foreach (var op in ops)
      {
        fileContents.AppendLine(string.Format("  Handle{0},", op.Name));
      }
      fileContents.AppendLine("};");

      File.WriteAllText("lookups_gen.h", fileContents.ToString());

      fileContents.Clear();
      fileContents.AppendLine("#include \"lookups_gen.h\"");
      fileContents.AppendLine("");
      foreach (var op in ops)
      {
        fileContents.AppendLine(op.GenerateHandlerDecleration() + " {");
        fileContents.AppendLine(String.Format("  S{0}* op{0} = (S{0}*)op;", op.Name));
        fileContents.AppendLine("}\n");
      }
      File.WriteAllText("lookups_gen.cpp", fileContents.ToString());
    }
  }
}
