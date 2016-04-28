#pragma once
#ifndef MADCORE_H
#define MADCORE_H


#include <gl/glew.h>

#include "Defines.h"
#include <iostream>
#include "Debug.h"
#include "Context.h" 
#include "Scene.h"
#include "Camera.h"
#include "Input.h"

class MadCore{

public:

	MadCore();
	~MadCore();
	int Init();
	int Run();

	void Terminate();
	void GetInfo();

	Scene scene_;
};

#endif
