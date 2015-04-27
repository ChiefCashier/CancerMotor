#pragma once
#include "FreeImage.h"
#include "glew.h"
#include "Resource.h"

	class Image : public Resource
	{
	public:
		Image() : Resource(""){};
		Image(char* name);
		~Image();
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
