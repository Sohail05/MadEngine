#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Context.h"
#include "Entity.h"

class Scene{

public:

	std::vector<Entity> Entities;
	bool axis; 		//Enable Axis Rendering
	bool grid;		//Enable Grid Rendering

	Scene(){
		CreateEntity();
		axis = true;
		grid = true;
	}


	void Update(){

		if(axis){DrawAxis();}
		if(grid){DrawGrid();}

		for(std::size_t i = 0 ; i < Entities.size() ; i++ ){
			Entities[i].Update();
		}
	}


	Entity* CreateEntity(){
		Entity E= Entity();
		Entities.push_back( E );
		return &Entities.back();
	}

	void AddEntity(Entity E){
		Entities.push_back( E );
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

		glEnableClientState( GL_VERTEX_ARRAY);
		glEnableClientState( GL_COLOR_ARRAY );

		glColorPointer( 3, GL_UNSIGNED_BYTE, 0, colors );
		glVertexPointer(3, GL_FLOAT, 0, vertices);

		glDrawElements(GL_LINES, (sizeof(indices)/sizeof(*indices)) , GL_UNSIGNED_BYTE, indices);

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

		}
		glEnd();
	}

};
#endif
