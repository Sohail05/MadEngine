#ifndef Render_H
#define Render_H

#include "Mesh.h"
#include "Shader.h"

enum RenderMode{
	kNone = 0,
	kTriangle = GL_TRIANGLES,
	kPoint = GL_POINTS,
	kLine = GL_LINES,
	kQuad = GL_QUADS
};

class Render {

public:

	Mesh mesh;
	Shader shader;
	RenderMode Mode;

	Render(){};
	~Render(){};
	//virtual Render(){} = 0;
	//virtual ~Render(){} = 0;

	virtual Draw(){} = 0;

private:

};

#endif
