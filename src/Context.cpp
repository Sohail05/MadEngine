#include "Context.h"

Context* Context::MainContext;

//todo : Overload with the param version
EditorContext::EditorContext(){

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	window = glfwCreateWindow( 500 , 500 , "New Context" , NULL , NULL );
	WebConfig config;
	config.remote_debugging_port = 9999;
	web_core = WebCore::Initialize( config );
	view = web_core->CreateWebView(500, 500, 0, kWebViewType_Offscreen);

	WebURL url(WSLit(URL));
	view->LoadURL(url);

}

EditorContext::EditorContext(int width , int height, char* title){

	window = glfwCreateWindow( width , height , title , NULL , NULL );
	WebConfig config;
	config.remote_debugging_port = 9999;
	web_core = WebCore::Initialize( config );
	
	MadSurfaceFactory* Factory = new MadSurfaceFactory(); 
	web_core->set_surface_factory((SurfaceFactory*)Factory);

	view = web_core->CreateWebView(width, height, 0, kWebViewType_Offscreen);
	view->SetTransparent(true);

	surface = (MadSurface*)view->surface();

	WebURL url(WSLit(URL));
	view->LoadURL(url);


}

void EditorContext::Update(){

	glEnable( GL_TEXTURE_2D );

	if( surface!= NULL){

		glBindTexture(GL_TEXTURE_2D, surface->GetTexture());
	}else{
	
		surface = (MadSurface*)view->surface();
	}

	glColor3f(1.0f,1.0f,1.0f);
	int width=10, height=10;

	//glfwGetWindowSize(window , &width , &height);

	//glViewport(0,0,width,height);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(0,1,0,1,0,10);
	//glMatrixMode(GL_MODELVIEW);

	
	glBegin(GL_QUADS);
      glTexCoord2f(0,1);glVertex3f(0, 0, 0.0f);
      glTexCoord2f(1,1);glVertex3f((GLfloat)width, 0, 0.0f);
      glTexCoord2f(1,0);glVertex3f((GLfloat)width, (GLfloat)height, 0.0f);
      glTexCoord2f(0,0);glVertex3f(0, (GLfloat)height, 0.0f);
	glEnd();

	glDisable( GL_TEXTURE_2D );

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