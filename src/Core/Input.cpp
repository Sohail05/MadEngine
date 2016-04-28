#include "Input.h"
#include <iostream>

Input* Input::MainInputHandler;

void Control::Keycallback(GLFWwindow *window, int key,int scancode,int action,int mods)
{
	std::cout << "Keycallback "  << key << "\n";

	if(action == GLFW_PRESS)
		switch( key ){
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window , GL_TRUE );
			break;
	}

}

void Control::Cursorcallback(GLFWwindow* window , double xpos , double ypos){
	std::cout << "Mouse Pointer - x:" << xpos << " - y:" << ypos << "\n";
}

void Control::MouseButtonCallback(GLFWwindow* window , int button , int action , int mods ){
	std::cout << "Button pressed: " << button << "\n";
}

void Control::ScrollCallback(GLFWwindow* window , double xoffset , double yoffset){
	std::cout << "Mouse Roll - x:" << xoffset << " y:" << yoffset << "\n";
}

void Control::ResizeCallback(GLFWwindow* window , int width , int height ){
	std::cout << "Width: " << width << " Height: " << height << "\n";
}
