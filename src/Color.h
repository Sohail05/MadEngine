#ifndef COLOR_H
#define COLOR_H

#include "common\Vector.h"

using namespace MAD;

class Color{

public:

	float red;
	float green;
	float blue;
	float alpha;

	Color();
	Color( float r , float g, float b , float a );
	vec3<float> HSL();
	vec3<float> HSV();

	//Hex format 0x FF FF FF
	//string Hex();
};

#endif
