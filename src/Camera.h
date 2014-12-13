#include "Input.h"
#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/glu.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera : Input {
public:

	GLFWwindow* window;


	float zoom;
	int WebViewWidth;
	int viewmode;

	float MoveX;
	float MoveY;
	float RotateX;
	float RotateY;

	double lastX;
	double lastY;

	int Move;
	float xrot;

	int rotateControl;

	double z;



	double fovy;
	double aspectratio;
	double zNear;
	double zFar; 



	Camera(GLFWwindow* win)
	{
		window = win;
		zoom=5;
		WebViewWidth =300;
		viewmode = 1;

		RotateX=30;
		z = -25;
		 MoveX=0;
		 MoveY=0;
		 RotateY=0;
		 lastY=0;
		 lastX=0;

		fovy = 45.0f;
		aspectratio;
		zNear=1;
		zFar=500; 

		event_handling_instance = this;
		//setEventHandling(); this doesnt work ... perhaps because of controls() or "final"

	}


	virtual void keycallback(GLFWwindow *window,int key,int scancode,int action,int mods);
	virtual void cursorcallback(GLFWwindow* window , double xpos , double ypos);
	virtual void MouseButtonCallback(GLFWwindow* window , int button , int action , int mods );
	virtual void ScrollCallback(GLFWwindow* window , double xoffset , double yoffset);


	void Viewport(){

		int width , height;

		glfwGetWindowSize(window , &width , &height);
		aspectratio = width / (float)height ;

		// Enable depth test
		glEnable(GL_DEPTH_TEST);
		// Accept fragment if it closer to the camera than the former one
		glDepthFunc(GL_LESS);

		//Add Gui Offset here for awesomium
		glViewport(WebViewWidth , 0 , width , height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		if (viewmode == 0){
			glOrtho(-aspectratio*zoom, aspectratio*zoom, -1.f*zoom, 1.f*zoom, 1.f, 500.f);
			glMatrixMode(GL_MODELVIEW);
		}else{
			gluPerspective( fovy , aspectratio , zNear , zFar);
			//glm::perspective(  &zNear , &aspectratio , &zNear , &zFar);
			glMatrixMode(GL_MODELVIEW);
		}
		glLoadIdentity();


		glTranslatef(MoveX , -MoveY , (GLfloat)z );
		glRotatef( RotateX , 1.0f , 0 , 0  );
		glRotatef( RotateY , 0 , 1.0f , 0  );

	}




private:

};
