#version 330 core

uniform sampler2D ourTexture;

in vec2 TexCoord;

void main()
{
	gl_FragColor = texture(ourTexture, TexCoord);
}