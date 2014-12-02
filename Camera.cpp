#include "Camera.h"


void Camera::keycallback(GLFWwindow* window , int key , int scancode , int action , int mods  ){

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

void Camera::cursorcallback(GLFWwindow* window , double xpos , double ypos){

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


}

void Camera::MouseButtonCallback(GLFWwindow* window , int button , int action , int mods ){

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

void Camera::ScrollCallback(GLFWwindow* window , double xoffset , double yoffset){

    z+=yoffset;
	std::cout << "zooming";

}