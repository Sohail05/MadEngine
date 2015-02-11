#include "Context.h"

Context* Context::MainContext;

//todo : Overload with the param version
EditorContext::EditorContext() : width_(500) , height_(500) , title_("New Context") {

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	window = glfwCreateWindow( width_ , height_ , title_ , NULL , NULL );
	WebConfig config;
	config.remote_debugging_port = 9999;
	web_core = WebCore::Initialize( config );
	view = web_core->CreateWebView(width_, height_, 0, kWebViewType_Offscreen);
	view->Focus();

	WebURL url(WSLit(URL));
	view->LoadURL(url);

}

EditorContext::EditorContext(int width , int height, char* title) : width_(width) , height_(height) , title_(title){

	window = glfwCreateWindow( width_ , height_ , title_ , NULL , NULL );
	WebConfig config;
	config.remote_debugging_port = 9999;
	web_core = WebCore::Initialize( config );

	MadSurfaceFactory* Factory = new MadSurfaceFactory(); 
	web_core->set_surface_factory((SurfaceFactory*)Factory);

	view = web_core->CreateWebView(width_, height_, 0, kWebViewType_Offscreen);
	view->SetTransparent(true);
	view->Focus();

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

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor3f(1.0f,1.0f,1.0f);

	glMatrixMode (GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode (GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();


	glBegin(GL_QUADS);
	glTexCoord2f(0,1);glVertex3i (-1, -1, -1);
	glTexCoord2f(1,1);glVertex3i (1, -1, -1);
	glTexCoord2f(1,0);glVertex3i (1, 1, -1);
	glTexCoord2f(0,0);glVertex3i (-1, 1, -1);
	glEnd();

	glPopMatrix();
	glMatrixMode (GL_MODELVIEW);
	glPopMatrix();
	

	/*
	glBegin(GL_QUADS);
	glTexCoord2f(0,1);glVertex3f(0, 0, 0.0f);
	glTexCoord2f(1,1);glVertex3f((GLfloat)10, 0, 0.0f);
	glTexCoord2f(1,0);glVertex3f((GLfloat)10, (GLfloat)10, 0.0f);
	glTexCoord2f(0,0);glVertex3f(0, (GLfloat)10, 0.0f);
	glEnd();
	*/

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