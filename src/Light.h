#ifndef LIGHT_H
#define LIGHT_H

#include "Color.h"
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/type_ptr.hpp>

//Todo: implement proper Shader before working more on the light

enum /* class only available in c++ 11*/ LightMode
{
	POINT = 0,
	DIRECTIONAL = 1,

};


class Light : Component {

private:
	LightMode lightType;

public:	

	glm::vec3 position;


	Color color;

	Light() : position(0.0f , 2.0f , 0.0f ){

		color = Color( 255 , 255 , 255 , 1.0f );
	lightType = point;


	}

	void Update(){

		glLightfv(GL_LIGHT0, GL_DIFFUSE, glm::value_ptr(position));

	}

	//Move Enable function class ? unless lights needs their own
	void Enable(){
	}
	void Disable(){
	}

};

#endif