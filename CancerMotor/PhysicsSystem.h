#pragma once
#include "System.h"
#include "Physics.h"
#include "glm\common.hpp"
#include <vector>
class PhysicsSystem : public System
{
public:

	PhysicsSystem(float gravity);
	~PhysicsSystem();

	void AddPhysicsComponent(Physics* physComp);
	void Update(){ Update(deltaTime); };
	void Update(double deltaTime);

	double deltaTime;

private:

	void Collision(Physics* comp);
	void UpdateForces(Physics* comp);
	void UpdateSpeed(Physics* comp);
	
	int it;

	float gravity;

	std::vector<Physics*> physicsComponents;
	std::vector<Physics*>::iterator PCIT;
	std::vector<Physics*>::iterator PCIT2;
};

