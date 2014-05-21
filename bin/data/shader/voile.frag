#version 120

uniform float cpt;
uniform float opacity;

float random(vec3 scale,float seed){
	return fract(sin(dot(gl_FragCoord.xyz+seed,scale)) * 43758.5453 + seed);
}

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

float map(float valeur, float minRef, float maxRef, float minDest, float maxDest)
{
	return minDest + (valeur - minRef) * (maxDest - minDest) / (maxRef - minRef);
}


void main()
{
	//float n = cpt * ( .5 - random( vec3( 1. ), length( gl_FragCoord ) ) );
	float n = rand(cpt * gl_FragCoord.xy);
	float n2 = rand(cpt/1000 * gl_FragCoord.xy);

    gl_FragColor = vec4(vec3(n2), opacity*n);
}
