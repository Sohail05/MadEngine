#ifndef Render_H
#define Render_H

#include "../Core/Mesh.h"
#include "shader.h"
#include "../Common/Color.h"

enum RenderMode{
	kNone = 0,
	kTriangle = GL_TRIANGLES,
	kPoint = GL_POINTS,
	kLine = GL_LINES,
	kQuad = GL_QUADS
};

class Renderer {

public:

	Color color;
	Mesh mesh;
	Shader shader;
	RenderMode Mode;

	Renderer();
	~Renderer();

	void Draw();

private:

};

#endif
