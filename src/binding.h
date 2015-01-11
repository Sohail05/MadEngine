#ifndef CAMERA_H
#define CAMERA_H

#include <Awesomium/WebCore.h>
#include <GLFW\glfw3.h>
#include "Context.h"
#include <ctype.h>

using namespace Awesomium;

void GLFW_to_Awesomium(GLFWwindow* window , int key , int scancode , int action , int mods  ){

	if( action != GLFW_PRESS ) {
		return;
	}

	EditorContext* C = (EditorContext*)Context::MainContext;

	if(C != NULL && C->view != NULL){

		WebKeyboardEvent WebKey;
		WebKey.virtual_key_code = key;

		if(key == GLFW_KEY_BACKSPACE ){

			WebKey.type = WebKeyboardEvent::kTypeKeyDown;
			WebKey.virtual_key_code = '\b';
			C->view->InjectKeyboardEvent(WebKey);
			WebKey.type = WebKeyboardEvent::kTypeKeyUp;
			C->view->InjectKeyboardEvent(WebKey);
			return;

		}

		WebKey.type = WebKeyboardEvent::kTypeChar;
		WebKey.modifiers = 0;

		if(mods == GLFW_MOD_SHIFT ){
			WebKey.text[0] = key;
		}else{
			WebKey.text[0] = tolower(key);
		}

		C->view->InjectKeyboardEvent(WebKey);
		cout << "Injected:" << key << "\n";

	}


}

#endif