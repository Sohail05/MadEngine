#ifndef MATERIAL_H
#define MATERIAL_H

#include "Shader.h"
#include "Color.h"

class Material {

public:

	//Todo: Make Shaders Globaly accessble by all Mesh Components to avoid multiple same shader to be compiled
	Shader shader;

	//Design TTA: Does Mesh really need a color?
	//If I leave it in each mesh will have it's own color with a shared shader
	//but all objects using the same Shader can't all sync with the same color EX: Duplicate Objects
	Color color;
	//RenderMode Mode;

private:


};


#endif
