#ifdef _WIN32
#include <Windows.h>
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#endif

#ifdef __linux__
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#endif

#include <GLFW/glfw3native.h>
#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include <iostream>
#include <cmath>
#include "MadCore.h"

//#define   URL "file:///C:/Users/Sohail/Desktop/Web/MadEngine/index.html"
#define   URL "file:///home/madman/Desktop/web/index.html"

using namespace Awesomium;

int main(){

	glfwInit();

	GLFWwindow* window;
	window = glfwCreateWindow( 1600 , 900, "Mad Engine" , NULL , NULL );
	glfwMakeContextCurrent(window);
        
  // get version info
  const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
  const GLubyte* version = glGetString (GL_VERSION); // version as a string
  printf ("Renderer: %s\n", renderer);
  printf ("OpenGL version supported %s\n", version);
  
  GLenum err = glewInit();
if (GLEW_OK != err)
{
  /* Problem: glewInit failed, something is seriously wrong. */
  fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
}
fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	WebConfig config;
	config.remote_debugging_port = 9999;
	WebCore* web_core = WebCore::Initialize( config );
	WebView* view = web_core->CreateWebView(300, 900, 0, kWebViewType_Window); //kWebViewType_Offscreen

//	#ifdef _WIN32
//	view->set_parent_window( glfwGetWin32Window(window) );
//	#endif

	//Load WebPage/Interface
	WebURL url(WSLit(URL));
	view->LoadURL(url);

	Scene scene;
	Control control(window);
	Camera cam(window);
	Mesh Cube;
	Cube = GenerateCube();
	
	/*
	const char* vertex_shader =
"#version 150\n"
"in vec3 vp;"
"void main () {"
"  gl_Position = vec4 (vp, 1.0);"
"}";

const char* fragment_shader =
"#version 150\n"
"out vec4 frag_colour;"
"void main () {"
"  frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
"}";

GLuint vs = glCreateShader (GL_VERTEX_SHADER);
glShaderSource (vs, 1, &vertex_shader, NULL);
glCompileShader (vs);
GLuint fs = glCreateShader (GL_FRAGMENT_SHADER);
glShaderSource (fs, 1, &fragment_shader, NULL);
glCompileShader (fs);

GLuint shader_programme = glCreateProgram ();
glAttachShader (shader_programme, fs);
glAttachShader (shader_programme, vs);
glLinkProgram (shader_programme);
	
	
	*/
	
		// Create and compile our GLSL program from the shaders
	 GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

	

	while( !glfwWindowShouldClose(window) ){

		cam.Viewport();
		scene.DrawAxis();
		scene.DrawGrid();
		glUseProgram(programID);
		Cube.Draw();
		glUseProgram(0);
		web_core->Update();
		glfwSwapBuffers(window);
		glfwSwapInterval(1);
		glfwPollEvents();

	}


	glfwDestroyWindow(window);
	glfwTerminate();
	view->Destroy();
	WebCore::Shutdown();

	return 0;
}

//Window Resize -> add to callback
//int width , height;
//glfwGetWindowSize(window , &width , &height);
//view->Resize( 300 , height);


/* bind texture
glBindTexture(GL_TEXTURE_2D, 13);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, buffer);
*/

//Callbacks





/*

//JS CALLBACKS

JSValue result = view->CreateGlobalJavascriptObject(WSLit("app"));
JSObject& app_object = result.ToObject();
delegator deler(app_object);

deler.customBind( app_object , WSLit("WebViewResize") , &WebViewResize );
deler.customBind( app_object , WSLit("ChangeColor") ,  &ChangeColor );
deler.customBind( app_object , WSLit("SetPosition") ,  &SetPosition );

view->set_js_method_handler(&deler);
//




void WebViewResize(WebView* caller, const JSArray& args){

WebViewWidth = args[0].ToInteger();

}



void ChangeColor(WebView* caller, const JSArray& args){


R=args[0].ToInteger();
G=args[1].ToInteger();
B=args[2].ToInteger();


}
glm::vec3 position;

void SetPosition(WebView* caller, const JSArray& args){


position.x= (float)args[0].ToInteger();
position.y= (float)args[1].ToInteger();
position.z= (float)args[2].ToInteger();



std::cout << "PositionSet :" << position.x;

}

*/
