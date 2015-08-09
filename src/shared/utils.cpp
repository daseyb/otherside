#include "utils.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

Texture MakeFlatTexture(int w, int h, Color col) {
  Color* data = new Color[w * h];
  for (int i = 0; i < w * h; i++) {
    data[i] = col;
  }
  return Texture{ w, h, data };
}

Texture MakeGradientTexture(int w, int h) {
  Color* data = new Color[w * h];
  float a = 1;
  for (int x = 0; x < w; x++) {
    float r = float(x) / (w - 1);
    for (int y = 0; y < h; y++) {
      float g = float(y) / (h - 1);
      float b = r*g;
      data[x + y * w] = { r, g, b, a };
    }
  }
  return Texture{ w, h, data };
}

BColor* ConvertToByte(uint32 w, uint32 h, Color* in) {
  BColor* data = new BColor[w *h];
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      auto p = in[x + y * w];
      data[x + y * w] = BColor { byte(p.r * 255), byte(p.g * 255), byte(p.b * 255), byte(p.a * 255) };
    }
  }
  return data;
}

Color* ConvertToFloat(uint32 w, uint32 h, BColor* in) {
  Color* data = new Color[w *h];
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      auto p = in[x + y * w];
      data[x + y * w] = { float(p.r) / 255, float(p.g) / 255, float(p.b) / 255, float(p.a) / 255 };
    }
  }
  return data;
}

Texture load_tex(const char* filename) {
  Texture result;
  int comps;
  BColor* inputData = (BColor*)stbi_load(filename, &result.width, &result.height, &comps, 4);

  if(!inputData)
  {
    result.data = nullptr;
    return result;
  }

  result.data = ConvertToFloat(result.width, result.height, inputData);
  free(inputData);
  return result;
}

void save_bmp(const char* filename, const Texture& texture) {
  BColor* outData = ConvertToByte(texture.width, texture.height, texture.data);
  stbi_write_bmp(filename, texture.width, texture.height, 4, outData);
  delete outData;
}
