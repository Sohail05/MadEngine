#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "FileIO.h"

//Todo: Make Shaders Globaly accessble by all Mesh Components to avoid multiple same shader to be compiled

class Shader {

public:

	std::string name;

	std::string VertexShaderSource;
	std::string FragmentShaderSource;
	GLuint shaderProgram;

	Shader(){

		VertexShaderSource = "#version 120\n"
			"uniform vec3 Position;"
			"void main () {"
			" gl_Position = gl_ModelViewProjectionMatrix * (gl_Vertex + vec4( Position , 0 ))  ;"
			"}";

		FragmentShaderSource = "#version 120\n"
			"uniform vec4 color;"
			"void main () {"
			" gl_FragColor = color;"
			"}";

		Compile();
	}

	Shader(char* VS , char* FS ){


		VertexShaderSource = LoadFile(VS);
		FragmentShaderSource = LoadFile(FS);

		Compile();

	}

	void Compile(){

		GLint Result = GL_FALSE;
		int InfoLogLength;

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const char *v_str = VertexShaderSource.c_str();
		glShaderSource(vertexShader, 1, &v_str , NULL);
		glCompileShader(vertexShader);

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if ( InfoLogLength > 0 ){
			std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
			glGetShaderInfoLog(vertexShader, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			printf("\n%s\n", &VertexShaderErrorMessage[0]);
		}



		const char *f_str = FragmentShaderSource.c_str();
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &f_str ,  NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if ( InfoLogLength > 0 ){
			std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
			glGetShaderInfoLog(fragmentShader, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
			printf("\n%s\n", &FragmentShaderErrorMessage[0]);
		}




		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

	}




private:


};

#endif