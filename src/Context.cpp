#include "Context.h"

Context* Context::MainContext;

//todo : Overload with the param version
EditorContext::EditorContext(){

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	window = glfwCreateWindow( 500 , 500 , "New Context" , NULL , NULL );
	WebConfig config;
	config.remote_debugging_port = 9999;
	web_core = WebCore::Initialize( config );
	//view = web_core->CreateWebView(300, 900, 0, kWebViewType_Window);// //kWebViewType_Offscreen
	view = web_core->CreateWebView(300, 900, 0, kWebViewType_Offscreen);
	//view->set_parent_window( glfwGetWin32Window(window) );

	//Load WebPage/Interface
	WebURL url(WSLit(URL));
	view->LoadURL(url);

}

EditorContext::EditorContext(int width , int height, char* title){

	window = glfwCreateWindow( width , height , title , NULL , NULL );
	WebConfig config;
	config.remote_debugging_port = 9999;
	web_core = WebCore::Initialize( config );

	//view = web_core->CreateWebView(300, 900, 0, kWebViewType_Window); //kWebViewType_Offscreen
	view = web_core->CreateWebView(width, height, 0, kWebViewType_Offscreen);
	view->SetTransparent(true);

/* For Onscreen view
#ifdef __linux__  
	view->set_parent_window( glfwGetX11Window(window) );
#endif

#ifdef _WIN32  
	//view->set_parent_window( glfwGetWin32Window(window) );
#endif
*/


	//Load WebPage/Interface
	WebURL url(WSLit(URL));
	view->LoadURL(url);

}

void EditorContext::Update(){

	web_core->Update();
	glfwSwapBuffers(window);
	glfwSwapInterval(1);
	glfwPollEvents();

}

void EditorContext::Terminate(){

	glfwDestroyWindow(window);
	view->Destroy();
	WebCore::Shutdown();


}

void EditorContext::SetActive(){

	MainContext = this;
	glfwMakeContextCurrent(window);

}

int EditorContext::ShouldClose(){

	return glfwWindowShouldClose(window);
}