#include "Input.h"

Input* Input::MainInputHandler;

void Control::Keycallback(GLFWwindow *window, int key,int scancode,int action,int mods)
{
	std::cout << "Keycallback\n";

	if(action == GLFW_PRESS)
		switch( key ){

		case GLFW_KEY_ESCAPE:

			glfwSetWindowShouldClose(window , GL_TRUE );
			break;
	}


}

void Control::Cursorcallback(GLFWwindow* window , double xpos , double ypos){
	std::cout << xpos << " - " << ypos; 
}


void Control::MouseButtonCallback(GLFWwindow* window , int button , int action , int mods ){
	std::cout << "Button pressed: " << button;
}


void Control::ScrollCallback(GLFWwindow* window , double xoffset , double yoffset){
	std::cout << "Offset: " << xoffset << " - " << yoffset;
}

void Control::ResizeCallback(GLFWwindow* window , int width , int height ){

	std::cout << "Width: " << width << " Height: " << height;
}