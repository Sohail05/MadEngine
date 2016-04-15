#include "Color.h"
#include <algorithm>


Color::Color( float r , float g, float b , float a ) : red(r), green(g), blue(b), alpha(a)  {}
Color::Color() : red(1.0f), green(0.0f), blue(1.0f), alpha(1.0f){}

vec3<float> Color::HSL(){

	using namespace std;

	float _r = red / 255.0f;
	float _g = green / 255.0f;
	float _b = blue / 255.0f;
	float const Cmax = max(max(_r, _g), _b);
	float Cmin = min(min(_r, _g), _b);
	float delta = Cmax - Cmin;

	//Hue calculation

	float H = 0.0f;
	if (delta != 0.0f) {
	
		if(Cmax == _r) {
			H = 60.0f * (float)( (int)( (_g - _b) / delta) % 6);
		}else if(Cmax == _g){
			H = 60.0f * (((_b - _r) / delta) + 2.0f );
		}else if(Cmax == _b){
			H = 60.0f * (((_r - _g) / delta) + 4.0f);
		}
	
	}

	//Lightness calculation 
	float L = (Cmax + Cmin) / 2.0f;
	
	float S = 0.0f;
	//Saturation calculation
	if( delta != 0.0f){
		S = delta / (1.0f - abs(2.0f*L - 1.0f));
	}

	return vec3<float>(H, S, L );

};

vec3<float> Color::HSV() {

	using namespace std;

	float _r = red / 255.0f;
	float _g = green / 255.0f;
	float _b = blue / 255.0f;
	float const Cmax = max(max(_r, _g), _b);
	float Cmin = min(min(_r, _g), _b);
	float delta = Cmax - Cmin;

	//Hue Calculation
	float H = 0.0f;
	if (delta != 0.0f) {

		if (Cmax == _r) {
			H = 60.0f * (float)((int)((_g - _b) / delta) % 6);
		}
		else if (Cmax == _g) {
			H = 60.0f * (((_b - _r) / delta) + 2.0f);
		}
		else if (Cmax == _b) {
			H = 60.0f * (((_r - _g) / delta) + 4.0f);
		}

	}

	float S = 0.0f;
	//Value calculation
	if (delta != 0.0f) {
		S = delta / Cmax;
	}

	return vec3<float>(H, S, Cmax);

};