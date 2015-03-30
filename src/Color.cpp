#include "Color.h"


Color::Color( int r , int g, int b , float a ){

	R=(float)r/255.0f;
	G=(float)r/255.0f;
	B=(float)r/255.0f;
	A=a;

}


Color::Color( float r , float g, float b , float a ){

	R=r;
	G=g;
	B=b;
	A=a;

}

Color::Color():R(1.0f) , G(0.0f) , B(1.0f) , A(1.0f){


}

void Color::SetColor( float r , float g, float b , float a ){

	R=r;
	G=g;
	B=b;
	A=a;

}
