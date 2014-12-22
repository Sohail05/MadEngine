#include "MadCore.h"
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <Awesomium\BitmapSurface.h>


GLuint textureID;

int main(){

	MadInit();

	EditorContext context(1800 , 900 , "Mad Engine");
	context.SetActive();

	Scene scene;
	Control control(context.window);
	Camera cam(context.window);

	Entity3D MyObj1;
	Entity3D MyObj2;

	Mesh Cube = GenerateCube();
	Mesh tetra = GenerateTetra();

	Light light;

	Cube.color.SetColor(0,1,0,1);


	MyObj1.AddComponent( (Component*)&Cube );
	MyObj1.AddComponent( (Component*)&light );
	MyObj2.AddComponent( (Component*)&tetra );


	MyObj1.transform.Position.x = 5.0f;


	scene.AddEntity(MyObj1);
	scene.AddEntity(MyObj2);




	while( context.view->IsLoading() == true ){
		context.web_core->Update();
	}

	//glDeleteTextures(1, &textureID);
	Context::MainContext->NeedUpdate = true;

	while( !Context::MainContext->ShouldClose() ){


		if(Context::MainContext->NeedUpdate == true){

			glDeleteTextures(1, &textureID);
			context.web_core->Update();
			Surface* surfacex = context.view->surface();
			BitmapSurface* surface = static_cast<BitmapSurface*>(surfacex);

			int w = surface->width();
			int h = surface->height();

			unsigned char *buffer = new unsigned char[w * h * 4];
			surface->CopyTo(buffer, w * 4, 4, false, false);


			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			// build our texture mipmaps
			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, w, h, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

			delete[] buffer;

			Context::MainContext->NeedUpdate = false;
			std::cout << "!";
		}

		cam.Viewport();
		//glBindTexture(GL_TEXTURE_2D, textureID);

		glEnable(GL_TEXTURE_2D);

		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2d(1, 1); glVertex3f(0.0, 0.0, -10.0);
		glTexCoord2d(1, 0); glVertex3f(0.0, 10.0, -10.0);
		glTexCoord2d(0, 0); glVertex3f(10.0, 10.0, -10.0);
		glTexCoord2d(0, 1); glVertex3f(10.0, 0.0, -10.0);
		glEnd();

		glDisable(GL_TEXTURE_2D);

		scene.Update();

		Context::MainContext->Update();

	}

	Context::MainContext->Terminate();
	MadTerminate();


	return 0;
}



/*
BitmapSurface* surface = (BitmapSurface*)view->surface();
int w = surface->width();
int h = surface->height();

unsigned char *buffer = new unsigned char[w * h * 4];
surface->CopyTo(buffer, w * 4, 4, false, false);

glBindTexture(GL_TEXTURE_2D, texture);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, buffer);

delete[] buffer;

*/