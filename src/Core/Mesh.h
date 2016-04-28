#ifndef MESH_H
#define MESH_H

#include <gl\glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <math.h>



class Mesh {

public:

	std::vector<GLfloat> vertex;
	//Todo: Need to get Triangle Data
	std::vector<GLubyte> indices;

	Mesh();
	~Mesh();


private:

};

Mesh GenerateTetrahedron(float size);
Mesh GenerateOctahedron(float size);
Mesh GenerateHexahedron(float size);
Mesh GenerateIcosahedron(float size);


#endif
