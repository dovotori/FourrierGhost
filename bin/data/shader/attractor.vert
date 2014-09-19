#version 120

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float pointWeight;

void main(){

    gl_PointSize = pointWeight;
	gl_Position = projection * view * model * gl_Vertex;

}

