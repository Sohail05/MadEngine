#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

using namespace glm;

class Transform
{
public:
		vec3 Position;
		vec3 Rotation;
		vec3 Scale;

		//glm::vec3 myRotationAxis( ??, ??, ??);
		//glm::rotate( angle_in_degrees, myRotationAxis );


		//glm::mat4 myScalingMatrix = glm::scale(2.0f, 2.0f ,2.0f);
private:

};


#endif