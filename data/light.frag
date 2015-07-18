#version 110
varying vec2 uv;

uniform vec2 texSize;
uniform sampler2D testTex;

struct Light {
	vec4 color;
	vec2 pos;
};

uniform Light light;

void main() {
  vec4 col = texture2D(testTex, uv);
  col.rgb = col.rbr;
  
  float lightDist = distance(uv * texSize, light.pos); 
  float intensity = light.color.a/pow(lightDist, 2.0);
  
  gl_FragColor.rgb = col.rgb + light.color.rgb * intensity;
  gl_FragColor.a = 1.0;
}