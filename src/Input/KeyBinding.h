#ifndef KEYBINDING_H
#define HEYBINDING_H

#include <GLFW\glfw3.h>

//Todo: Need to handle mods differently

/***************************************

mods:
GLFW_MOD_SHIFT   0x0001
GLFW_MOD_CONTROL   0x0002
GLFW_MOD_ALT   0x0004
GLFW_MOD_SUPER   0x0008

***************************************/

void GLFW_to_Key(GLFWwindow* window , int key , int scancode , int action , int mods  ){

	if( !(action == GLFW_PRESS  || action == GLFW_REPEAT) ) {
		return;
	}

	switch (key){

	case GLFW_KEY_A:
	case GLFW_KEY_B:
	case GLFW_KEY_C:
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
		break;
	default:
		break;
	}

}

#endif
