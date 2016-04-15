#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <GLFW\glfw3.h>

class Input{
public:

	virtual void Keycallback(GLFWwindow *window,int key,int scancode,int action,int mods) = 0;
	virtual void Cursorcallback(GLFWwindow* window , double xpos , double ypos) = 0 ;
	virtual void MouseButtonCallback(GLFWwindow* window , int button , int action , int mods ) = 0;
	virtual void ScrollCallback(GLFWwindow* window , double xoffset , double yoffset) = 0;
	virtual void ResizeCallback(GLFWwindow* window , int width , int height) = 0 ;

	static Input *MainInputHandler;

	virtual void SetMainInput() { MainInputHandler = this; }

	static void  KeycallbackDispatch(GLFWwindow *window,int key,int scancode,int action,int mods)
	{
		if(MainInputHandler)
			MainInputHandler->Keycallback(window,key,scancode,action,mods);
	}

	static void  CursorcallbackDispatch(GLFWwindow* window , double xpos , double ypos)
	{
		if(MainInputHandler)
			MainInputHandler->Cursorcallback(window,xpos,ypos);
	}

	static void  MousebuttoncallbackDispatch(GLFWwindow* window , int button , int action , int mods )
	{
		if(MainInputHandler)
			MainInputHandler->MouseButtonCallback(window,button,action,mods);

	}

	static void  ScrollcallbackDispatch(GLFWwindow* window , double xoffset , double yoffset)
	{
		if(MainInputHandler)
			MainInputHandler->ScrollCallback(window,xoffset,yoffset);

	}
	static void  ResizecallbackDispatch(GLFWwindow* window , int width , int height)
	{
		if(MainInputHandler)
			MainInputHandler->ResizeCallback(window,width,height);

	}

private:

};

class Control : Input
{
public:

	//Todo: Overload this with a Context class and have the construcstor get the view itself
	Control(GLFWwindow* window){
		SetMainInput();
		glfwSetKeyCallback(window, Input::KeycallbackDispatch);
		glfwSetCursorPosCallback( window , Input::CursorcallbackDispatch );
		glfwSetMouseButtonCallback( window ,Input::MousebuttoncallbackDispatch );
		glfwSetScrollCallback( window , Input::ScrollcallbackDispatch );
		glfwSetWindowSizeCallback( window , Input::ResizecallbackDispatch );
	}

	virtual void Keycallback(GLFWwindow *window,int key,int scancode,int action,int mods);
	virtual void Cursorcallback(GLFWwindow* window , double xpos , double ypos);
	virtual void MouseButtonCallback(GLFWwindow* window , int button , int action , int mods );
	virtual void ScrollCallback(GLFWwindow* window , double xoffset , double yoffset);
	virtual void ResizeCallback(GLFWwindow* window , int width , int height);

};

#endif
