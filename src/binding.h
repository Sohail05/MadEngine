#include <Awesomium/WebCore.h>
#include <GLFW\glfw3.h>
#include "Context.h"
#include <ctype.h>

using namespace Awesomium;

void GLFW_to_Awesomium(GLFWwindow* window , int key , int scancode , int action , int mods  ){

	if( action != GLFW_PRESS || key == GLFW_KEY_LEFT_SHIFT ) {
		return;
	}

	EditorContext* C = (EditorContext*)Context::MainContext;
	WebKeyboardEvent WebKey;


	WebKey.type = Awesomium::WebKeyboardEvent::kTypeKeyDown;
	WebKey.virtual_key_code = key;


	if(key == 259){

		if(C != NULL && C->view != NULL){
			WebKey.type = WebKeyboardEvent::kTypeKeyDown;
			WebKey.virtual_key_code = '\b';
			C->view->InjectKeyboardEvent(WebKey);
			WebKey.type = WebKeyboardEvent::kTypeKeyUp;
			C->view->InjectKeyboardEvent(WebKey);
			return;

		}

	}

	WebKey.type = WebKeyboardEvent::kTypeChar;
	WebKey.modifiers = 0;

	if(mods == GLFW_MOD_SHIFT ){
		WebKey.text[0] = key;
	}else{
		WebKey.text[0] = tolower(key);
	}

	//WebKey.unmodified_text[0] = (unsigned int)key;



	//EditorContext* C = (EditorContext*)Context::MainContext;

	if(C != NULL && C->view != NULL){

		if( key == 259 ){
			WebKey.type = WebKeyboardEvent::kTypeKeyDown;
			C->view->InjectKeyboardEvent(WebKey);
		}

		C->view->InjectKeyboardEvent(WebKey);
		cout << "Injected:" << key << "\n";

	}


}