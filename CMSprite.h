#pragma once
#include "CMImage.h"
#include <string>

namespace CML
{
	class CMSprite
	{
	public:

		CMSprite();
		CMSprite(float, float, float, float);
		CMSprite(float, float, float, float, char*);
		CMSprite(float, float, float, float, CMImage);
		~CMSprite();

		float GetX();
		void SetX(float);

		float GetY();
		void SetY(float);

		float GetWidht();
		void SetWidht(float);

		float GetHeight();
		void SetHeight(float);

		float* GetColor();
		float GetColorRed();
		float GetColorGreen(); 
		float GetColorBlue();
		void SetColor(float, float, float, float);

		CMImage GetImage();
		void SetImage(char*);

		float GetTexturePositionX();
		void SetTexturePositionX(float);

		float GetTexturePositionY();
		void SetTexturePositionY(float);

		float GetTextureWidht();
		void SetTextureWidht(float);

		float GetTextureHeight();
		void SetTextureHeight(float);


	private:

		float _xPosition, _yPosition, _widht, _height;
		float _colorRed, _colorGreen, _colorBlue, _alphaChannel;
		float _texturePositionX, _texturePositionY;
		float _textureWidht, _textureHeight;
		CMImage _image;

	};
}