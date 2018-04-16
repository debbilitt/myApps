#version 150


// Author @patriciogv - 2015
// http://patriciogonzalezvivo.com

#ifdef GL_ES
precision mediump float;
#endif

out vec4 output_Color;

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

//uniform sampler2d;

uniform sampler2DRect tex0;
in vec2 texCoordVarying;


in vec3 colorMap;

float random (in vec2 st) {
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233)))*
        43758.5453123);
}

// Based on Morgan McGuire @morgan3d
// https://www.shadertoy.com/view/4dS3Wd
float noise (in vec2 st) {
    vec2 i = floor(st);
    vec2 f = fract(st);

    // Four corners in 2D of a tile
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));

    vec2 u = f * f * (3.0 - 2.0 * f);

    return mix(a, b, u.x) +
            (c - a)* u.y * (1.0 - u.x) +
            (d - b) * u.x * u.y;
}

#define OCTAVES 8
float fbm (in vec2 st) {
    // Initial values
    float value = 0.0;
    float amplitude = .5;
    float frequency = 0.;
    //
    // Loop of octaves
    for (int i = 0; i < OCTAVES; i++) {
        value += amplitude * noise(st);
        st *= 1.6;
        amplitude *= abs(cos(u_time));
    }
    return value;
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    st.x *= u_resolution.x/u_resolution.y;

    vec3 color = vec3(0.0);
    color += fbm(st*3.0);

    vec4 txt = texture(tex0, texCoordVarying);
/*
    //lighting
    //vec4 lcolor = vec4(0.5, 0.0, 1.0, 1.0);

    vec3 vPosition = vec3(gl_FragCoord);
    //vec3 vNormal = vec3(1.0, 1.0, 1.0);

    vec3 lightDirection = normalize(lightPos - vPosition.xyz);
    float dProd = max(0.3, dot(vNormal, lightDirection));
    vec4 colorWithLight = vec4( vec3( dProd ) * vec3( color ), 1.0 );
    //output_Color = colorWithLight;
*/
    //output_Color = txt * vec4(colorMap,1.0);

    output_Color = txt;
}
