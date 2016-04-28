#ifndef CONTEXT_H
#define CONTEXT_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>

class Context{

public:

	GLFWwindow* window;
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
