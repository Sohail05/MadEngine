#include "Context.h"

Context* Context::MainContext;

EditorContext::EditorContext(int width , int height, char* title) : width_(width) , height_(height) , title_(title){
  window = glfwCreateWindow( width_ , height_ , title_ , NULL , NULL );
}

EditorContext::~EditorContext(){}

void EditorContext::Update(){

	glfwSwapBuffers(window);
	glfwSwapInterval(1);
	glfwPollEvents(); //Move to inputs

}

void EditorContext::Terminate(){
	glfwDestroyWindow(window);
}

void EditorContext::SetActive(){
	MainContext = this;
	glfwMakeContextCurrent(window);
}

int EditorContext::ShouldClose(){
	return glfwWindowShouldClose(window);
}
