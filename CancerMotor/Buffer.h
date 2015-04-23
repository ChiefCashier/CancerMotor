#pragma once
#ifndef BUFFER_H
#define BUFFER_H
#include "glew.h"
class Buffer
{
public:
	Buffer(){};

	Buffer(GLuint buffer)//GL_ELEMENT_ARRAY_BUFFER OR GL_ARRAY_BUFFER
	{
		//bufferPtr[0] = CreateBuffer(buffer);
	};

	GLuint GetBuffer()
	{
		return bufferPtr;
	};

	~Buffer()
	{
		//delete bufferPtr;
	};

	GLuint CreateIndexBuffer(GLuint* indices , int indiceSize)//GL_ELEMENT_ARRAY_BUFFER OR GL_ARRAY_BUFFER
	{
		glGenBuffers(1, &bufferPtr);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferPtr);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indiceSize, indices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0u);
		return bufferPtr;
	};
	GLuint CreateVertexBuffer(GLfloat* vertices, int indiceSize)//GL_ELEMENT_ARRAY_BUFFER OR GL_ARRAY_BUFFER
	{
		glGenBuffers(1, &bufferPtr);
		glBindBuffer(GL_ARRAY_BUFFER, bufferPtr);
		glBufferData(GL_ARRAY_BUFFER, indiceSize * sizeof(GLfloat)* 8, vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0u);
		return bufferPtr;
	};

private:

	GLuint bufferPtr;

};
#endif