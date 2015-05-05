#include "CMSprite.h"

namespace CML
{
	CMSprite::CMSprite()
	{
		_xPosition = 0.0f;
		_yPosition = 0.0f;
		_widht = 200.0f;
		_height = 300.0f;

		_colorRed = { 0.0f }, _colorGreen = { 0.0f }, _colorBlue = { 0.0f }, _alphaChannel = { 1.0f };

		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_image = nullptr;
	}

	CMSprite::CMSprite(float xPosition, float yPosition, float widht, float height)
	{
		_xPosition = xPosition;
		_yPosition = yPosition;
		_widht = widht;
		_height = height;

		_colorRed = { 0.0f }, _colorGreen = { 0.0f }, _colorBlue = { 0.0f }, _alphaChannel = { 1.0f };

		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_image = nullptr;
		_textureHeight = 0;
		_textureWidht = 0;
	}

	CMSprite::CMSprite(float xPosition, float yPosition, float widht, float height, char* imageLocation)
	{
		_xPosition = xPosition;
		_yPosition = yPosition;
		_widht = widht;
		_height = height;

		_colorRed = { 0.0f }, _colorGreen = { 0.0f }, _colorBlue = { 0.0f }, _alphaChannel = { 1.0f };

		_image = CML::CMImage::CMImage(imageLocation);

		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_textureHeight = _image.getHeight();
		_textureWidht = _image.getWidth();

	}
	CMSprite::CMSprite(float xPosition, float yPosition, float widht, float height, CMImage image)
	{
		_xPosition = xPosition;
		_yPosition = yPosition;
		_widht = widht;
		_height = height;

		_colorRed = { 0.0f }, _colorGreen = { 0.0f }, _colorBlue = { 0.0f }, _alphaChannel = { 1.0f };

		_image = image;

		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_textureHeight = _image.getHeight();
		_textureWidht = _image.getWidth();
	}

	CMSprite::~CMSprite()
	{ 

	}

	float CMSprite::GetX()
	{
		return _xPosition;
	}

	void CMSprite::SetX(float x)
	{
		_xPosition = x;
	}

	float CMSprite::GetY()
	{
		return _yPosition;
	}

	void CMSprite::SetY(float y)
	{
		_yPosition = y;
	}

	float CMSprite::GetWidht()
	{
		return _widht;
	}

	void CMSprite::SetWidht(float widht)
	{
		_widht = widht;
	}

	float CMSprite::GetHeight()
	{
		return _height;
	}

	void CMSprite::SetHeight(float height)
	{
		_height = height;
	}

	float* CMSprite::GetColor()
	{
		float colors[4] = { _colorRed, _colorGreen, _colorBlue, _alphaChannel };

		return colors;
	}

	float CMSprite::GetColorRed()
	{
		return _colorRed;
	}

	float CMSprite::GetColorGreen()
	{
		return _colorGreen;
	}

	float CMSprite::GetColorBlue()
	{
		return _colorBlue;
	}

	void CMSprite::SetColor(float red, float green, float blue, float alpha)
	{
		_colorRed = red / 255, _colorGreen = green / 255, _colorBlue = blue / 255, _alphaChannel = alpha / 255;
	}

	CMImage CMSprite::GetImage()
	{
		return _image;
	}

	void CMSprite::SetImage(char* imageLocation)
	{
		_image = CML::CMImage::CMImage(imageLocation);
	}
	float CMSprite::GetTexturePositionX()
	{
		return _texturePositionX;
	}

	void CMSprite::SetTexturePositionX(float texPosX)
	{
		_texturePositionX = texPosX;
	}

	float CMSprite::GetTexturePositionY()
	{
		return _texturePositionY;
	}

	void CMSprite::SetTexturePositionY(float texPosY)
	{
		_texturePositionY = texPosY;
	}

	float CMSprite::GetTextureHeight()
	{
		return _textureHeight;
	}

	void CMSprite::SetTextureHeight(float texHeight)
	{
		_textureHeight = texHeight;
	}

	float CMSprite::GetTextureWidht()
	{
		return _textureWidht;
	}

	void CMSprite::SetTextureWidht(float texWidht)
	{
		_textureWidht = texWidht;
	}
}