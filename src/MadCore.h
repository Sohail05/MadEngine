#ifndef MADCORE_H
#define MADCORE_H

#define MAD_VERSION "0.X"

#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0

#ifdef _WIN32
#include <Windows.h>
#endif

#include "Context.h" // Should really only need 2 type of context, 1. Editor and  2. Run-time
#include "Scene.h"


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