#include <glm/glm.hpp>
#include <vector>
#include "shader.hpp"

class Mesh{

	public:
	
	std::vector<GLubyte> colors;
	std::vector<GLfloat> Vertex;
	std::vector<GLubyte> Indices;

	int Mode;

	Mesh(){
		

	
	
	}



	void Draw(){
		
	// Activate Vertex and Color Buffer
    glEnableClientState( GL_VERTEX_ARRAY);
    //glEnableClientState( GL_COLOR_ARRAY );

    // Specify Color Buffer
	//glColorPointer( 3, GL_UNSIGNED_BYTE, 0, colors.data()  );
    // Specify pointer to vertex array
    
	glVertexPointer(3, GL_FLOAT, 0, Vertex.data() );

    // draw a cube
	glDrawElements(Mode, Indices.size() , GL_UNSIGNED_BYTE, Indices.data() );
    //std::cout << (sizeof(indices)/sizeof(*indices));

    // deactivate vertex arrays after drawing
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


		M.colors.push_back( 255);	  M.colors.push_back( 0 );		M.colors.push_back( 255 );
		M.colors.push_back( 255);	  M.colors.push_back( 0 );		M.colors.push_back( 255 );
		M.colors.push_back( 255);	  M.colors.push_back( 0 );		M.colors.push_back( 255 );
		M.colors.push_back( 255);	  M.colors.push_back( 0 );		M.colors.push_back( 255 );


		M.colors.push_back( 255);	  M.colors.push_back( 0 );		M.colors.push_back( 255 );
		M.colors.push_back( 255);	  M.colors.push_back( 0 );		M.colors.push_back( 255 );
		M.colors.push_back( 255);	  M.colors.push_back( 0 );		M.colors.push_back( 255 );
		M.colors.push_back( 255);	  M.colors.push_back( 0 );		M.colors.push_back( 255 );
	


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



    GLubyte colors[] =
    {

      255,0,255,       //0 Bottom left
      255,0,255,       //1 Bottom right
      255,0,255,       //2 Top Left
      255,0,255,       //3 Top Right
		
    };

		std::vector<GLubyte> c( colors , colors + sizeof(colors) / sizeof(colors[0]) );
		M.colors = c;


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
		M.Indices = c;


		return M;
}
