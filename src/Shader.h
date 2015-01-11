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

	std::string vertex_shader_source;
	std::string fragment_shaders_source;
	GLuint shaderProgram;

	Shader(){

		vertex_shader_source = "#version 120\n"
			"uniform vec3 Position;"
			"void main () {"
			" gl_Position = gl_ModelViewProjectionMatrix * (gl_Vertex + vec4( Position , 0 ))  ;"
			"}";

		fragment_shaders_source = "#version 120\n"
			"uniform vec4 color;"
			"void main () {"
			" gl_FragColor = color;"
			"}";

		Compile();
	}

	Shader(char* VS , char* FS ){


		vertex_shader_source = LoadFile(VS);
		fragment_shaders_source = LoadFile(FS);

		Compile();

	}

	void Compile(){

		//Shader Debugging code from http://www.opengl-tutorial.org/
		//WTFPL Public 

		GLint Result = GL_FALSE;
		int InfoLogLength;

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const char *v_str = vertex_shader_source.c_str();
		glShaderSource(vertexShader, 1, &v_str , NULL);
		glCompileShader(vertexShader);

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if ( InfoLogLength > 0 ){
			std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
			glGetShaderInfoLog(vertexShader, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			printf("\n%s\n", &VertexShaderErrorMessage[0]);
		}



		const char *f_str = fragment_shaders_source.c_str();
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