#ifndef CONTEXT_H
#define CONTEXT_H

#include <Awesomium/WebCore.h>
//Todo: Remove BitmaSurface Implementation
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>

//Todo: Create one definition location for GLFW stuff
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
#include "Surface.h"
#include "Shader.h"

//Run .Bat file (Python server)
//For path simplicity
//Todo: set the relative path of the binary
//#define   URL "http://127.0.0.1:8000/web/index.html"
#define URL "file:///C:/Repositories/madengine/MadEngine/web/MadEngine.html"
using namespace Awesomium;

class Context{


public:

	GLFWwindow* window;
	WebCore* web_core;
	WebView* view;

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
	MadSurface* surface;
	Shader SurfaceShader;

	EditorContext();
	EditorContext(int width , int height, char* title);

	virtual void Update();
	virtual void Terminate();
	virtual void SetActive();
	virtual int ShouldClose();


private:


};






#endif
