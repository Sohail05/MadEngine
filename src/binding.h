#ifndef BINDING_H
#define BINDING_H

#include <Awesomium/WebCore.h>
#include <GLFW\glfw3.h>
#include "Context.h"
#include <ctype.h>

using namespace Awesomium;

int getWebKeyFromGLFWKey(int key);


//Todo: Need to handle mods differently

/***************************************

mods:
GLFW_MOD_SHIFT   0x0001
GLFW_MOD_CONTROL   0x0002
GLFW_MOD_ALT   0x0004
GLFW_MOD_SUPER   0x0008

***************************************/


void GLFW_to_Awesomium(GLFWwindow* window , int key , int scancode , int action , int mods  ){

	if( action != GLFW_PRESS ) {
		return;
	}

	EditorContext* C = (EditorContext*)Context::MainContext;

	if(C != NULL && C->view != NULL){

		WebKeyboardEvent WebKey;
		WebKey.virtual_key_code = getWebKeyFromGLFWKey(key);

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

		if(mods == GLFW_MOD_SHIFT){
			WebKey.text[0] = key;
		}else{
			WebKey.text[0] = tolower(key);
		}

		C->view->InjectKeyboardEvent(WebKey);
		cout << "Injected:" << key << "\n";

	}

	//Todo: select all,paste etc
	//Copy to clipboard C->view->Copy();
}


//Converted Awesomium's webflow demo SDL to GLFW KeyCodes
//getWebKeyFromSDLKey -> getWebKeyFromGLFWKey

#define mapKey(a, b) case GLFW_KEY_##a: return Awesomium::KeyCodes::AK_##b;

int getWebKeyFromGLFWKey(int key) {
  switch (key) {
	mapKey(UNKNOWN, UNKNOWN );
    mapKey(BACKSPACE, BACK)
    mapKey(TAB, TAB)
   // mapKey(CLEAR, CLEAR)
    mapKey(ENTER, RETURN)
    mapKey(PAUSE, PAUSE)
    mapKey(ESCAPE, ESCAPE)
    mapKey(SPACE, SPACE)
    mapKey(1, 1)
    mapKey(2, 2)
    mapKey(3, 3)
    mapKey(4, 4)
    mapKey(7, 7)
    //(QUOTE, OEM_7)
    mapKey(9, 9)
    mapKey(0, 0)
    mapKey(8, 8)
    mapKey(EQUAL, OEM_PLUS)
    mapKey(COMMA, OEM_COMMA)
    mapKey(MINUS , OEM_MINUS)
    mapKey(PERIOD, OEM_PERIOD)
    mapKey(SLASH, OEM_2)
 /*   mapKey(0, 0)
    mapKey(1, 1)
    mapKey(2, 2)
    mapKey(3, 3)
    mapKey(4, 4)
    mapKey(5, 5)
    mapKey(6, 6)
    mapKey(7, 7)
    mapKey(8, 8)
    mapKey(9, 9)*/
    //mapKey(COLON, OEM_1)
    mapKey(SEMICOLON, OEM_1)
    //mapKey(LESS, OEM_COMMA)
   // mapKey(EQUALS, OEM_PLUS)
    //mapKey(GREATER, OEM_PERIOD)
    //mapKey(QUESTION, OEM_2)
    //mapKey(AT, 2)
    //mapKey(LEFTBRACKET, OEM_4)
    mapKey(BACKSLASH, OEM_5)
   // mapKey(RIGHTBRACKET, OEM_6)
   // mapKey(CARET, 6)
   // mapKey(UNDERSCORE, OEM_MINUS)
    //mapKey(BACKQUOTE, OEM_3)
    mapKey(A, A)
    mapKey(B, B)
    mapKey(C, C)
    mapKey(D, D)
    mapKey(E, E)
    mapKey(F, F)
    mapKey(G, G)
    mapKey(H, H)
    mapKey(I, I)
    mapKey(J, J)
    mapKey(K, K)
    mapKey(L, L)
    mapKey(M, M)
    mapKey(N, N)
    mapKey(O, O)
    mapKey(P, P)
    mapKey(Q, Q)
    mapKey(R, R)
    mapKey(S, S)
    mapKey(T, T)
    mapKey(U, U)
    mapKey(V, V)
    mapKey(W, W)
    mapKey(X, X)
    mapKey(Y, Y)
    mapKey(Z, Z)
    mapKey(DELETE, DELETE)
    mapKey(KP_0, NUMPAD0)
    mapKey(KP_1, NUMPAD1)
    mapKey(KP_2, NUMPAD2)
    mapKey(KP_3, NUMPAD3)
    mapKey(KP_4, NUMPAD4)
    mapKey(KP_5, NUMPAD5)
    mapKey(KP_6, NUMPAD6)
    mapKey(KP_7, NUMPAD7)
    mapKey(KP_8, NUMPAD8)
    mapKey(KP_9, NUMPAD9)
    mapKey(KP_DECIMAL, DECIMAL)
    mapKey(KP_DIVIDE, DIVIDE)
    mapKey(KP_MULTIPLY, MULTIPLY)
    mapKey(KP_SUBTRACT , SUBTRACT)
    mapKey(KP_ADD , ADD)
    mapKey(KP_ENTER, SEPARATOR)
    mapKey(KP_EQUAL, UNKNOWN)
    mapKey(UP, UP)
    mapKey(DOWN, DOWN)
    mapKey(RIGHT, RIGHT)
    mapKey(LEFT, LEFT)
    mapKey(INSERT, INSERT)
    mapKey(HOME, HOME)
    mapKey(END, END)
    mapKey(PAGE_UP , PRIOR)
    mapKey(PAGE_DOWN, NEXT)
    mapKey(F1, F1)
    mapKey(F2, F2)
    mapKey(F3, F3)
    mapKey(F4, F4)
    mapKey(F5, F5)
    mapKey(F6, F6)
    mapKey(F7, F7)
    mapKey(F8, F8)
    mapKey(F9, F9)
    mapKey(F10, F10)
    mapKey(F11, F11)
    mapKey(F12, F12)
    mapKey(F13, F13)
    mapKey(F14, F14)
    mapKey(F15, F15)
    mapKey(NUM_LOCK, NUMLOCK)
    mapKey(CAPS_LOCK, CAPITAL)
    mapKey(SCROLL_LOCK, SCROLL)
    mapKey(RIGHT_SHIFT, RSHIFT)
    mapKey(LEFT_SHIFT , LSHIFT)
    mapKey(RIGHT_CONTROL, RCONTROL)
    mapKey(LEFT_CONTROL , LCONTROL)
    mapKey(RIGHT_ALT , RMENU)
    mapKey(LEFT_ALT , LMENU)
   // mapKey(RMETA, LWIN)
   // mapKey(LMETA, RWIN)
    mapKey(LEFT_SUPER, LWIN)
    mapKey(RIGHT_SUPER, RWIN)
   // mapKey(MODE, MODECHANGE)
  //  mapKey(COMPOSE, ACCEPT)
   // mapKey(HELP, HELP)
    mapKey(PRINT_SCREEN, SNAPSHOT)
    //mapKey(SYSREQ, EXECUTE)
  default:
    return Awesomium::KeyCodes::AK_UNKNOWN;
  }
}






#endif