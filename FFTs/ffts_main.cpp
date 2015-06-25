#include <iostream>
#include <math.h>
#include <conio.h>
#include <chrono>
#include <thread>

#define M_PI 3.141592653f

void printBuffer(float* buffer, int length, int height, int width) {
  char* lines = new char[height*(width + 1)];
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int index = (int)((float)x / width * length);
      
      float bufferVal = buffer[index];
      int quantizedVal = (int)(bufferVal * height/2);

      if ( abs(y - height/2) <= abs(quantizedVal) && quantizedVal * (y - height / 2) > 0) {
        lines[y*width + x] = '#';
      } else if (x == 0) {
        lines[y*width + x] = '|';
      } else if (y == height / 2) {
        lines[y*width + x] = '-';
      }
      else {
        lines[y*width + x] = ' ';
      }
    }
    lines[y*width + width - 1] = '\n';
  }

  lines[height*width] = 0;
  std::cout << lines;

}

int main(int argc, char** argv) {
  using namespace std::literals;

  const int SAMPLES = 64*4;
  const float RATE = 2.0f * M_PI / SAMPLES;
  float buffer[SAMPLES];

  float offset = 0;

  while (true) {
    for (int i = 0; i < SAMPLES; i++) {
      float t = i * RATE + offset;
      buffer[i] = sinf(t) * cosf(t *3 + 2) + cos(t/3) * 0.5f;
    }

    printBuffer(buffer, SAMPLES, 24, 79);
    std::this_thread::sleep_for(33ms);
    system("cls");
    offset += 2.0f * M_PI/30 * 0.5f;
  }
  

}