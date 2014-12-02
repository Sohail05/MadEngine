#ifdef _WIN32 
#include <Windows.h>
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#include <GLFW/glfw3native.h>
#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include <iostream>
#include <cmath>
#include "MadCore.h"

#define   URL "file:///C:/Users/Sohail/Desktop/Web/MadEngine/index.html"

using namespace Awesomium;

//void KeyCallback(GLFWwindow* window , int key , int scancode , int action , int mods  );

int main(){

	/*
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		// failed to initialize GLEW!
	}
	std::cout << "Using GLEW Version: "  << glewGetString(GLEW_VERSION);
	*/

	glfwInit();

	GLFWwindow* window;
	window = glfwCreateWindow( 1600 , 900, "Mad Engine" , NULL , NULL );
	glfwMakeContextCurrent(window);


	WebConfig config;
	config.remote_debugging_port = 9999;
	WebCore* web_core = WebCore::Initialize( config );
	WebView* view = web_core->CreateWebView(300, 900, 0, kWebViewType_Window); //kWebViewType_Offscreen
	view->set_parent_window( glfwGetWin32Window(window) );

	
	//Load WebPage/Interface
	WebURL url(WSLit(URL));
	view->LoadURL(url);


	Scene scene;
	Control control(window);
	Camera cam(window);
	


	while( !glfwWindowShouldClose(window) ){

		cam.Viewport();
		scene.DrawAxis();
		scene.DrawGrid();
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

/*
void KeyCallback(GLFWwindow* window , int key , int scancode , int action , int mods  ){

	if(action == GLFW_PRESS)
		switch( key ){

		case GLFW_KEY_ESCAPE:

			glfwSetWindowShouldClose(window , GL_TRUE );
			break;

	}

}
*/


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
