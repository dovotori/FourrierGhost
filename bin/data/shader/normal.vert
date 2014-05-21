#version 120

varying vec3 vNormal;

void main(){

    vNormal = gl_NormalMatrix * gl_Normal;
	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
}

