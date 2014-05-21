#version 120

varying vec3 vPosition;
varying vec3 vNormal;


void main()
{
	vec3 posLum = vec3(4.0, 10.5, 20.8);
	vec3 dirEye = vec3(0.0, 0.0, 1.0);
	float brillance = 60;

	// COULEURS
	vec3 ambiant = vec3(1.0, 0.0, 0.0);
	vec3 diffuse = vec3(0.0, 1.0, 0.0);
	vec3 specular = vec3(1.0, 1.0, 1.0);
	vec3 color = ambiant;
	
	// DIFFUSE
    vec3 lumDir = normalize(posLum - vPosition);
    float angle = max(dot(lumDir, normalize(vNormal)), 0.0);
    color += (diffuse * angle);

	// SPECULAR
	vec3 reflection = reflect(-lumDir, normalize(vNormal));
  	float spec = pow(max(dot(reflection, dirEye), 0.0), brillance);
  	color += (specular * spec);

	gl_FragColor = vec4(color, 1.0);
}
