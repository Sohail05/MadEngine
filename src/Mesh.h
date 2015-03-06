#ifndef MESH_H
#define MESH_H

#include <gl\glew.h>
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Shader.h"
#include "Color.h"
#include <math.h>

enum RenderMode{

	kTriangle = GL_TRIANGLES,
	kPoint = GL_POINTS,
	kLine = GL_LINES,
	kQuad = GL_QUADS
};

class Mesh : public Component{

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

	Mesh();
	~Mesh();

	void Update();
	void Draw();
	void Enable();
	void Disable();

private:


};

Mesh GenerateTetrahedron(float size);
Mesh GenerateOctahedron(float size);
Mesh GenerateHexahedron(float size);
Mesh GenerateIcosahedron(float size);


#endif
