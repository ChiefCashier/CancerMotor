#pragma once
#include "glew.h"
class Object
{
public:

	Object();
	~Object();

	int _indexSize;
	int _vertexSize;

	GLfloat* _vertices;
	GLuint* _indices;

	GLuint vertexBuffer;
	GLuint indexBuffer;
	GLuint vertexArray;

private:

};

