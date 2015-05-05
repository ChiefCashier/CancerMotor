#pragma once
class Component
{
enum IDENTIFIER
	{
		RENDERABLE,
		TRANSFORMABLE
	};
public:

	Component(int ID);
	virtual ~Component();
	class GameObject;
	void AddParent(void* GO) { parent = (GameObject*)GO; };
	GameObject* GetParent() { return parent; };
	unsigned int componentId;

protected:

	GameObject* parent;
};

