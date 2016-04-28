#include "MadCore.h"

MadCore::MadCore() : scene_(){
	Init();
};
MadCore::~MadCore(){
	Terminate();
};

int MadCore::Run(){
	

	//Create Context Window, Camera and Controls
	EditorContext context = EditorContext(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	Camera camera(context);
	Control control(context);

	//Set Context to Active MainContext
	context.SetActive();

	while( !Context::MainContext->ShouldClose() ){
		camera.Viewport();
		scene_.Update();
		Context::MainContext->Update();
	}
	return 0;
}

int MadCore::Init(){

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	if(!glfwInit() ){
		Debug::Console("Failed to initate GLFW");
		return 1;
	}

	//Create Window to check glew
	GLFWwindow* window;
	window = glfwCreateWindow( 500 , 500 , "Loading ..." , NULL , NULL );
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err){
		Debug::Console(glewGetErrorString(err));
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
	Debug::Console("\nRenderer");
	Debug::Console(glGetString(GL_RENDERER));
	Debug::Console("\nOpenGL version supported ");
	Debug::Console(glGetString(GL_VERSION));
	Debug::Console("\nStatus: Using GLEW ");
	Debug::Console(glewGetString(GLEW_VERSION));
	Debug::Console("\nMadEngine Version :");
	Debug::Console(MADENGINE_VERSION);
}
