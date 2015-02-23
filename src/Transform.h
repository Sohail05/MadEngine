#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

using namespace glm;

class Transform
{
public:
	vec3 position;
	vec3 rotation;
	vec3 scale;
	mat4 matrix;

	//Todo : Implement Transform functions  
	//glm::rotate( Degree, Rotation );

	Transform(): position(1), rotation(1), scale(1) {

		UpdateMatrix();
	}


	void UpdateMatrix(){


		//Matrix = mat4(Scale,Rotation,Position); 

	}




private:

};


#endif