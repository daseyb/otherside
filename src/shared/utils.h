#pragma once
#include "types.h"

template<typename T>
struct TColor {
  T r;
  T g;
  T b;
  T a;
};

typedef TColor<float> Color;
typedef TColor<byte> BColor;

struct Texture {
  int width;
  int height;
  Color* data;
};

struct Vec2 {
  float x;
  float y;
};

struct Light {
  Color color;
  Vec2 pos;
};

Texture MakeFlatTexture(int w, int h, Color col);
Texture MakeGradientTexture(int w, int h);
Texture load_tex(const char* filename);
void save_bmp(const char* filename, const Texture& texture);