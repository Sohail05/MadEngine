#ifndef CONTEXT_H
#define CONTEXT_H

#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>

#include <gl\glew.h>
#include <GLFW/glfw3.h>
#include "Surface.h"
#include "Shader.h"

//Run .Bat file (Python server)
//For path simplicity
//Todo: set the relative path of the binary & remove macro
#define URL "file:///" //Path the Interface files
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
	Shader surface_shader;

	EditorContext(int width , int height, char* title);
	~EditorContext();

	virtual void Update();
	virtual void Terminate();
	virtual void SetActive();
	virtual int ShouldClose();

	int width() const { return width_; }
	int height() const { return height_; }
	char* title() const { return title_; }

private:

	int width_, height_;
	char* title_;

};


#endif
