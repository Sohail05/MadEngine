#ifndef MADCORE_H
#define MADCORE_H

//Clean Up all uncessesary includes

/*

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

*/


#ifdef _WIN32
#include <Windows.h>
#endif

//Todo: Figure something out for Defines
#define MAD_VERSION "0.X"



#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>

#include <iostream>
#include <cmath>

//Todo: order and remove redundant includes

#include "Transform.h"
#include "Component.h"
#include "Entity3D.h"
#include "Color.h"
#include "Shader.h"
#include "Light.h"
#include "DelegateHandler.h" //-> #include "js_delegate.h"
#include "Mesh.h"
#include "Scene.h"
#include "Input.h"
#include "Camera.h"
#include "Context.h"

void GetMadInfo();

int MadInit(){

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

	//Todo: Implement Spasl Screen 
	GetMadInfo();

	glfwDestroyWindow(window);

	return 0;
}

void MadTerminate(){

	glfwTerminate();

}


void GetMadInfo(){

	// get version info
	const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString (GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("MadEngine Version : %s", MAD_VERSION );
}


#endif