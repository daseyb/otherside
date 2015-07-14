#version 110
uniform int iterations;
varying vec3 color;

void main() {
  vec3 currColor = color;
  
  for(int i = 0; i < iterations; i++) {
	currColor += color;
  }
  
  gl_FragColor = vec4(currColor, 1.0);
}