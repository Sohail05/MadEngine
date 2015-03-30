#ifndef Render_H
#define Render_H

#include <gl\glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Shader.h"
#include "Color.h"
#include "Component.h"

enum RenderMode{

	kTriangle = GL_TRIANGLES,
	kPoint = GL_POINTS,
	kLine = GL_LINES,
	kQuad = GL_QUADS
};

class Render {

public:

	std::vector<GLfloat> vertex;
	//Todo: Need to get Triangle Data
	std::vector<GLubyte> indices;

	//Todo: Make Shaders Globaly accessble by all Mesh Components to avoid multiple same shader to be compiled
	Shader shader;

	//Design TTA: Does Mesh really need a color?
	//If I leave it in each mesh will have it's own color with a shared shader
	//but all objects using the same Shader can't all sync with the same color EX: Duplicate Objects
	Color color;
	RenderMode Mode;

	Render();
	~Render();

	void Draw();


private:

};


#endif
