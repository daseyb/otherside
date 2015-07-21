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
  
  float lightDist = distance(uv, light.pos); 
  float intensity = clamp(1.0 - (lightDist / light.color.a), 0.0, 1.0);
  
  gl_FragColor.rgb = col.rgb + pow(light.color.rgb * intensity, vec3(2.0, 2.0, 2.0));
  gl_FragColor.a = 1.0;
}