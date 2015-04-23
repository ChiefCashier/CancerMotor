#pragma once
#include "Component.h"
#include "Vector3.h"

class Physics : public Component
{
public:

	Physics(int ID);
	~Physics();

	float GetMass();
	float GetElasticity();
	Vector3<float> GetSpeed();
	Vector3<float> GetForces();
	
	void SetMass(float m);
	void SetElasticity(float e);
	void SetSpeed(Vector3<float> s);
	void SetForces(Vector3<float> f);

	bool collision;

private:

	float mass;
	float elasticity;

	Vector3<float> speed;
	Vector3<float> forces;

	bool collisionable;

	//other values may be added

};

