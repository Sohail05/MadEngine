#include "MadCore.h"

MadCore::MadCore() : scene_(), debugger() {};
MadCore::~MadCore(){};

int MadCore::Run(){

	Init();
	//Create The context window
	EditorContext context = EditorContext(1800 , 900 , "Mad Engine");
	//Set it up as the main MainContext
	context.SetActive();

	Control control(context.window);
	Camera cam(context.window);

	while( !Context::MainContext->ShouldClose() ){

		cam.Viewport();
		scene_.Update();
		Context::MainContext->Update();

	}

	Terminate();

	return 0;

}

int MadCore::Init(){

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	if(!glfwInit() ){
		debugger.Console("Failed to initate GLFW");
		return 1;
	}

	GLFWwindow* window;
	window = glfwCreateWindow( 500 , 500 , "Loading ..." , NULL , NULL );
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		debugger.Console(glewGetErrorString(err));
		return 1;
	}

	GetInfo();
	glfwDestroyWindow(window);

	return 0;
}


void MadCore::Terminate(){

	Context::MainContext->Terminate();
	glfwTerminate();

}


void MadCore::GetInfo(){

	debugger.Console("\nRenderer");
	debugger.Console(glGetString(GL_RENDERER));
	debugger.Console("\nOpenGL version supported ");
	debugger.Console(glGetString(GL_VERSION));
	debugger.Console("\nStatus: Using GLEW ");
	debugger.Console(glewGetString(GLEW_VERSION));
	debugger.Console("\nMadEngine Version :");
	debugger.Console(MADENGINE_VERSION);

}
