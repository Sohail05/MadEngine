#pragma once
#ifndef DEBUG_H
#define DEBUG_H

#include "common\String.h"
#include <iostream>
#include <fstream>

class Debug {

public:

	Debug() {};
	~Debug() {};

	template <class T>
	void Console(T msg) {

		std::cout << msg;

	}

	template <class T>
	void Log(T msg) {

		std::fstream file;
		file.open("MadEngine.log", std::ios_base::app);
		if (file.is_open())
		{
			file << msg << "\n";
			file.close();
		}


	}




};






#endif
