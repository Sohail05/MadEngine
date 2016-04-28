#ifndef LIGHT_H
#define LIGHT_H


#include "../Common/Vector.h"
#include "../Common/Color.h"
#include "Component.h"
#include <glm/gtc/type_ptr.hpp>
enum LightMode
{
	kPoint_Light = 0,
	kDirectional_Light = 1,
};

class Light : Component {

public:
	LightMode lightType;
	MAD::vec3<float> position;
	Color color;

	Light(Entity* parent) : position(0.0f , 2.0f , 0.0f ) , Component(parent){
		color = Color( 255 , 255 , 255 , 1.0f );
		lightType = LightMode::kPoint_Light;
	}

	void Update(){
		glLightfv(GL_LIGHT0, GL_DIFFUSE, glm::value_ptr(position));
	}

};

#endif
