
#version 150

uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;


uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

out vec2 texCoordVarying;

//trying to pass this to frag
out vec3 colorMap;

float normSine(float f){
    f = (sin(f) * 0.5) + 0.5;
    return f;
}

float normCos(float f){
    f = (cos(f) * 0.5) + 0.5;
    return f;
}

//begin random stuff

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

//end random stuff

void main(){
	
    vec4 modifiedPosition = modelViewProjectionMatrix * position;
	
    // we need to scale up the values we get from the texture
    float scale = 100.0;
    
    // here we get the red channel value from the texture
    // to use it as vertical displacement

    vec2 st = position.xy/u_resolution.xy;
    st.x *= u_resolution.x/u_resolution.y;

    vec3 color = vec3(0.0);
    color += fbm(st*normSine(u_time) * 1.0);

    colorMap = color;
    float displacementY = normSine(color.r * texcoord.y);

    float displacementX = normSine(color.r * texcoord.x);

    float displacementZ = normSine(color.r * texcoord.y);

    // use the displacement we created from the texture data
    // to modify the vertex position
//    modifiedPosition.y += displacementY * scale;
//    modifiedPosition.x += displacementX * scale;
    modifiedPosition.z += displacementZ * scale;
    //modifiedPosition.yz *= (texcoord / u_resolution) * sin(u_time);
    // this is the resulting vertex position
    gl_Position = modifiedPosition;

    // pass the texture coordinates to the fragment shader
    texCoordVarying = texcoord;

}
