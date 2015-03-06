#ifndef MADCORE_H
#define MADCORE_H

#define MAD_VERSION "0.X"

#ifdef _WIN32
#include <Windows.h>
#endif

#include "Context.h" // Should really only need 2 type of context, 1. Editor and  2. Run-time
#include "Scene.h"


class MadCore{

private:

	Scene scene_;

public:

	MadCore(){};
	~MadCore(){};

	int run();
	int MadInit();

	void MadTerminate();
	void GetMadInfo();


};

#endif