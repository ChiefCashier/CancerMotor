#pragma once
#include "Component.h"
#include "Object.h"
#include <vector>

class Transformable : public Component
{
public:

	Transformable(int ID);
	~Transformable();

	void SetOrigin(float XPosition, float YPosition, float ZPosition)
	{
		position[0] = XPosition;
		position[1] = YPosition;
		position[2] = ZPosition;
	};
	float* GetOrigin()
	{
		return position;
	};
	void SetRotation(float xrotation, float yrotation, float zrotation)
	{
		rotation[0] = xrotation;
		rotation[1] = yrotation;
		rotation[2] = zrotation;
	};
	float* GetRotation()
	{
		return rotation;
	};

private:

	float position[3];
	float rotation[3];

};

