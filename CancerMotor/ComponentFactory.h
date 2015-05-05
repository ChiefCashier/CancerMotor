#pragma once
#include "Renderable.h"
#include "Transformable.h"
#include "PhysicsSystem.h"
#include "ResourceManager.h"
#include "ObjectLoader.h"
static unsigned int ID = 0;
class ComponentFactory
{
public:
	static Renderable* CreateRenderable(char* object, char* texture)
	{
		ObjectLoader OLO;

		Renderable* temp = new Renderable(ID);
		ID++;
		temp->init(OLO.LoadObject(object));
		temp->SetTexture(ResourceManager::createResource<Image>(texture));

		return temp;
	};
	static Transformable* CreateTransformable()
	{
		Transformable* temp = new Transformable(ID);
		ID++;
		temp->SetOrigin(0.f,0.f,0.f);
		temp->SetRotation(0.f,0.f,0.f);

		return temp;
	};
	static Transformable* CreateTransformable(float x, float y, float z, float rx, float ry, float rz)
	{
		Transformable* temp = new Transformable(ID);
		ID++;
		temp->SetOrigin(x, y, z);
		temp->SetRotation(rx, ry, rz);

		return temp;
	};
	static Physics* CreatePhysicsComponent(PhysicsSystem* asd)
	{
		Physics* temp = new Physics(ID);
		ID++;
		temp->SetElasticity(1.0);
		temp->SetForces(Vector3<float>(0.0f, 0.0f, 0.0f));
		temp->SetMass(10);
		temp->SetSpeed(Vector3<float>(0.0f, 0.0f, 0.0f));
		temp->SetAngularSpeed(Vector3<float>(0.0f, 0.0f, 0.0f));
		asd->AddPhysicsComponent(temp);
		return temp;
	};
private:

};
