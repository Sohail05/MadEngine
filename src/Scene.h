#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Entity3D.h"
#include "Context.h"
class Scene{

public:

	//std::vector<Light> Lights;
	//std::vector<Mesh> Meshs;

	std::vector<Entity3D> Entities;


	//Skybox

	void Update(){

		DrawAxis();
		DrawGrid();
		

		for(std::size_t i = 0 ; i < Entities.size() ; i++ ){
			Entities.at(i).Update();

		}

		//DrawAxisCude();

	}

	void AddEntity(Entity3D E){

		Entities.push_back( E );
	}

	void DrawAxisCude(){


		//int width = 1800, height = 900;

		//glfwGetWindowSize( win , &width , &height);
		//float aspectratio = width / (float)height ;

		//glViewport( width - 200 ,  height - 200 , 200 , 200);


		Mesh Cube;
		Cube = GenerateCube();

		Transform transform;

		Component* c = (Component*)&Cube;

		c->transform = &transform;

		Cube.Draw();

		glEnd();


	}


	void DrawAxis(){

		glLineWidth( 5.0f );
		glEnable(GL_LINE_SMOOTH);

		GLfloat vertices[] = {

			0.0,  0.0,   0.0,	
			10.0,  0.0,   0.0,  
			0.0,  10.0,   0.0,  
			0.0,  0.0,   10.0,  

		};

		GLubyte colors[] =
		{

			255,255,255, 
			255,0,0,       
			0,255,0,       
			0,0,255,       

		};

		// 8 of vertex coords
		// 24 indices
		GLubyte indices[] = {0,1,
			0,2,
			0,3,
		};

		// Activate Vertex and Color Buffer
		glEnableClientState( GL_VERTEX_ARRAY);
		glEnableClientState( GL_COLOR_ARRAY );

		// Specify Color Buffer
		glColorPointer( 3, GL_UNSIGNED_BYTE, 0, colors );
		// Specify pointer to vertex array
		glVertexPointer(3, GL_FLOAT, 0, vertices);

		glDrawElements(GL_LINES, (sizeof(indices)/sizeof(*indices)) , GL_UNSIGNED_BYTE, indices);
		//std::cout << (sizeof(indices)/sizeof(*indices));

		// deactivate vertex arrays after drawing
		glDisableClientState(GL_VERTEX_ARRAY);
		glLineWidth( 1.0f );
		glDisable(GL_LINE_SMOOTH);

	}



	void DrawGrid(){

		glBegin(GL_LINES);
		glColor3f(0.7f, 0.7f, 0.7f);

		for(int i = -10 ; i <= 10 ; i++  ){

			glVertex3f(  (float)i, 0,-10.0f);
			glVertex3f(  (float)i, 0, 10.0f);

			glVertex3f(  -10.0f, 0, (float)i);
			glVertex3f(   10.0f, 0, (float)i);

			//glVertex3f(  i, -10,0);
			// glVertex3f(  i, 10, 0);

			//glVertex3f(  -10, i, 0);
			//glVertex3f(   10, i, 0);

		}
		glEnd();

	}


};
#endif