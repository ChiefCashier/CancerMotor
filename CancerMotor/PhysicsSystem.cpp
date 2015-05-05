#include "PhysicsSystem.h"
#include "GameObject.h"
#include "Transformable.h"
#include <math.h>

PhysicsSystem::PhysicsSystem(float grav)
{
	gravity = grav;
	deltaTime = 0.016;
	fo = 0;
	to = 0;
	it = 0;
}

void PhysicsSystem::Update(double deltaT)
{
	PCIT = physicsComponents.begin();
	while (PCIT != physicsComponents.end())
	{
		if ((*PCIT)->GetParent() == nullptr)
			PCIT++;
		else
		{
			UpdateForces((*PCIT));

			Collision((*PCIT));

			PCIT++; 
		}
	}
	PCIT = physicsComponents.begin();
	while (PCIT != physicsComponents.end())
	{
		if ((*PCIT)->GetParent() == nullptr)
			PCIT++;
		else
		{
			if (!(*PCIT)->collision)
			{
				UpdateSpeed((*PCIT));
			}
			else
			{
				(*PCIT)->collision = false;
			}
			PCIT++;
		}
	}



}

void PhysicsSystem::UpdateSpeed(Physics* comp)
{

	GameObject* GO = (GameObject*)comp->GetParent();

	if (GO->GetComponent<Transformable>()->GetOrigin()[1] + comp->GetSpeed().y * deltaTime > 80)
	{
		comp->SetSpeed(Vector3<float>(comp->GetSpeed().x, -std::abs(comp->GetSpeed().y * comp->GetElasticity()), comp->GetSpeed().z));
		comp->SetForces(Vector3<float>(comp->GetForces().x, comp->GetForces().y - gravity * comp->GetMass(), comp->GetForces().z));
	}

	if (GO->GetComponent<Transformable>()->GetOrigin()[1] + comp->GetSpeed().y * deltaTime < -80)
	{
		comp->SetSpeed(Vector3<float>(comp->GetSpeed().x, std::abs(comp->GetSpeed().y * comp->GetElasticity()), comp->GetSpeed().z));
		comp->SetForces(Vector3<float>(comp->GetForces().x, comp->GetForces().y + gravity * comp->GetMass(), comp->GetForces().z));
	}

	if (GO->GetComponent<Transformable>()->GetOrigin()[0] + comp->GetSpeed().x * deltaTime < -120)
	{
		comp->SetSpeed(Vector3<float>(std::abs(comp->GetSpeed().x * comp->GetElasticity()), comp->GetSpeed().y, comp->GetSpeed().z));

	}

	if (GO->GetComponent<Transformable>()->GetOrigin()[0] + comp->GetSpeed().x * deltaTime >  120)
	{
		comp->SetSpeed(Vector3<float>(-std::abs(comp->GetSpeed().x * comp->GetElasticity()), comp->GetSpeed().y, comp->GetSpeed().z));

	}

	if (GO->GetComponent<Transformable>()->GetOrigin()[2] + comp->GetSpeed().z * deltaTime < -400)
	{
		comp->SetSpeed(Vector3<float>(comp->GetSpeed().x, comp->GetSpeed().y, std::abs(comp->GetSpeed().z * comp->GetElasticity())));

	}

	if (GO->GetComponent<Transformable>()->GetOrigin()[2] + comp->GetSpeed().z * deltaTime > -100)
	{
		comp->SetSpeed(Vector3<float>(comp->GetSpeed().x, comp->GetSpeed().y, -std::abs(comp->GetSpeed().z * comp->GetElasticity())));
	}



	comp->SetSpeed(Vector3<float>(
		comp->GetSpeed().x + (comp->GetForces().x * deltaTime / comp->GetMass() ),	//X
		comp->GetSpeed().y + (comp->GetForces().y * deltaTime / comp->GetMass() ),	//Y
		comp->GetSpeed().z + (comp->GetForces().z * deltaTime / comp->GetMass() )	//Z
		));

	comp->SetForces(Vector3<float>(
		0.0f,
		0.0f,
		0.0f
		));

	GO->GetComponent<Transformable>()->SetOrigin(
		GO->GetComponent<Transformable>()->GetOrigin()[0] + comp->GetSpeed().x * deltaTime,
		GO->GetComponent<Transformable>()->GetOrigin()[1] + comp->GetSpeed().y * deltaTime,
		GO->GetComponent<Transformable>()->GetOrigin()[2] + comp->GetSpeed().z * deltaTime
		);
	GO->GetComponent<Transformable>()->SetRotation(
		GO->GetComponent<Transformable>()->GetRotation()[0] + comp->GetAngularSpeed().x * deltaTime,
		GO->GetComponent<Transformable>()->GetRotation()[1] + comp->GetAngularSpeed().y * deltaTime,
		GO->GetComponent<Transformable>()->GetRotation()[2] + comp->GetAngularSpeed().z * deltaTime
		);
}

