#version 120

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float cpt;

varying vec3 vPosition;
varying vec3 vNormal;



float random(vec3 scale,float seed){
    return fract(sin(dot(gl_Vertex.xyz+seed,scale)) * 43758.5453 + seed);
}

float map(float valeur, float minRef, float maxRef, float minDest, float maxDest)
{
    return minDest + (valeur - minRef) * (maxDest - minDest) / (maxRef - minRef);
}


void main(){

    vPosition = gl_Vertex.xyz;
    vNormal = gl_NormalMatrix * gl_Normal;

    //vec4 nP = vec4(gl_Vertex.xyz + (gl_Normal * cos(cpt) * sin(gl_Vertex.y)), 1.0);
	//float popote = 0.2 - cos(cpt * gl_Vertex.x * 0.02) * 0.2;
  	//vec4 nP = vec4(gl_Vertex.xyz - (gl_Normal * popote), 1.0);

	//gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
	gl_Position = projection * view * model * gl_Vertex;
}

