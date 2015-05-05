#pragma once
#include "Object.h"
#include <vector>
#include "glm\common.hpp"
#include "glew.h"

class ObjectLoader
{
public:
	ObjectLoader();
	~ObjectLoader();
	Object* LoadObject(char* GameObjectName);

private:

	GLuint vertexBuffer;
	GLuint indexBuffer;
	GLuint vertexArray;
};

