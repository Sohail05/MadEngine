#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Common\Vector.h"
#include "Common\Matrix.h"

using namespace MAD;

class Transform
{
	public:

		vec3<float> position;
		vec3<float> rotation;
		vec3<float> scale;
		mat4x4<float> matrix;

		//Todo : Implement Transform functions
		//glm::rotate( Degree, Rotation );

		Transform() : position(1.0f), rotation(1.0f), scale(1.0f) {
			UpdateMatrix();
		}

		void translate(){};
		void rotate(){};

		void UpdateMatrix(){
			//Matrix = mat4(Scale,Rotation,Position);
		}

		vec3<float> GetPosition() const{
			return position;
		}

	private:

};

#endif
