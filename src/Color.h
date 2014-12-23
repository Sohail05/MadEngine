#ifndef COLOR_H
#define COLOR_H

/* Implement something like so:
ex:
Color NewColor = Color.Red;

enum Colors
{
Black	,
Blue	,
Green	,
Cyan	,
Red		,
Magenta	,
Brown	,
Yellow	,
White	,

};
*/


class Color{


public:

	//Todo: figure out a General purpose approch with multiple format support
	//Hex format 0x FF FF FF
	//RGB 255 255 255
	//RGBA 255 255 255 1
	//HSL
	//HSV

	float R;
	float G;
	float B;
	float A;

	//int from 0 to 255
	Color( int r , int g, int b , float a ){

		R=(float)r/255.0f;
		G=(float)r/255.0f;
		B=(float)r/255.0f;
		A=a;

	}


	Color( float r , float g, float b , float a ){

		R=r;
		G=g;
		B=b;
		A=a;

	}


	void SetColor( float r , float g, float b , float a ){

		R=r;
		G=g;
		B=b;
		A=a;

	}

	Color(){

		R=1.0f;
		G=1.0f;
		B=1.0f;
		A=1.0f;

	}




};

#endif