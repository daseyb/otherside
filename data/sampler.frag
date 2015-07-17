#version 110
varying vec2 uv;
uniform sampler2D testTex;

void main() {
  gl_FragColor = texture2D(testTex, uv);
  gl_FragColor *= gl_FragColor;
  gl_FragColor.a = 1.0;
}