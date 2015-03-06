#ifndef COLOR_H
#define COLOR_H


// it's fine for now but This needs a lot of work!

/* Implement something like so:
ex: Color NewColor = Color.Red;

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


	//Todo: change variable to lowercase
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

	//Default Contructor: everything at 1.0f
	Color();

	//int from 0 to 255
	Color( int r , int g, int b , float a );

	Color( float r , float g, float b , float a );

	void SetColor( float r , float g, float b , float a );




};

#endif