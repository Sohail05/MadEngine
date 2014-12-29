#include "MadCore.h"

GLuint textureID;

void ChangeColor(WebView* caller, const JSArray& args);

Scene scene;

void ChangeColor(WebView* caller, const JSArray& args){


	//sece.color.SetColor(args[0].ToInteger(),args[1].ToInteger(),args[2].ToInteger(),1);
	cout << "ColorChange\n";

}

void SetScene(WebView* caller, const JSArray& args){

	scene.Axis = args[0].ToBoolean();
	scene.Grid = args[1].ToBoolean();
	//sece.color.SetColor(args[0].ToInteger(),args[1].ToInteger(),args[2].ToInteger(),1);
	cout << "Axis - Grid\n";

}


int main(){

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
	Entity3D MyObj2;

	//Declare Mesh Component & Generate Mesh data
	Mesh Cube = GenerateCube();
	Mesh tetra = GenerateTetra();

	//Light Component
	Light light;

	//Set Color
	Cube.color.SetColor(0,1,0,1);


	MyObj1.AddComponent( (Component*)&Cube );
	MyObj1.AddComponent( (Component*)&light );

	MyObj2.AddComponent( (Component*)&tetra );

	//Move Entities
	MyObj1.transform.Position.x = 5.0f;

	//Add them to the scene
	scene.AddEntity(MyObj1);
	scene.AddEntity(MyObj2);

	EditorContext* C = (EditorContext*)Context::MainContext;
	JSValue result = C->view->CreateGlobalJavascriptObject(WSLit("app"));
	JSObject& app_object = result.ToObject();
	delegator deler(app_object);

	deler.customBind( app_object , WSLit("SetScene") , &SetScene );
	C->view->set_js_method_handler(&deler);

	while( !Context::MainContext->ShouldClose() ){

		cam.Viewport();
		scene.Update();

		//context is set as the MainContext
		Context::MainContext->Update();

	}

	Context::MainContext->Terminate();
	MadTerminate();


	return 0;
}