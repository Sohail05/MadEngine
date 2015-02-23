#include <Windows.h>
#include "MadCore.h"

GLuint textureID;

void ChangeColor(WebView* caller, const JSArray& args);

Scene scene;

void ChangeColor(WebView* caller, const JSArray& args){


	//sece.color.SetColor(args[0].ToInteger(),args[1].ToInteger(),args[2].ToInteger(),1);
	cout << "ColorChange\n";

}

void SetScene(WebView* caller, const JSArray& args){

	scene.axis = args[0].ToBoolean();
	scene.grid = args[1].ToBoolean();
	//sece.color.SetColor(args[0].ToInteger(),args[1].ToInteger(),args[2].ToInteger(),1);
	cout << "Axis - Grid\n";

}

void GetSceneData(WebView* caller, const JSArray& args){



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
	Entity3D MyObj3;
	Entity3D MyObj4;
	Entity3D MyObj5;

	//Declare Mesh Component & Generate Mesh data
	Mesh Cube = GenerateHexahedron(2.0f);
	Mesh Tetra = GenerateTetrahedron(2.0f);
	Mesh Octa = GenerateOctahedron(2.0f);
	Mesh Icos = GenerateIcosahedron(2.0f);

	Mesh load = Mesh();
	load.vertex = LoadObj("C:/Repositories/madengine/MadEngine/resources/TetraObject/MadEngineTetra.obj"); 
	load.Mode = RenderMode::kPoint;

	//Light Component
	Light light;

	//Set Color
	Cube.color.SetColor(0,1,0,1);

	MyObj1.AddComponent( (Component*)&Cube );
	MyObj1.AddComponent( (Component*)&light );
	//Move Entities
	MyObj1.transform.position.x = 5.0f;

	MyObj2.AddComponent( (Component*)&Tetra );
	MyObj2.transform.position.x = -5.0f;

	MyObj3.AddComponent( (Component*)&Octa );
	MyObj3.transform.position.y = -5.0f;
	
	MyObj4.AddComponent( (Component*)&Icos );
	MyObj4.transform.position.y = 5.0f;

	MyObj5.AddComponent( (Component*)&load );
	MyObj5.transform.position.z = -5.0f;


	//Add them to the scene
	scene.AddEntity(MyObj1);
	scene.AddEntity(MyObj2);
	scene.AddEntity(MyObj3);
	scene.AddEntity(MyObj4);
	scene.AddEntity(MyObj5);

	
	EditorContext* C = (EditorContext*)Context::MainContext;
	JSValue result = C->view->CreateGlobalJavascriptObject(WSLit("app"));
	JSObject& app_object = result.ToObject();

	//No difference
	//delegator deler(app_object);

	delegator deler(app_object);
	deler.Bind( app_object , WSLit("SetScene") , &SetScene );
	deler.Bind( app_object , WSLit("GetSceneData") , &GetSceneData );
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