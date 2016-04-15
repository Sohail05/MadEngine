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

	if( !(action == GLFW_PRESS  || action == GLFW_REPEAT) ) {
		return;
	}

	EditorContext* C = (EditorContext*)Context::MainContext;

	if( C == NULL && C->view == NULL ){
		return;
	}

	WebKeyboardEvent WebKey;
	WebKey.type =  Awesomium::WebKeyboardEvent::kTypeKeyDown;
	WebKey.virtual_key_code = getWebKeyFromGLFWKey(key);
	WebKey.modifiers = mods;
	WebKey.native_key_code = getWebKeyFromGLFWKey(key);

	switch (key)
	{

	case GLFW_KEY_A:
		//Control-A Select all
		if( mods == GLFW_MOD_CONTROL ){
			WebKey.type = WebKeyboardEvent::kTypeKeyDown;
			break;
		}
	case GLFW_KEY_B:
	case GLFW_KEY_C:
		//Control-C Copy
		if( mods == GLFW_MOD_CONTROL ){
			WebKey.type = WebKeyboardEvent::kTypeKeyDown;
			break;
		}
	case GLFW_KEY_D:
	case GLFW_KEY_E:
	case GLFW_KEY_F:
	case GLFW_KEY_G:
	case GLFW_KEY_H:
	case GLFW_KEY_I:
	case GLFW_KEY_J:
	case GLFW_KEY_K:
	case GLFW_KEY_L:
	case GLFW_KEY_M:
	case GLFW_KEY_N:
	case GLFW_KEY_O:
	case GLFW_KEY_P:
	case GLFW_KEY_Q:
	case GLFW_KEY_R:
	case GLFW_KEY_S:
	case GLFW_KEY_T:
	case GLFW_KEY_U:
	case GLFW_KEY_V:
		//Control-V Paste
		if( mods == GLFW_MOD_CONTROL ){
			WebKey.type = WebKeyboardEvent::kTypeKeyDown;
			break;
		}
	case GLFW_KEY_W:
	case GLFW_KEY_X:
	case GLFW_KEY_Y:
	case GLFW_KEY_Z:
	case GLFW_KEY_SPACE 		:
	case GLFW_KEY_APOSTROPHE    :
	case GLFW_KEY_COMMA         :
	case GLFW_KEY_MINUS         :
	case GLFW_KEY_PERIOD        :
	case GLFW_KEY_SLASH         :
	case GLFW_KEY_0             :
	case GLFW_KEY_1             :
	case GLFW_KEY_2             :
	case GLFW_KEY_3             :
	case GLFW_KEY_4             :
	case GLFW_KEY_5             :
	case GLFW_KEY_6             :
	case GLFW_KEY_7             :
	case GLFW_KEY_8             :
	case GLFW_KEY_9             :
	case GLFW_KEY_SEMICOLON     :
	case GLFW_KEY_EQUAL         :
	case GLFW_KEY_LEFT_BRACKET  :
	case GLFW_KEY_BACKSLASH     :
	case GLFW_KEY_RIGHT_BRACKET :
	case GLFW_KEY_GRAVE_ACCENT  :
		//case GLFW_KEY_KP_0:
		//case GLFW_KEY_KP_1:
		//case GLFW_KEY_KP_2:
		//case GLFW_KEY_KP_3:
		//case GLFW_KEY_KP_4:
		//case GLFW_KEY_KP_5:
		//case GLFW_KEY_KP_6:
		//case GLFW_KEY_KP_7:
		//case GLFW_KEY_KP_8:
		//case GLFW_KEY_KP_9:
		//case GLFW_KEY_KP_DECIMAL :
		//case GLFW_KEY_KP_DIVIDE  :
		//case GLFW_KEY_KP_MULTIPLY:
		//case GLFW_KEY_KP_SUBTRACT:
		//case GLFW_KEY_KP_ADD     :
		//case GLFW_KEY_KP_ENTER   :
		//case GLFW_KEY_KP_EQUAL   :
		WebKey.type = WebKeyboardEvent::kTypeChar;
		if( mods == GLFW_MOD_SHIFT){
			WebKey.text[0] = key;
		}else{
			WebKey.text[0] = tolower(key);
		}
		break;
	case GLFW_KEY_ESCAPE      :
	case GLFW_KEY_ENTER       :
	case GLFW_KEY_TAB         :
	case GLFW_KEY_BACKSPACE   :
	case GLFW_KEY_INSERT      :
	case GLFW_KEY_DELETE      :
	case GLFW_KEY_RIGHT       :
	case GLFW_KEY_LEFT        :
	case GLFW_KEY_DOWN        :
	case GLFW_KEY_UP          :
	case GLFW_KEY_PAGE_UP     :
	case GLFW_KEY_PAGE_DOWN   :
	case GLFW_KEY_HOME        :
	case GLFW_KEY_END         :
	case GLFW_KEY_CAPS_LOCK   :
	case GLFW_KEY_SCROLL_LOCK :
	case GLFW_KEY_NUM_LOCK    :
	case GLFW_KEY_PRINT_SCREEN:
	case GLFW_KEY_PAUSE       :
		//case GLFW_KEY_F1  :
		//case GLFW_KEY_F2  :
		//case GLFW_KEY_F3  :
		//case GLFW_KEY_F4  :
		//case GLFW_KEY_F5  :
		//case GLFW_KEY_F6  :
		//case GLFW_KEY_F7  :
		//case GLFW_KEY_F8  :
		//case GLFW_KEY_F9  :
		//case GLFW_KEY_F10 :
		//case GLFW_KEY_F11 :
		//case GLFW_KEY_F12 :
		//case GLFW_KEY_LEFT_SHIFT      :
		//case GLFW_KEY_LEFT_CONTROL    :
		//case GLFW_KEY_LEFT_ALT        :
		//case GLFW_KEY_LEFT_SUPER      :
		//case GLFW_KEY_RIGHT_SHIFT     :
		//case GLFW_KEY_RIGHT_CONTROL   :
		//case GLFW_KEY_RIGHT_ALT       :
		//case GLFW_KEY_RIGHT_SUPER     :
		//case GLFW_KEY_MENU            :
		WebKey.type = WebKeyboardEvent::kTypeKeyDown;
		break;
	default:
		WebKey.type = WebKeyboardEvent::kTypeKeyDown;
		break;
	}


	C->view->InjectKeyboardEvent(WebKey);
	WebKey.type = WebKeyboardEvent::kTypeKeyUp;
	C->view->InjectKeyboardEvent(WebKey);


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
