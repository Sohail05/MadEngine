#include "MadCore.h"


#include <iostream>
//#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>


#include "Entity3D.h"
#include "Component.h" // move components.h to entity or something ...
#include "Light.h" // move this to component.h

#include "Input.h"
#include "Camera.h"  //Rewrite this class

#include "Mesh.h"

MadCore::MadCore() : scene_() {


};
MadCore::~MadCore(){

};




int MadCore::run(){

	MadInit();

	//Create The context window
	EditorContext context = EditorContext(1800 , 900 , "Mad Engine");
	//Set it up as the main MainContext
	context.SetActive();

	Control control(context.window);
	Camera cam(context.window);

	while( !Context::MainContext->ShouldClose() ){

		cam.Viewport();
		scene_.Update();

		//context is set as the MainContext
		Context::MainContext->Update();

	}

	Context::MainContext->Terminate();
	MadTerminate();


	return 0;

}


int MadCore::MadInit(){

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	if(!glfwInit() ){

		printf("Failed to initate GLFW");
		return 1;
	}

	

	GLFWwindow* window;
	window = glfwCreateWindow( 500 , 500 , "Loading ..." , NULL , NULL );
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return 1;
	}

	//Todo: Implement Splash Screen ... 
	// Oh really ? don't we have anything else better to do!

	GetMadInfo();
	glfwDestroyWindow(window);

	return 0;
}


void MadCore::MadTerminate(){

	glfwTerminate();
}


void MadCore::GetMadInfo(){

	// get version info
	const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString (GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("MadEngine Version : %s", MAD_VERSION );
}