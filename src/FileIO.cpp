#include "FileIO.h"

using namespace std;

std::string LoadFile( char* Filepath ){

	string Buffer = "";
	string Text;
	ifstream InputFile(Filepath , std::ios::in);

	if(InputFile.is_open()){

		while( getline( InputFile, Buffer ) ){

			Text += "\n" + Buffer;

		}

		InputFile.close();

	}else{
	
		cout  << "cannot open or file not found: " << Filepath;
		return NULL;
	}

	cout << Text;

	return Text;
}