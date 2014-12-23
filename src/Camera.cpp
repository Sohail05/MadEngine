#include "Camera.h"

void Camera::keycallback(GLFWwindow* window , int key , int scancode , int action , int mods  ){

	if(action == GLFW_PRESS)
		switch( key ){

		case GLFW_KEY_ESCAPE:

			glfwSetWindowShouldClose(window , GL_TRUE );
			break;

		case GLFW_KEY_F:

			if( CameraViewMode == ViewMode::Orthographic ){
				CameraViewMode = ViewMode::Perspective;
			}else{
				CameraViewMode = ViewMode::Orthographic;
			}
			break;

		case GLFW_KEY_R:

			transform.Rotation = glm::vec3( 30 , 0 , 0  );
			transform.Position = glm::vec3(0 , 0 , -25 );
			zoom = 10;
			CameraViewMode = ViewMode::Perspective ;
			break;

		case GLFW_KEY_U:

			Context::MainContext->NeedUpdate = true;
			break;

	}



	if( key == GLFW_KEY_KP_SUBTRACT && action == GLFW_PRESS ){

	}
	if( key == GLFW_KEY_KP_ADD && action == GLFW_PRESS ){

	}

	if( key == GLFW_KEY_DOWN && action == GLFW_PRESS ){

	}
	if( key == GLFW_KEY_UP && action == GLFW_PRESS ){

	}


}

void Camera::cursorcallback(GLFWwindow* window , double xpos , double ypos){

	if(Pan == true){

		float deltaX = (float)(xpos - lastX);
		float deltaY = (float)(ypos - lastY);

		transform.Position.x +=  0.01f * deltaX;
		transform.Position.y +=  0.01f * deltaY;

		lastX = xpos;
		lastY = ypos;
	}

/* splited them into OrbitX and OrbitY
	if(rotateControl == 1 ){

		float deltaX = (float)(xpos - lastX) ;
		float deltaY = (float)(ypos - lastY);

		transform.Rotation.x +=  0.1f * deltaY;
		transform.Rotation.y +=  0.1f * deltaX;

		lastX = xpos;
		lastY = ypos;
	}
*/

	if(OrbitX == true ){

		float deltaX = (float)(xpos - lastX) ;
		transform.Rotation.y +=  0.1f * deltaX;
		lastX = xpos;

	}

	if(OrbitY == true ){

		float deltaY = (float)(ypos - lastY) ;
		transform.Rotation.x +=  0.1f * deltaY;
		lastY = ypos;

	}




}

void Camera::MouseButtonCallback(GLFWwindow* window , int button , int action , int mods ){

	if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS ){
		Pan = true;
		glfwGetCursorPos(window , &lastX , &lastY );
	}

	if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE ){
		Pan = false;
	}

	if( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS ){
		OrbitX = true;
		OrbitY = true;
		glfwGetCursorPos(window , &lastX , &lastY );
	}
	if( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE ){
		OrbitX = false;
		OrbitY = false;

	}

}

void Camera::ScrollCallback(GLFWwindow* window , double xoffset , double yoffset){

	transform.Position.z += (float)yoffset;
}