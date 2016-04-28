#include "Renderer.h"
#include "../Core/Mesh.h"

Renderer::Renderer(){

	//shader = Shader("C:/Repositories/madengine/MadEngine/bin/default.vertex" , "C:/Repositories/madengine/MadEngine/bin/default.fragment"  );
	shader = Shader();
	Mode = RenderMode::kNone;
}

Renderer::~Renderer(){}

void Renderer::Draw(){

	// Activate Vertex Buffer
	glEnableClientState( GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, mesh.vertex.data() );

	//Use Shader
	glUseProgram(shader.shaderProgram);

	//Todo: Creat a struct or class to hold all IDs
	//Design:  Should only need to do this once

	GLuint PositionID = glGetUniformLocation(shader.shaderProgram, "Position");
	GLfloat Vec3[3] = {0,0,0};
	glUniform3fv(PositionID, 1, Vec3);

	GLuint ColorID = glGetUniformLocation(shader.shaderProgram, "color");
	//Ugly: is there a cleaner way ?
	glUniform4f(ColorID, color.red , color.green , color.blue , color.alpha );

	//Draw Mesh with Indices
	//Design: Should Thing about implementing VBOs in a VAB
	//TTA: Should I also Generate a buffer and leave the vertices in there ?
	glDrawElements(Mode, mesh.indices.size() , GL_UNSIGNED_BYTE, mesh.indices.data() );

	//Disable Shader
	glUseProgram(0);

	//Disable Buffer
	glDisableClientState(GL_VERTEX_ARRAY);
}
