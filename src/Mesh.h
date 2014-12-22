#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Shader.h"
#include "Color.h"

class Mesh : Component{

public:


	std::vector<GLfloat> Vertex;
	std::vector<GLubyte> Indices;
	Shader shader;
	
	Color color;
	int Mode;

	Mesh(){

		Enable();
		shader = Shader();

	}

	void Update(){
	

		if(Active){
		Draw();
		}
	
	}

	void Enable(){

		Active = true;
	
	}
	void Disable(){
	

		Active = false;
	}


	void Draw(){

		// Activate Vertex Buffer
		glEnableClientState( GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, Vertex.data() );

		//Use Shader
		glUseProgram(shader.shaderProgram);

		GLuint PositionID = glGetUniformLocation(shader.shaderProgram, "Position");
		//glUniform1f(MatrixID, col);
		glUniform3fv(PositionID, 1, glm::value_ptr(transform->Position) );
		

		GLuint ColorID = glGetUniformLocation(shader.shaderProgram, "color");
		glUniform4f(ColorID, color.R , color.G , color.B , color.A );

		//Draw Mesh with Indices
		glDrawElements(Mode, Indices.size() , GL_UNSIGNED_BYTE, Indices.data() );

		//Disable Shader
		glUseProgram(0);

		//Disable Buffer
		glDisableClientState(GL_VERTEX_ARRAY);

	}


};



Mesh GenerateCube(){


	Mesh M;
	M.Mode = GL_QUADS;

	M.Vertex.push_back(-1.0);	  M.Vertex.push_back(-1.0);		M.Vertex.push_back(-1.0);
	M.Vertex.push_back( 1.0);	  M.Vertex.push_back(-1.0);		M.Vertex.push_back(-1.0);
	M.Vertex.push_back(-1.0);	  M.Vertex.push_back( 1.0);		M.Vertex.push_back(-1.0);
	M.Vertex.push_back( 1.0);	  M.Vertex.push_back( 1.0);		M.Vertex.push_back(-1.0);


	M.Vertex.push_back(-1.0);	  M.Vertex.push_back(-1.0);		M.Vertex.push_back( 1.0);
	M.Vertex.push_back( 1.0);	  M.Vertex.push_back(-1.0);		M.Vertex.push_back( 1.0);
	M.Vertex.push_back(-1.0);	  M.Vertex.push_back( 1.0);		M.Vertex.push_back( 1.0);
	M.Vertex.push_back( 1.0);	  M.Vertex.push_back( 1.0);		M.Vertex.push_back( 1.0);


	M.Indices.push_back( 0);	  M.Indices.push_back( 1 );		M.Indices.push_back( 3 );  M.Indices.push_back( 2 );
	M.Indices.push_back( 4);	  M.Indices.push_back( 5 );		M.Indices.push_back( 7 );  M.Indices.push_back( 6 );
	M.Indices.push_back( 0);	  M.Indices.push_back( 1 );		M.Indices.push_back( 5 );  M.Indices.push_back( 4 );
	M.Indices.push_back( 2);	  M.Indices.push_back( 3 );		M.Indices.push_back( 7 );  M.Indices.push_back( 6 );
	M.Indices.push_back( 1);	  M.Indices.push_back( 3 );		M.Indices.push_back( 7 );  M.Indices.push_back( 5 );
	M.Indices.push_back( 0);	  M.Indices.push_back( 2 );		M.Indices.push_back( 6 );  M.Indices.push_back( 4 );

	return M;
}


Mesh GenerateTetra(){


	Mesh M;

	M.Mode = GL_LINES;

	GLfloat vertices[] = {

		1,1,1,
		1,-1,-1,
		-1,1,-1,
		-1,-1,1
	};

	std::vector<GLfloat> v( vertices , vertices + sizeof(vertices) / sizeof(vertices[0]) );
	M.Vertex = v;

	//(1,1,1), (1,−1,−1), (−1,1,−1), (−1,−1,1)


	// 8 of vertex coords
	// 24 indices
	GLubyte indices[] = {

		0,1,
		0,2,
		0,3,
		1,2,
		1,3,
		2,3
	};



	std::vector<GLubyte> i( indices , indices + sizeof(indices) / sizeof(indices[0]) );
	M.Indices = i;


	return M;
}

#endif
