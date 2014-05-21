#version 120

void main(){

    gl_PointSize = 2.0;
	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;

}

