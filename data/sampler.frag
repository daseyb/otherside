#version 110
varying vec2 uv;
uniform sampler2D testTex;

void main() {
  vec4 col = texture2D(testTex, uv);
  col.rgb = col.rbr;
  gl_FragColor = col;
  gl_FragColor.a = 1.0;
}