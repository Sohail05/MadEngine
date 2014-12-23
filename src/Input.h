#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <GLFW\glfw3.h>

class Input{
public:

	virtual void keycallback(GLFWwindow *window,int key,int scancode,int action,int mods) = 0;
	virtual void cursorcallback(GLFWwindow* window , double xpos , double ypos) = 0 ;
	virtual void MouseButtonCallback(GLFWwindow* window , int button , int action , int mods ) = 0;
	virtual void ScrollCallback(GLFWwindow* window , double xoffset , double yoffset) = 0;

	static Input *MainInputHandler;

	virtual void SetMainInput() { MainInputHandler = this; }

	static void  keycallback_dispatch(GLFWwindow *window,int key,int scancode,int action,int mods)
	{
		if(MainInputHandler)
			MainInputHandler->keycallback(window,key,scancode,action,mods);
	} 

	static void  cursorcallback_dispatch(GLFWwindow* window , double xpos , double ypos)
	{
		if(MainInputHandler)
			MainInputHandler->cursorcallback(window,xpos,ypos);
	}

	static void  mousebuttoncallback_dispatch(GLFWwindow* window , int button , int action , int mods )
	{
		if(MainInputHandler)
			MainInputHandler->MouseButtonCallback(window,button,action,mods);

	} 

	static void  scrollcallback_dispatch(GLFWwindow* window , double xoffset , double yoffset)
	{
		if(MainInputHandler)
			MainInputHandler->ScrollCallback(window,xoffset,yoffset);

	} 


private:

};



class Control : Input
{
public:

	//Todo: Overload this with a Context class and have the construcstor get the view itself
	Control(GLFWwindow* window){
		SetMainInput();
		glfwSetKeyCallback(window, Input::keycallback_dispatch);
		glfwSetCursorPosCallback( window , Input::cursorcallback_dispatch );
		glfwSetMouseButtonCallback( window ,Input::mousebuttoncallback_dispatch );
		glfwSetScrollCallback( window , Input::scrollcallback_dispatch );

	}



	virtual void keycallback(GLFWwindow *window,int key,int scancode,int action,int mods);
	virtual void cursorcallback(GLFWwindow* window , double xpos , double ypos);
	virtual void MouseButtonCallback(GLFWwindow* window , int button , int action , int mods );
	virtual void ScrollCallback(GLFWwindow* window , double xoffset , double yoffset);


};


#endif
