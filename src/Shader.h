#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <string>

class Shader {

public:

	char* VertexShaderSource;
	char* FragmentShaderSource;
	GLuint shaderProgram;

	Shader(){
	
		VertexShaderSource = "#version 120\n"
"uniform vec3 Position;"
"void main () {"
" gl_Position = gl_ModelViewProjectionMatrix * (gl_Vertex + vec4( Position , 0 ))  ;"
"}";
	
//layout(location = 0) in vec3 vertexPosition_modelspace;


		FragmentShaderSource = "#version 120\n"
"uniform vec4 color;"
"void main () {"
" gl_FragColor = color;"
"}";
	
		Compile();
	}

	void Compile(){
	
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &VertexShaderSource , NULL);
		glCompileShader(vertexShader);


		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &FragmentShaderSource ,  NULL);
		glCompileShader(fragmentShader);


		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		
	}




private:


};
#endif