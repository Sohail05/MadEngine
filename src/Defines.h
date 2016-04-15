#ifndef DEFINES_H
#define DEFINES_H

#define MADENGINE_VERSION "0.1"

#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0

//Windows
#ifdef _WIN32
#include <Windows.h>
#endif

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>

#include "../utilities/Debug.h"

#include "Context.h" // Should really only need 2 type of context, 1. Editor and  2. Run-time
#include "Scene.h"
#include "Entity.h"
#include "../inputs/Input.h"
#include "../inputs/Camera.h"  //Rewrite this class
#include "../components/Mesh.h"

#endif
