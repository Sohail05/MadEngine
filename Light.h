#include "Color.h"
#include <GL\GL.h>


enum LightMode
{
	point = 0,
	directional = 1,

};


class Light{

private:
	LightMode LightType;

public:	

	Tranform transform;
	Color color;

	Light(){
		
		color = Color( 255 , 255 , 255 , 1.0f );
		LightType = LightMode::point;

	}

};