void PhysicsSystem::UpdateForces(Physics* comp)
{
	comp->SetForces(Vector3<float>(
		comp->GetForces().x,
		comp->GetForces().y - gravity * comp->GetMass(),
		comp->GetForces().z
		));
	//if (comp->GetSpeed().x < 0.3 && comp->GetSpeed().y < 0.3 && comp->GetSpeed().z < 0.3)
	//	comp->SetSpeed(Vector3<float>(0, 0, 0));
}

void PhysicsSystem::UpdateCollisionMap(Physics* comp)
{
	if (CollisionMap.find(comp->componentId) != CollisionMap.end())
	{
		;
		PCIT2 = physicsComponents.begin();
		GameObject* GO = (GameObject*)comp->GetParent();
		GameObject* GO2 = (GameObject*)(*PCIT2)->GetParent();
		float deltax = GO->GetComponent<Transformable>()->GetOrigin()[0] - GO2->GetComponent<Transformable>()->GetOrigin()[0] + comp->GetSpeed().x * deltaTime + (*PCIT2)->GetSpeed().x * deltaTime;
		float deltay = GO->GetComponent<Transformable>()->GetOrigin()[1] - GO2->GetComponent<Transformable>()->GetOrigin()[1] + comp->GetSpeed().y * deltaTime + (*PCIT2)->GetSpeed().y * deltaTime;
		float deltaz = GO->GetComponent<Transformable>()->GetOrigin()[2] - GO2->GetComponent<Transformable>()->GetOrigin()[2] + comp->GetSpeed().z * deltaTime + (*PCIT2)->GetSpeed().z * deltaTime;
	
	}
}

