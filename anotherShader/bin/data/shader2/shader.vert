#version 150

// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;
in vec4 position;
in vec2 texcoord;

// the time value is passed into the shader by the OF app.
uniform float u_time;
//uniform float u_mouse;

//get the texture

out vec2 texCoordVarying;



void main()
{
    
   texCoordVarying = vec2(texcoord.x);
    
    // the sine wave travels along the x-axis (across the screen),
    // so we use the x coordinate of each vertex for the calculation,
    // but we displace all the vertex along the y axis (up the screen)/
    
    float displacementHeight = 100.0;
    float displacementY = sin(u_time + (position.x / 100.0)) * displacementHeight;
	
    vec4 modifiedPosition = modelViewProjectionMatrix * position;
	modifiedPosition.y += displacementY;
    
	gl_Position = modifiedPosition;
}
