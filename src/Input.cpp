#include "Input.h"

Input* Input::event_handling_instance;

void Control::keycallback(GLFWwindow *window, int key,int scancode,int action,int mods)
{
	std::cout << "Keycallback\n";

	if(action == GLFW_PRESS)
		switch( key ){

		case GLFW_KEY_ESCAPE:

			glfwSetWindowShouldClose(window , GL_TRUE );
			break;
	}


}

void Control::cursorcallback(GLFWwindow* window , double xpos , double ypos){
	std::cout << xpos << " - " << ypos; 
}


void Control::MouseButtonCallback(GLFWwindow* window , int button , int action , int mods ){
	std::cout << "Button pressed: " << button;
}


void Control::ScrollCallback(GLFWwindow* window , double xoffset , double yoffset){
	std::cout << "Offset: " << xoffset << " - " << yoffset;
}