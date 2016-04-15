#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include <gl\glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Shader.h"
#include "Color.h"
#include "Component.h"

enum RenderMode{

	kNone = 0,
	kTriangle = GL_TRIANGLES,
	kPoint = GL_POINTS,
	kLine = GL_LINES,
	kQuad = GL_QUADS
};

class OpenglRenderer : public Render {

public:

	//Design TTA: Does Mesh really need a color?
	//If I leave it in each mesh will have it's own color with a shared shader
	//but all objects using the same Shader can't all sync with the same color EX: Duplicate Objects
	Color color;
	RenderMode Mode;

	OpenglRenderer();
	~OpenglRenderer();

	void Draw();

private:

};


#endif
