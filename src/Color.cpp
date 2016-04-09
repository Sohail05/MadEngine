#include "Color.h"


//Todo: figure out a General purpose approch with multiple format support
//Hex format 0x FF FF FF
//RGB 255 255 255
//RGBA 255 255 255 1
//HSL
//HSV

Color::Color( float r , float g, float b , float a ) : _red(r), _green(g), _blue(b), _alpha(a)  {}
Color::Color() : _red(1.0f), _green(0.0f), _blue(1.0f), _alpha(1.0f){}
