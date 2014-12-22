#ifndef CONTEXT_H
#define CONTEXT_H

#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include <iostream>
#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#endif

#ifdef __linux__
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#endif

#include <gl\glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>


//Run .Bat file or Python server 
//#define   URL "http://127.0.0.1:8000/web/index.html"

#define   URL "file:///C:/Users/Sohail/Desktop/Web/index.html"


using namespace Awesomium;

class Context{


public:

	GLFWwindow* window;
	WebCore* web_core;
	WebView* view;
	bool NeedUpdate;
	static Context *MainContext;

	virtual void Update() = 0;
	virtual void Terminate() = 0;
	virtual void SetActive() = 0;
	virtual int ShouldClose() = 0;

private:


};


class EditorContext : Context {

public:

	GLFWwindow* window;
	WebCore* web_core;
	WebView* view;

	EditorContext();
	EditorContext(int width , int height, char* title);

	virtual void Update();
	virtual void Terminate();
	virtual void SetActive();
	virtual int ShouldClose();


private:


};






#endif
