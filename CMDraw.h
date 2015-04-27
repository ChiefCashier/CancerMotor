#pragma once

#include "glew.h"
#include "glm\glm.hpp"
#include <string>
#include <iostream>
#include "CMWindow.h"

// Examples
//CMDraw::CMDrawShapeRectangle(100, 100, 250, 250);
//CMDraw::CMDrawShapeCircle(100, 100, 50, 20);

class CMDraw
{
public:
	CMDraw() {};
	~CMDraw() {};

	static void CMDrawShapeRectangle(float posX, float posY, float width, float height)
	{
		GLint m_viewport[4];
		// Gets screen x, y, width, height
		glGetIntegerv(GL_VIEWPORT, m_viewport);

		float  _screenWidth = m_viewport[2];
		float _screenHeight = m_viewport[3];
		
		int _vertexCount = 4;
			
		static const GLfloat RECTANGLE_DATA[] =
		{
			// 1st
			CMDraw::ConvertX(posX, _screenWidth),			CMDraw::ConvertX(posY, _screenHeight),
			
			// 2nd
			CMDraw::ConvertX(posX + width, _screenWidth),	CMDraw::ConvertX(posY, _screenHeight),

			// 3rd
			CMDraw::ConvertX(posX + width, _screenWidth),	CMDraw::ConvertX(posY - height, _screenHeight),

			// 4th
			CMDraw::ConvertX(posX, _screenWidth),			CMDraw::ConvertX(posY - height, _screenHeight)
		};
		
		/*
		static const GLfloat VERTEX_DATA[] =
		{
			//1st vertex
			0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			0.0f, 0.0f,

			//2nd vertex
			1.0f, -0.0f,
			0.0f, 1.0f, 0.0f,
			1.0f, 0.0f,

			//3rd vertex
			1.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			1.0f, 1.0f,

			//4th vertex
			0.0f, 1.0f,
			1.0f, 0.0f, 1.0f,
			0.0f, 1.0f
		};
		*/
	};

	
	static void CMDrawShapeCircle(float posX, float posY, float size, int sides)
	{
		GLint m_viewport[4];
		// Gets screen x, y, width, height
		glGetIntegerv(GL_VIEWPORT, m_viewport);

		float  _screenWidth = m_viewport[2];
		float _screenHeight = m_viewport[3];

		static float* CIRCLE_DATA = new GLfloat[];
		
		for (int i = 0; i < 360; i += sides)
		{
			for (int j = 0; j < 256; j++)
			{
				CIRCLE_DATA[j] = posX + size * cos(i);
				CIRCLE_DATA[j + 1] = posY + size * sin(i);
			}
		}
	}
	// Conversion
	// (posX * 2) / _screenWidth - 1
	static float ConvertX(float x, float screenD)
	{
		return (x * 2) / screenD - 1;
	}
};

