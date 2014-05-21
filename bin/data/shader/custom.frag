#version 120

varying vec3 vPosition;
varying vec3 vNormal;


void main()
{

	vec3 posLum = vec3(4.0, 10.5, 20.8);
	vec3 dirEye = vec3(0.0, 0.0, 1.0);
	float brillance = 10.0; // plus il diminue plus la surface s'étale

	// COULEURS
	vec3 ambiant = vec3(0.0);
	vec3 diffuse = vec3(0.5);
	vec3 specular = vec3(1.0);
	vec3 fog = vec3(0.0);
	vec3 color = ambiant;

	// DIFFUSE
    vec3 lumDir = normalize(posLum - vPosition);
    float angle = max(dot(lumDir, normalize(vNormal)), 0.0);
    color += (diffuse * angle);

	// SPECULAR
	vec3 reflection = reflect(-lumDir, normalize(vNormal));
  	float spec = pow(max(dot(reflection, dirEye), 0.0), brillance);
  	color += (specular * spec);

  	// FOG
  	const float LOG2 = 1.442695;
    float density = 0.1;	// plus on augmente plus le brouillard est dense
    float z = gl_FragCoord.z / gl_FragCoord.w;
    float fogFactor = exp2( -density * density * z * z * LOG2 );
    fogFactor = clamp(fogFactor, 0.0, 1.0);

    //gl_FragColor = mix(vec4(fog, 1.0), vec4(color, 1.0), fogFactor );
	gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	//gl_FragColor = vec4(normalize(vNormal), 1.0);

}


