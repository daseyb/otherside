#version 110
uniform int iterations;
uniform bool loopFlag;
varying vec3 color;

struct lerp_res {
  vec3 val;
};

lerp_res mlerp(vec3 a, vec3 b, float t) {
 lerp_res Result = lerp_res(a + (b - a) * t);
 return Result;
}

void main() {
  lerp_res res;
  vec3 currColor = color;
  if(loopFlag) {
    for(int i = 0; i < iterations; i++) {
      res = mlerp(currColor, color, float(i)/2.0); 
      currColor += res.val;
    }
  }
  gl_FragColor = vec4(color, 1.0);
}