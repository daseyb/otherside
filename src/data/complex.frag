#version 110
uniform int iterations;
uniform bool loopFlag;
varying vec3 color;

struct lerp_res {
  vec3 val1;
  vec3 val2;
};

lerp_res mlerp(vec3 a, vec3 b, float t) {
 lerp_res Result = lerp_res(vec3(0, 0, 0), a + (b - a) * t);
 return Result;
}

void main() {
  lerp_res res;
  vec3 currColor = color;
  
  if(loopFlag) {
    for(int i = 0; i < iterations; i++) {
      res = mlerp(currColor, color, float(i)/float(iterations)); 
      currColor += res.val2;
    }
  } else {
	  if(iterations > 0) {
		currColor = vec3(0, 0, 0);
	  } else {
		currColor = vec3(1, 0, 1);
	  }
  }
  
  gl_FragColor = vec4(currColor, 1.0);
}