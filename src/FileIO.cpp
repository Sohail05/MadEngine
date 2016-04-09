#include "FileIO.h"

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

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
	return Text;
}


std::vector<float> LoadObj( char* Filepath ){

	string Buffer = "";
	std::vector<float> V;
	ifstream InputFile(Filepath , std::ios::in);

	if(InputFile.is_open()){
		while( getline( InputFile, Buffer ) ){
			if( Buffer.substr( 0 , 2 ) == "v " ){
				std::vector<std::string> vec = split(Buffer.substr(2 , Buffer.length() ) , ' ');
				V.push_back( stof(vec.at(0), 0 ) );
				V.push_back( stof(vec.at(1),0 ) );
				V.push_back( stof(vec.at(2),0 ) );
			}
		}
		InputFile.close();
	}else{
		cout  << "cannot open or file not found: " << Filepath;
		return V;
	}
	return V;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}
