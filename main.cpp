#include <Windows.h>
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
#include "scene.h"

//#define   URL "file:///C:/Users/Sohail/Desktop/Web/index.html"
#define   URL "file:///C:/Users/Sohail/Desktop/Web/MadEngine/index.html"
using namespace Awesomium;

void Viewport();

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

int WebViewWidth = 300;


int R=0;
int G=0;
int B=0;


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


int main(){


    glfwInit();
    window = glfwCreateWindow( 1600 , 900, "Mad Engine" , NULL , NULL );
    glfwMakeContextCurrent(window);

	WebCore* web_core = WebCore::Initialize(WebConfig());
	WebView* view = web_core->CreateWebView(WebViewWidth, 480, 0, kWebViewType_Window);

	view->set_parent_window( glfwGetWin32Window(window) );



	// Wait for our WebView to finish loading
	WebURL url(WSLit(URL));
	view->LoadURL(url);

	
	//JS CALLBACKS

	JSValue result = view->CreateGlobalJavascriptObject(WSLit("app"));
	JSObject& app_object = result.ToObject();
	delegator deler(app_object);
	
	deler.customBind( app_object , WSLit("WebViewResize") , &WebViewResize );
	deler.customBind( app_object , WSLit("ChangeColor") ,  &ChangeColor );
	deler.customBind( app_object , WSLit("SetPosition") ,  &SetPosition );

	view->set_js_method_handler(&deler);

    //Callbacks
    glfwSetKeyCallback(window , KeyCallback );
    glfwSetCursorPosCallback( window , CursorCallback );
    glfwSetMouseButtonCallback( window , MouseButtonCallback );
    glfwSetScrollCallback( window , ScrollCallback );


	//Create Scene, Mesh, Object Lights
	Mesh Cube;
	Mesh Tetra;
	Scene scene;

	Cube = GenerateCube();
	Tetra = GenerateTetra();


    while( !glfwWindowShouldClose(window) ){


		int width , height;

		glfwGetWindowSize(window , &width , &height);
		view->Resize( WebViewWidth , height);


        Viewport();

        //Movement & Rotation
        glTranslatef(MoveX , -MoveY , (GLfloat)z );
        glRotatef( RotateX , 1.0f , 0 , 0  );
        glRotatef( RotateY , 0 , 1.0f , 0  );


		scene.DrawGrid();
		scene.DrawAxis();
		Cube.Draw();
		Tetra.Draw();

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
	glViewport(WebViewWidth , 0 , width , height);
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

        float deltaX = float(xpos - lastX) ;
        float deltaY = float(ypos - lastY);

        MoveX +=  0.01f * deltaX;
        MoveY +=  0.01f * deltaY;

        lastX = xpos;
        lastY = ypos;
    }


    if(rotateControl == 1 ){

        float deltaX = float(xpos - lastX) ;
        float deltaY = float(ypos - lastY);

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