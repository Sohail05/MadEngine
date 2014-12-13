#include "Color.h"

	  #ifdef __APPLE__
	  #include <OpenGL/gl.h>
	  #else
	  #include <GL/gl.h>
	  #endif


enum /* class only available in c++ 11*/ LightMode
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
		LightType = point;

	}

};
