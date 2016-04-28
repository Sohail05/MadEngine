#include "Camera.h"
/*
void Camera::Keycallback(GLFWwindow* window , int key , int scancode , int action , int mods  ){

	GLFW_to_Awesomium(window ,  key ,  scancode ,  action ,  mods);

	if(action == GLFW_PRESS)
		switch( key ){

		case GLFW_KEY_ESCAPE:

			glfwSetWindowShouldClose(window , GL_TRUE );
			break;

		case GLFW_KEY_F:

			if( CameraViewMode == ViewMode::kOrthographic ){
				CameraViewMode = ViewMode::kPerspective;
			}else{
				CameraViewMode = ViewMode::kOrthographic;
			}
			break;

		case GLFW_KEY_R:

			transform.rotation = glm::vec3( 30 , 0 , 0  );
			transform.position = glm::vec3(0 , 0 , -25 );
			zoom = 1;
			CameraViewMode = ViewMode::kPerspective ;
			break;

		case GLFW_KEY_U:

			EditorContext* C = (EditorContext*)Context::MainContext;

			if(C->view != NULL){
				WebURL url(WSLit(URL));
				C->view->LoadURL(url);
			}

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

void Camera::Cursorcallback(GLFWwindow* window , double xpos , double ypos){

	if(pan == true){

		float deltaX = (float)(xpos - lastX);
		float deltaY = (float)(ypos - lastY);

		transform.position.x +=  0.01f * deltaX;
		transform.position.y +=  0.01f * deltaY;

		lastX = xpos;
		lastY = ypos;
	}



	if(orbit_y == true ){

		float deltaX = (float)(xpos - lastX) ;
		transform.rotation.y +=  0.1f * deltaX;
		lastX = xpos;

	}

	if(orbit_y == true ){

		float deltaY = (float)(ypos - lastY) ;
		transform.rotation.x +=  0.1f * deltaY;
		lastY = ypos;

	}

	EditorContext* C = (EditorContext*)Context::MainContext;

	if(C->view != NULL){

		C->view->InjectMouseMove( (int)xpos , (int)ypos );
	}



}

void Camera::MouseButtonCallback(GLFWwindow* window , int button , int action , int mods ){

	if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS ){

		pan = true;
		glfwGetCursorPos(window , &lastX , &lastY );

	}

	if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE ){
		pan = false;
	}

	if( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS ){
		orbit_x = true;
		orbit_y = true;
		glfwGetCursorPos(window , &lastX , &lastY );
	}
	if( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE ){
		orbit_x = false;
		orbit_y = false;

	}

	EditorContext* C = (EditorContext*)Context::MainContext;

	if(C->view != NULL){


		if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS ){
			C->view->InjectMouseDown(Awesomium::kMouseButton_Left);
		}
		if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE ){
			C->view->InjectMouseUp(Awesomium::kMouseButton_Left);
		}
		if( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS ){
			C->view->InjectMouseDown(Awesomium::kMouseButton_Right);
		}
		if( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE ){
			C->view->InjectMouseUp(Awesomium::kMouseButton_Right);
		}


	}

}

void Camera::ScrollCallback(GLFWwindow* window , double xoffset , double yoffset){

	transform.position.z += (float)yoffset;

	EditorContext* C = (EditorContext*)Context::MainContext;

	if(C->view != NULL){

		C->view->InjectMouseWheel( (int)yoffset , (int)xoffset);
	}
}

void Camera::ResizeCallback(GLFWwindow* window , int width , int height){

	EditorContext* C = (EditorContext*)Context::MainContext;

	if(C->view != NULL){

		C->view->Resize(width, height);

	}

}

*/