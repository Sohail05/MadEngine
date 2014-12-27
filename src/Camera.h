#ifndef CAMERA_H
#define CAMERA_H

#include "Context.h"
#include "Input.h"
#include "Transform.h"


/**********
References:

Roll
1	0	0
0  cos -sin
0  sin cos

Pitch
cos	0	sin
0	1	0
-sin	0	cos

Yaw
cos	 -sin	0
sin	  cos	0
0	0	0
*****/


enum ViewMode{

	Orthographic = 0,
	Perspective = 1
	//Todo: Add Panorama
	//Todo: Add Fish Eye

};


class Camera : Input {
public:

	GLFWwindow* window;
	ViewMode CameraViewMode;
	Transform transform;

	float zoom;

	double fovy;
	double aspectratio;
	double zNear;
	double zFar; 


	double lastX;
	double lastY;

	//Rotation Controls
	bool Roll;		//Not implemented
	bool Yaw;		//Not implemented
	bool Pitch;		//Not implemented

	bool OrbitX;
	bool OrbitY;

	//Position Controls
	bool Pan;


	bool Zoom;


	Camera(GLFWwindow* win)
	{
		window = win;
		zoom=5;

		CameraViewMode = ViewMode::Perspective;

		transform.Rotation = glm::vec3(30.0f , 0 , 0 );
		transform.Position = glm::vec3(0.0f , 0.0f ,-25.0f);

		lastY=0;
		lastX=0;

		fovy = 45.0f;
		zNear=1;
		zFar=500; 

		SetMainInput();

	}


	virtual void Keycallback(GLFWwindow *window,int key,int scancode,int action,int mods);
	virtual void Cursorcallback(GLFWwindow* window , double xpos , double ypos);
	virtual void MouseButtonCallback(GLFWwindow* window , int button , int action , int mods );
	virtual void ScrollCallback(GLFWwindow* window , double xoffset , double yoffset);
	virtual void ResizeCallback(GLFWwindow* window , int width , int height);

	void Viewport(){

		//Todo: Set Aspect Ratio to a public member
		int width , height;
		glfwGetWindowSize(window , &width , &height);
		aspectratio = width / (float)height ;

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glViewport( 0 , 0 , width , height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		if (CameraViewMode == ViewMode::Orthographic){

			glOrtho(-aspectratio*zoom, aspectratio*zoom, -1.f*zoom, 1.f*zoom, 1.f, 500.f);
			glMatrixMode(GL_MODELVIEW);

		}else{

			gluPerspective( fovy , aspectratio , zNear , zFar);
			//Implement glm::perspective(  &zNear , &aspectratio , &zNear , &zFar);
			glMatrixMode(GL_MODELVIEW);
		}
		glLoadIdentity();

		//Todo: Implement with GLM here
		glTranslatef(transform.Position.x , -transform.Position.y, transform.Position.z );
		glRotatef( transform.Rotation.x , 1.0f , 0 , 0  );
		glRotatef( transform.Rotation.y , 0 , 1.0f , 0  );

	}

private:

};


#endif