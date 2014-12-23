#ifndef LIGHT_H
#define LIGHT_H

#include "Color.h"
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/type_ptr.hpp>

//Todo: implement proper Shader before working more on the light

enum /* class only available in c++ 11*/ LightMode
{
	point = 0,
	directional = 1,

};


class Light : Component {

private:
	LightMode LightType;

public:	

	glm::vec3 Position;


	Color color;

	Light() : Position(0.0f , 2.0f , 0.0f ){

		color = Color( 255 , 255 , 255 , 1.0f );
		LightType = point;


	}

	void Update(){

		glLightfv(GL_LIGHT0, GL_DIFFUSE, glm::value_ptr(Position));

	}

	//Move Enable function class ? unless lights needs their own
	void Enable(){
	}
	void Disable(){
	}

};

#endif