void PhysicsSystem::Collision(Physics* comp)
{
	GameObject* GO = (GameObject*)comp->GetParent();

	PCIT2 = physicsComponents.begin();

	while (PCIT2 != physicsComponents.end())
	{
		if ((*PCIT2)->GetParent() == nullptr)
			PCIT2++;
		else if ((*PCIT2)->componentId == comp->componentId)
			PCIT2++;
		else
		{
			GameObject* GO2 = (GameObject*)(*PCIT2)->GetParent();

			float deltax = GO->GetComponent<Transformable>()->GetOrigin()[0] - GO2->GetComponent<Transformable>()->GetOrigin()[0] + comp->GetSpeed().x * deltaTime + (*PCIT2)->GetSpeed().x * deltaTime;
			float deltay = GO->GetComponent<Transformable>()->GetOrigin()[1] - GO2->GetComponent<Transformable>()->GetOrigin()[1] + comp->GetSpeed().y * deltaTime + (*PCIT2)->GetSpeed().y * deltaTime;
			float deltaz = GO->GetComponent<Transformable>()->GetOrigin()[2] - GO2->GetComponent<Transformable>()->GetOrigin()[2] + comp->GetSpeed().z * deltaTime + (*PCIT2)->GetSpeed().z * deltaTime;
			
			float deltax2 = GO->GetComponent<Transformable>()->GetOrigin()[0] - GO2->GetComponent<Transformable>()->GetOrigin()[0] + comp->GetSpeed().x * deltaTime * 2 + (*PCIT2)->GetSpeed().x * deltaTime * 2;
			float deltay2 = GO->GetComponent<Transformable>()->GetOrigin()[1] - GO2->GetComponent<Transformable>()->GetOrigin()[1] + comp->GetSpeed().y * deltaTime * 2 + (*PCIT2)->GetSpeed().y * deltaTime * 2;
			float deltaz2 = GO->GetComponent<Transformable>()->GetOrigin()[2] - GO2->GetComponent<Transformable>()->GetOrigin()[2] + comp->GetSpeed().z * deltaTime * 2 + (*PCIT2)->GetSpeed().z * deltaTime * 2;

			//if (std::cbrt(deltax2 * deltax2 + deltay2 * deltay2 + deltaz2 * deltaz2) > 15)
			{
				
			}
			if (std::cbrt(std::pow(deltax, 2) + std::pow(deltay, 2) + std::pow(deltaz,2)) <= 15)
			{
				
				std::cout << "collision" << std::endl;
				Vector3<float> asd(GO->GetComponent<Transformable>()->GetOrigin()[0], GO->GetComponent<Transformable>()->GetOrigin()[1], GO->GetComponent<Transformable>()->GetOrigin()[2]);

				Vector3<float> asd2(GO2->GetComponent<Transformable>()->GetOrigin()[0], GO2->GetComponent<Transformable>()->GetOrigin()[1], GO2->GetComponent<Transformable>()->GetOrigin()[2]);

			
				float angle = atan((asd.x - asd2.x) / (asd.y - asd2.y));
				if (abs(asd.y - asd2.y) < 1)
					if (asd.y - asd2.y < 0)
						angle = 0;
					else
						angle = 3.14;

				if (abs(asd.x - asd2.x) < 0.5)
					if (asd.x - asd2.x < 0)
						angle = 3.14 / 2;
					else
						angle = 3.14 / 4;

				//GO->GetComponent<Transformable>()->SetOrigin(
				//	GO->GetComponent<Transformable>()->GetOrigin()[0] - 50 * sin(angle)* deltaTime,
				//	GO->GetComponent<Transformable>()->GetOrigin()[1] - 50 * cos(angle)* deltaTime,
				//	GO->GetComponent<Transformable>()->GetOrigin()[2]
				//	);

				//GO2->GetComponent<Transformable>()->SetOrigin(
				//	GO2->GetComponent<Transformable>()->GetOrigin()[0] - 50 * sin(angle + 3.141)* deltaTime,
				//	GO2->GetComponent<Transformable>()->GetOrigin()[1] - 50 * cos(angle + 3.141)* deltaTime,
				//	GO2->GetComponent<Transformable>()->GetOrigin()[2]
				//	);


				

				float AbN = comp->GetSpeed().x * cos(angle) + comp->GetSpeed().y * sin(angle);
				float AbT = comp->GetSpeed().x * -sin(angle) + comp->GetSpeed().y * cos(angle);
				float BbN = (*PCIT2)->GetSpeed().x * cos(angle) + (*PCIT2)->GetSpeed().y * sin(angle);
				float BbT = (*PCIT2)->GetSpeed().x * -sin(angle) + (*PCIT2)->GetSpeed().y * cos(angle);

				float AaN = ((comp->GetMass() - comp->GetElasticity() * (*PCIT2)->GetMass()) / (comp->GetMass() + (*PCIT2)->GetMass())) * AbN;
				AaN += (((1 + comp->GetElasticity()) * (*PCIT2)->GetMass()) / (comp->GetMass() + (*PCIT2)->GetMass())) * BbN;
				float BaN = ((comp->GetMass() - (*PCIT2)->GetElasticity() * (*PCIT2)->GetMass()) / (comp->GetMass() + (*PCIT2)->GetMass())) * BbN;
				BaN += (((1 + comp->GetElasticity()) * (*PCIT2)->GetMass()) / (comp->GetMass() + (*PCIT2)->GetMass())) * AbN;

				comp->SetSpeed(Vector3<float>(AaN * cos(angle) + AbT * sin(-angle), AaN * sin(angle) + AbT * cos(angle), comp->GetSpeed().z));
				(*PCIT2)->SetSpeed(Vector3<float>(BaN * cos(angle) + BbT * sin(-angle), BaN * sin(angle) + BbT * cos(angle), (*PCIT2)->GetSpeed().z));
				//comp->SetForces(Vector3<float>(comp->GetForces().x, comp->GetForces().y + gravity * comp->GetMass(), comp->GetForces().z));
				UpdateSpeed(comp);
				//UpdateSpeed((*PCIT2));
				comp->collision = true;
				//(*PCIT2)->collision = true;

			}
			PCIT2++;
		}
			
	}

}

void PhysicsSystem::AddPhysicsComponent(Physics* physComp)
{
	physicsComponents.push_back(physComp);
}