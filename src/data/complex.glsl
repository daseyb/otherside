#version 110
uniform int iterations;
uniform bool loopFlag;
varying vec3 color;

int lerp(vec3 a, vec3 b, float t) {
 return a + (b - a) * t;
}

void main() {
  vec3 currColor = color;
  if(loopFlag) {
    for(int i = 0; i < iterations; i++) {
      currColor += lerp(currColor, color, (float)i/10);
    }
  }
  gl_FragColor = vec4(color, 1.0);
}