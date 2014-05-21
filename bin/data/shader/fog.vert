#version 120

uniform float cpt;

varying vec3 vPosition;
varying vec3 vNormal;




void main(){

    vPosition = gl_Vertex.xyz;
    vNormal = gl_NormalMatrix * gl_Normal;

	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
}

