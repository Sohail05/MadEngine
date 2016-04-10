#ifndef MADCORE_H
#define MADCORE_H

#define MADENGINE_VERSION "0.1"

#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0


#ifdef _WIN32
#include <Windows.h>
#endif

#include "Context.h" // Should really only need 2 type of context, 1. Editor and  2. Run-time
#include "Scene.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>


#include "Entity3D.h"
#include "Component.h" // move components.h to entity or something ...
#include "Light.h" // move this to component.h

#include "Input.h"
#include "Camera.h"  //Rewrite this class

#include "Mesh.h"


class MadCore{

private:

public:

	MadCore();
	~MadCore();

	int run();
	int MadInit();

	void MadTerminate();
	void GetMadInfo();

	Scene scene_;

};

#endif