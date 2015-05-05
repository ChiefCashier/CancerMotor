#pragma once
#include "glew.h"
#include <list>
class GraphicContext
{
public:
	struct drawable{
		GLfloat vertices;
		GLuint indices;
		GLuint textureIndex;
	};
	
	GraphicContext();
	~GraphicContext();
	void BeginDraw();
	void EndDraw();
	void Draw();
private:
	std::list<drawable> drawables;
};

