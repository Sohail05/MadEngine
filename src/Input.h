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

	static Input *event_handling_instance;

	virtual void setEventHandling() /*final only available with c++ 11*/ { event_handling_instance = this; }

	static void  keycallback_dispatch(GLFWwindow *window,int key,int scancode,int action,int mods)
	{
		if(event_handling_instance)
			event_handling_instance->keycallback(window,key,scancode,action,mods);
		//std::cout << "keycallback dispatched\n";
	} 

	static void  cursorcallback_dispatch(GLFWwindow* window , double xpos , double ypos)
	{
		if(event_handling_instance)
			event_handling_instance->cursorcallback(window,xpos,ypos);
		//std::cout << "cursorcallback dispatched\n";
	}

	static void  mousebuttoncallback_dispatch(GLFWwindow* window , int button , int action , int mods )
	{
		if(event_handling_instance)
			event_handling_instance->MouseButtonCallback(window,button,action,mods);
		//std::cout << "mousebuttoncallback dispatched\n";
	} 

	static void  scrollcallback_dispatch(GLFWwindow* window , double xoffset , double yoffset)
	{
		if(event_handling_instance)
			event_handling_instance->ScrollCallback(window,xoffset,yoffset);
		//std::cout << "scrollcallback dispatched\n";
	} 


private:

};



class Control : Input
{
public:


	Control(GLFWwindow* window){
		setEventHandling();
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
