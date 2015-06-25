using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using HtmlAgilityPack;

namespace SpecParser
{
  class Program
  {

    struct Op
    {
      public string Name;
      public int Index;
      public List<string> Parameters;

      public Op(string name = "", int index = -1)
      {
        Name = name;
        Index = index;
        Parameters = new List<string>();
      }

      public override string ToString()
      {
        var ret = Name + "(" + Index + "): ";
        foreach(var param in Parameters)
        {
          ret +=  param + " | ";
        }
        return ret;
      }

      public string GenerateCode()
      {
        string paramList = "";
        foreach (var param in Parameters)
        {
          paramList += String.Format("\n  WordType::T{0},", param);
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

      if(htmlCode == null)
      {
        return;
      }

      HtmlDocument doc = new HtmlDocument();
      doc.LoadHtml(htmlCode);
      var nodes = doc.DocumentNode.SelectNodes(@"html[1]/body[1]/div[2]/div[4]/div[1]/div[28]/div/table");

      var ops = new List<Op>();

      foreach(var node in nodes)
      {
        var opNode = node.SelectSingleNode("tbody/tr[1]/td/p/a");
        var defNodes = node.SelectNodes("tbody/tr[2]/td/p");
        var wordCount = int.Parse(defNodes[0].InnerText.Split(' ')[0]);

        Op op = new Op(opNode.Attributes[0].Value.Substring(2), int.Parse(defNodes[1].InnerText));

        for (int i = 2; i < defNodes.Count; i++)
        {
          var defNodeText = defNodes[i].InnerText;
          if (defNodeText.Contains("&lt;id&gt;"))
          {
            op.Parameters.Add("Id");
          }
          else
          {
            var param = defNodeText.Split('\n')[0].Split(',')[0].Replace(" ", "");
            if (param == "literal") param = "LiteralNumber";

            op.Parameters.Add(param);
          }
        }

        ops.Add(op);
      }

      ops = ops.OrderBy(o => o.Index).ToList();

      StringBuilder fileContents = new StringBuilder();

      fileContents.AppendLine("#pragma once");
      fileContents.AppendLine("#include \"lookups.h\"");
      fileContents.AppendLine("");

      foreach (var op in ops)
      {
        fileContents.AppendLine(op.GenerateCode());
      }

      fileContents.AppendLine("static void* LUTOpWordTypes[] {");
      foreach (var op in ops)
      {
        fileContents.AppendLine(string.Format("&{0}WordTypes,", op.Name));
      }
      fileContents.AppendLine("};");
      fileContents.AppendLine("");

      fileContents.AppendLine("static uint32 LUTOpWordTypesCount[] {");
      foreach (var op in ops)
      {
        fileContents.AppendLine(string.Format("{0}WordTypesCount,", op.Name));
      }
      fileContents.AppendLine("};");

      File.WriteAllText("lookups_gen.h", fileContents.ToString());
    }
  }
}
