#version 150
uniform vec4 globalColor;
out vec4 outputColor;

// this is how we receive the texture
uniform sampler2DRect tex0;

in vec2 texCoordVarying;

void main()
{
    outputColor = texture(tex0, texCoordVarying);
}
