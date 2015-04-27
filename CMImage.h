#pragma once
#include "FreeImage.h"
#include "glew.h"
#include "Resource.h"
namespace CML
{
	class CMImage : public Resource
	{
	public:
		CMImage() : Resource(""){};
		CMImage(char* name);
		~CMImage();
		size_t getWidth();
		size_t getHeight();
		char* getName();
		void* getPixelData();
		GLuint getImageFormat();
		GLuint getTextureId();
		FIBITMAP* getBITMAP();


	private:

		char* _name;
		size_t _width;
		size_t _height;
		void* _pixelData;
		GLuint _imageFormat;
		GLuint _textureId;


	};

}