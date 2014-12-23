﻿#include <Windows.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL

#include <GLFW/glfw3native.h>

#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include "DelegateHandler.h"

#define   URL "file:///C:/Users/Sohail/Desktop/Web/index.html"

using namespace Awesomium;

void Viewport();
void DrawGrid();
void DrawCube();
void DrawAxis();
void DrawTetra();

static void KeyCallback(GLFWwindow* window , int key , int scancode , int action , int mods  );
static void CursorCallback(GLFWwindow* window , double xpos , double ypos);
static void MouseButtonCallback(GLFWwindow* window , int button , int action , int mods );
static void ScrollCallback(GLFWwindow* window , double xoffset , double yoffset);

int viewmode = 1;

float MoveX=0;
float MoveY=0;
float RotateX=30;
float RotateY=0;

double lastX=0;
double lastY=0;

int Move = 0;
int zoom = 10;
float xrot = 0;

int rotateControl = 0;

double z = -25;

GLFWwindow* window;


int leftwall = 300;

int R=0;
int G=0;
int B=0;


void doit(WebView* caller, const JSArray& args){

	leftwall = args[0].ToInteger();

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


int main(){

    glfwInit();
    window = glfwCreateWindow( 1600 , 900, "Basic 3D Viewer" , NULL , NULL );
    glfwMakeContextCurrent(window);

	WebCore* web_core = WebCore::Initialize(WebConfig());
	WebView* view = web_core->CreateWebView(200, 480, 0, kWebViewType_Window);

	view->set_parent_window( glfwGetWin32Window(window) );



	// Wait for our WebView to finish loading
	WebURL url(WSLit(URL));
	view->LoadURL(url);

	//We dont really need to wait
	//while (view->IsLoading()){
	// web_core->Update();
	//}
	// Sleep a bit and update once more to give scripts and plugins
	// on the page a chance to finish loading.
	//Sleep(300);
	//web_core->Update();


	
	
	//JS CALLBACKS

	JSValue result = view->CreateGlobalJavascriptObject(WSLit("app"));
	JSObject& app_object = result.ToObject();
	delegator deler(app_object);
	
	deler.customBind( app_object , WSLit("leftwall") , &doit );
	deler.customBind( app_object , WSLit("ChangeColor") ,  &ChangeColor );
	deler.customBind( app_object , WSLit("SetPosition") ,  &SetPosition );

	view->set_js_method_handler(&deler);

    //Callbacks
    glfwSetKeyCallback(window , KeyCallback );
    glfwSetCursorPosCallback( window , CursorCallback );
    glfwSetMouseButtonCallback( window , MouseButtonCallback );
    glfwSetScrollCallback( window , ScrollCallback );

    while( !glfwWindowShouldClose(window) ){


		int width , height;
		glfwGetWindowSize(window , &width , &height);
		view->Resize(leftwall,height);


        Viewport();

        //Movement & Rotation
        glTranslatef(MoveX , -MoveY , (GLfloat)z );
        glRotatef( RotateX , 1.0f , 0 , 0  );
        glRotatef( RotateY , 0 , 1.0f , 0  );


        DrawGrid();
        //DrawCube();
		DrawAxis();
		DrawTetra();

		//view->set_js_method_handler(&deler);
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

void Viewport(){

    float ratio;
    int width , height;

    glfwGetWindowSize(window , &width , &height);
    ratio = width / (float)height ;

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

	//Add Gui Offset here for awesomium
    glViewport(leftwall , 0 , width , height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (viewmode == 0){
        glOrtho(-ratio*zoom, ratio*zoom, -1.f*zoom, 1.f*zoom, 1.f, 500.f);
        glMatrixMode(GL_MODELVIEW);
    }else{
        gluPerspective( 45.0 , ratio , 1.0 , 500.0);
        glMatrixMode(GL_MODELVIEW);
    }
    glLoadIdentity();


}

void DrawCube(){

    GLfloat vertices[] = {
//back
        -1.0, -1.0,  -1.0,  //0 Bottom left
         1.0, -1.0,  -1.0,  //1 Bottom right
        -1.0,  1.0,  -1.0,  //2 Top Left
         1.0,  1.0,  -1.0,  //3 Top Right
//front
        -1.0, -1.0,  1.0,   //4 Bottom left
         1.0, -1.0,  1.0,   //5 Bottom right
        -1.0,  1.0,  1.0,   //6 Top Left
         1.0,  1.0,  1.0    //7 Top Right

    };


    GLubyte colors[] =
    {

      R,G,B,       //0 Bottom left
      R,G,B,       //1 Bottom right
      R,G,B,       //2 Top Left
      R,G,B,       //3 Top Right
		
      R,G,B,       //4 Bottom left
      R,G,B,       //5 Bottom right
      R,G,B,       //6 Top Left
      R,G,B        //7 Top Right
    };

    // 8 of vertex coords
    // 24 indices
    GLubyte indices[] = {0,1,3,2, //back face
                         4,5,7,6, //front face
                         0,1,5,4, //Bottom face
                         2,3,7,6, //Top face
                         1,3,7,5, //Right face
                         0,2,6,4  //Left face
                        };

    // Activate Vertex and Color Buffer
    glEnableClientState( GL_VERTEX_ARRAY);
    glEnableClientState( GL_COLOR_ARRAY );

    // Specify Color Buffer
    glColorPointer( 3, GL_UNSIGNED_BYTE, 0, colors );
    // Specify pointer to vertex array
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    // draw a cube
    glDrawElements(GL_QUADS, (sizeof(indices)/sizeof(*indices)) , GL_UNSIGNED_BYTE, indices);
    //std::cout << (sizeof(indices)/sizeof(*indices));

    // deactivate vertex arrays after drawing
    glDisableClientState(GL_VERTEX_ARRAY);

}


void DrawTetra(){

	

	glTranslatef(position.x , position.y , position.z);


    GLfloat vertices[] = {

		/* -1.0,  0.0,   -1/sqrtf(2),  
         1.0,  0.0,   -1/sqrtf(2),			
         0.0,  -1.0,   1/sqrtf(2),			
         0.0,  1.0,   1/sqrtf(2),	*/		


		1,1,1,
		1, -1,-1,
		-1,1,-1,
		-1,-1,1
    };


	//(1,1,1), (1,−1,−1), (−1,1,−1), (−1,−1,1)



    GLubyte colors[] =
    {

      R,G,B,       //0 Bottom left
      R,G,B,       //1 Bottom right
      R,G,B,       //2 Top Left
      R,G,B,       //3 Top Right
		
    };

    // 8 of vertex coords
    // 24 indices
    GLubyte indices[] = {
		
					0,1,
					0,2,
					0,3,
					1,2,
					1,3,
					2,3
                        };

    // Activate Vertex and Color Buffer
    glEnableClientState( GL_VERTEX_ARRAY);
    glEnableClientState( GL_COLOR_ARRAY );

    // Specify Color Buffer
    glColorPointer( 3, GL_UNSIGNED_BYTE, 0, colors );
    // Specify pointer to vertex array
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    // draw a cube
    glDrawElements(GL_LINES, (sizeof(indices)/sizeof(*indices)) , GL_UNSIGNED_BYTE, indices);
    //std::cout << (sizeof(indices)/sizeof(*indices));

    // deactivate vertex arrays after drawing
    glDisableClientState(GL_VERTEX_ARRAY);
	glLoadIdentity();
}



void DrawGrid(){


    glBegin(GL_LINES);
    glColor3f(0.7f, 0.7f, 0.7f);

    for(int i = -10 ; i <= 10 ; i++  ){

        glVertex3f(  i, 0,-10);
        glVertex3f(  i, 0, 10);

        glVertex3f(  -10, 0, i);
        glVertex3f(   10, 0, i);

        //glVertex3f(  i, -10,0);
        // glVertex3f(  i, 10, 0);

        //glVertex3f(  -10, i, 0);
        //glVertex3f(   10, i, 0);

    }
    glEnd();


}

void DrawAxis(){


	glLineWidth( 5.0f );
	glEnable(GL_LINE_SMOOTH);

    GLfloat vertices[] = {

		 0.0,  0.0,   0.0,	
         10.0,  0.0,   0.0,  
         0.0,  10.0,   0.0,  
         0.0,  0.0,   10.0,  

    };


    GLubyte colors[] =
    {

      255,255,255, 
      255,0,0,       
      0,255,0,       
      0,0,255,       
		
    };

    // 8 of vertex coords
    // 24 indices
    GLubyte indices[] = {0,1,
                         0,2,
                         0,3,
                        };

    // Activate Vertex and Color Buffer
    glEnableClientState( GL_VERTEX_ARRAY);
    glEnableClientState( GL_COLOR_ARRAY );

    // Specify Color Buffer
    glColorPointer( 3, GL_UNSIGNED_BYTE, 0, colors );
    // Specify pointer to vertex array
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    // draw a cube
	glDrawElements(GL_LINES, (sizeof(indices)/sizeof(*indices)) , GL_UNSIGNED_BYTE, indices);
    //std::cout << (sizeof(indices)/sizeof(*indices));

    // deactivate vertex arrays after drawing
    glDisableClientState(GL_VERTEX_ARRAY);
	glLineWidth( 1.0f );
	glDisable(GL_LINE_SMOOTH);

}




static void KeyCallback(GLFWwindow* window , int key , int scancode , int action , int mods  ){

    if(action == GLFW_PRESS)
        switch( key ){

        case GLFW_KEY_ESCAPE:

            glfwSetWindowShouldClose(window , GL_TRUE );
            break;

        case GLFW_KEY_F:

            if( viewmode == 0 ){
                viewmode = 1;
            }else{
                viewmode = 0;
            }
            break;

        case GLFW_KEY_R:
            RotateX=30;
            RotateY=0;
            MoveX=0;
            MoveY=0;
            zoom = 10;
            z= -25;
            viewmode = 1;
            break;


        }



    if( key == GLFW_KEY_KP_SUBTRACT && action == GLFW_PRESS ){
        zoom--;

    }
    if( key == GLFW_KEY_KP_ADD && action == GLFW_PRESS ){
        zoom++;

    }

    if( key == GLFW_KEY_DOWN && action == GLFW_PRESS ){
        xrot--;

    }
    if( key == GLFW_KEY_UP && action == GLFW_PRESS ){
        xrot++;

    }


}

static void CursorCallback(GLFWwindow* window , double xpos , double ypos){

    if(Move == 1){

        float deltaX = xpos - lastX ;
        float deltaY = ypos - lastY;

        MoveX +=  0.01f * deltaX;
        MoveY +=  0.01f * deltaY;

        lastX = xpos;
        lastY = ypos;
    }


    if(rotateControl == 1 ){

        float deltaX = xpos - lastX ;
        float deltaY = ypos - lastY;

        RotateX +=  0.1f * deltaY;
        RotateY +=  0.1f * deltaX;

        lastX = xpos;
        lastY = ypos;
    }


	std::cout << "x: "<< xpos << " - y: "<< ypos << "\n";


}

static void MouseButtonCallback(GLFWwindow* window , int button , int action , int mods ){

    if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS ){
        Move = 1;
        glfwGetCursorPos(window , &lastX , &lastY );
    }

    if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE ){
        Move = 0;
    }

    if( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS ){
        rotateControl = 1;
        glfwGetCursorPos(window , &lastX , &lastY );
    }
    if( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE ){
        rotateControl = 0;

    }

}

static void ScrollCallback(GLFWwindow* window , double xoffset , double yoffset){

    z+=yoffset;

}