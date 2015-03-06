#include "MadCore.h"

#include <iostream>
//#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>


#include "Component.h" // move components.h to entity or something ...
#include "Light.h" // move this to component.h

#include "Input.h"
#include "Camera.h"  //Rewrite this class

int MadCore::run(){

	MadInit();

	//Create The context window
	EditorContext context = EditorContext(1800 , 900 , "Mad Engine");
	//Set it up as the main MainContext
	context.SetActive();

	//Create a Scene that Holds Entities and environment
	//Scene scene;
	Control control(context.window);
	Camera cam(context.window);

	//Create Entities/Objects in 3d space 
	Entity3D MyObj1;
	//Entity3D MyObj2;
	//Entity3D MyObj3;
	//Entity3D MyObj4;
	//Entity3D MyObj5;

	////Declare Mesh Component & Generate Mesh data
	//Mesh Cube = GenerateHexahedron(2.0f);
	//Mesh Tetra = GenerateTetrahedron(2.0f);
	//Mesh Octa = GenerateOctahedron(2.0f);
	//Mesh Icos = GenerateIcosahedron(2.0f);



	Entity3D TestEntity;
	Mesh TestMesh = TestEntity.AddComponent<Mesh>();
	TestMesh = GenerateHexahedron(1.0f);
	scene_.AddEntity(TestEntity);



	
	//Set Color
	//Cube.color.SetColor(0,1,0,1);

	//MyObj1.AddComponent( (Component*)&Cube );
	//MyObj1.AddComponent( (Component*)&light );
	////Move Entities
	//MyObj1.transform.position.x = 5.0f;

	//MyObj2.AddComponent( (Component*)&Tetra );
	//MyObj2.transform.position.x = -5.0f;

	//MyObj3.AddComponent( (Component*)&Octa );
	//MyObj3.transform.position.y = -5.0f;

	//MyObj4.AddComponent( (Component*)&Icos );
	//MyObj4.transform.position.y = 5.0f;

	//MyObj5.AddComponent( (Component*)&load );
	//MyObj5.transform.position.z = -5.0f;
	

	//Add them to the scene
	scene_.AddEntity(MyObj1);
	/*scene_.AddEntity(MyObj2);
	scene_.AddEntity(MyObj3);
	scene_.AddEntity(MyObj4);
	scene_.AddEntity(MyObj5);*/


	//EditorContext* C = (EditorContext*)Context::MainContext;
	//JSValue result = C->view->CreateGlobalJavascriptObject(WSLit("app"));
	//JSObject& app_object = result.ToObject();

	//No difference
	//delegator deler(app_object);

	//delegator deler(app_object);
	//deler.Bind( app_object , WSLit("SetScene") , &SetScene );
	//deler.Bind( app_object , WSLit("GetSceneData") , &GetSceneData );
	//C->view->set_js_method_handler(&deler);



	while( !Context::MainContext->ShouldClose() ){

		cam.Viewport();
		scene_.Update();

		//context is set as the MainContext
		Context::MainContext->Update();

	}

	Context::MainContext->Terminate();
	MadTerminate();


	return 0;


}


int MadCore::MadInit(){

	if(!glfwInit() ){

		printf("Failed to initate GLFW");
		return 1;
	}

	GLFWwindow* window;
	window = glfwCreateWindow( 500 , 500 , "Loading ..." , NULL , NULL );
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return 1;
	}

	//Todo: Implement Spasl Screen ... 
	// Oh really ? don't we have anything else better to do!

	GetMadInfo();
	glfwDestroyWindow(window);

	return 0;
}


void MadCore::MadTerminate(){

	glfwTerminate();
}


void MadCore::GetMadInfo(){

	// get version info
	const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString (GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("MadEngine Version : %s", MAD_VERSION );
}