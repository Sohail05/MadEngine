#include "Mesh.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


Mesh::Mesh(){}

Mesh::~Mesh(){}

Mesh GenerateTetrahedron(float size){

	Mesh M;

	GLfloat a = size / 2.0f;

	GLfloat vertices[] = {

		a, a, a, //0
		a,-a,-a, //1
		-a, a,-a, //2
		-a,-a, a  //3
	};

	GLubyte indices[] = {

		0,  2,  1,
		2,  3,  1,
		0,  1,  3,
		0,  3,  2
	};

	std::vector<GLfloat> v( vertices , vertices + sizeof(vertices) / sizeof(vertices[0]) );
	M.vertex = v;

	std::vector<GLubyte> i( indices , indices + sizeof(indices) / sizeof(indices[0]) );
	M.indices = i;

	return M;
}

Mesh GenerateOctahedron(float size){

	Mesh M;

	GLfloat a = size / ( 2.0f * sqrtf(2.0f) ) ;
	GLfloat b = size / 2.0f;

	GLfloat vertices[] = {

		a, 0, a, //0
		a, 0,-a, //1
		-a, 0, a, //2
		-a, 0,-a, //3
		0, b, 0, //4
		0,-b, 0 //5
	};

	GLubyte indices[] = {

		2, 3, 4,
		3, 2, 4,
		1, 0, 4,
		0, 2, 4,
		1, 3, 5,
		3, 2, 5,
		0, 1, 5,
		2, 0, 5
	};

	std::vector<GLfloat> v( vertices , vertices + sizeof(vertices) / sizeof(vertices[0]) );
	M.vertex = v;

	std::vector<GLubyte> i( indices , indices + sizeof(indices) / sizeof(indices[0]) );
	M.indices = i;

	return M;
}


Mesh GenerateHexahedron(float size){

	Mesh M;
	GLfloat a = size / 2.0f ;

	GLfloat vertices[] = {

		a, a, a, //0
		a, a,-a, //1
		a,-a, a, //2
		a,-a,-a, //3
		-a, a, a, //4
		-a, a,-a, //5
		-a,-a, a, //6
		-a,-a,-a //7
	};

	GLubyte indices[] = {

		7, 3, 2, 6,
		7, 6, 4, 5,
		6, 2, 0, 4,
		5, 4, 0, 1,
		3, 1, 0, 2,
		7, 5, 1, 3

	};

	std::vector<GLfloat> v( vertices , vertices + sizeof(vertices) / sizeof(vertices[0]) );
	M.vertex = v;

	std::vector<GLubyte> i( indices , indices + sizeof(indices) / sizeof(indices[0]) );
	M.indices = i;

	return M;
}

Mesh GenerateIcosahedron(float size){

	Mesh M;
	GLfloat a = size / 2.0f ;
	GLfloat b = size / (2.0f * ( (1.0f + sqrtf(5.0f)) / 2.0f) ) ;

	GLfloat vertices[] = {

		0, b, a, //0
		0, b,-a, //1
		0,-b, a, //2
		0,-b,-a, //3
		b, a, 0, //4
		b,-a, 0, //5
		-b, a, 0, //6
		-b,-a, 0, //7
		a, 0, b, //8
		a, 0,-b, //9
		-a, 0, b, //10
		-a, 0,-b  //11


	};

	GLubyte indices[] = {

		1, 4,  6,
		0, 6,  4,
		0, 2,  10,
		0, 8,  2,
		1, 3,  9,
		1, 11, 3,
		2, 5,  7,
		3, 7,  5,
		6, 10, 11,
		7, 11, 10,
		4, 9,  8,
		5, 8,  9,
		0, 10, 6,
		0, 4,  8,
		1, 6,  11,
		1, 9,  4,
		3, 11, 7,
		3, 5,  9,
		2, 7,  10,
		2, 8,  5,

	};

	std::vector<GLfloat> v( vertices , vertices + sizeof(vertices) / sizeof(vertices[0]) );
	M.vertex = v;

	std::vector<GLubyte> i( indices , indices + sizeof(indices) / sizeof(indices[0]) );
	M.indices = i;

	return M;
}

