#ifndef MADCORE_H
#define MADCORE_H

#include "defines.h"

class MadCore{

private:

public:

	MadCore();
	~MadCore();

	int Run();
	int Init();

	void Terminate();
	void GetInfo();

	Scene scene_;
	Debug debugger;
};

#endif
