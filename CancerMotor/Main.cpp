#include "Window.h"
#include "glew.h"
#include "ResourceManager.h"
#include "RenderingSystem.h"
#include "Input.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderable.h"
#include "Transformable.h"
#include "ObjectLoader.h"
#include "ComponentFactory.h"
#include "MemoryManager.h"
#include "PhysicsSystem.h"
#include "Vector3.h"
#include "SystemManager.h"
#include <vector>

RenderingContext* rendContext;

int main()
{
	Window window(0, L"asd", 800, 600);
	window.ShowAWindow();
	rendContext = new RenderingContext(&window);
	SystemManager* SM = new SystemManager();


	RenderingSystem* RS = new RenderingSystem(rendContext);
	PhysicsSystem* PS = new PhysicsSystem(98.1);

	SM->AddSystem(RS);
	SM->AddSystem(PS);

	LARGE_INTEGER StartingTime, EndingTime, ElapsedMilliseconds;
	LARGE_INTEGER Frequency;

	GameObject* obj = new GameObject("pallo.obj");

	Renderable* rendComp = ComponentFactory::CreateRenderable("pallo.obj", "sample.png");

	Physics* physz1 = ComponentFactory::CreatePhysicsComponent(PS);

	Transformable* transComp = ComponentFactory::CreateTransformable();


	std::vector<GameObject*> GOS;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 50; j++)
		{	
		GameObject* objs = new GameObject("pallo.obj");
		Renderable* rendComps = ComponentFactory::CreateRenderable("pallo.obj", "sample.png");
		//Physics* physzs = ComponentFactory::CreatePhysicsComponent(PS);
		//Transformable* transComps = ComponentFactory::CreateTransformable();
		objs->AddComponent(rendComps);
		//objs->AddComponent(transComps);
		//objs->AddComponent(physzs);
		GOS.push_back(objs);
		}		

	}
	

	physz1->SetElasticity(1.0);


	obj->AddComponent(rendComp);
	obj->AddComponent(transComp);
	obj->AddComponent(physz1);
	transComp->SetOrigin(0, 100, -200.0f);

	RS->Draw(obj);

	for (int i = 0; i < 10; i++)
	{
		RS->Draw(GOS.at(i));
	}


	int houboxu = 0;
	while (true)
	{
		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&StartingTime);


		if (Input::isKeyPressed(Input::L))
			std::cout << "X: " << transComp->GetOrigin()[0] << " Y: " << transComp->GetOrigin()[1] << " Z: " << transComp->GetOrigin()[2] << std::endl;

		window.WindowMessageCheck();

		
		
		if (Input::isKeyPressed(Input::W))
			physz1->SetForces(Vector3<float>(0.0f, 4000.0f, 0.0f));
		if (Input::isKeyPressed(Input::S))
			physz1->SetForces(Vector3<float>(0.0f, -4000.0f, 0.0f));
		if (Input::isKeyPressed(Input::D))
			physz1->SetForces(Vector3<float>(4000.0f, 0.0f, 0.0f));
		if (Input::isKeyPressed(Input::A))
			physz1->SetForces(Vector3<float>(-4000.0f, 0.0f, 0.0f));
		if (Input::isKeyPressed(Input::Up))
			physz1->SetForces(Vector3<float>(0.0f, 0.0f, -4000.0f));
		if (Input::isKeyPressed(Input::Down))
			physz1->SetForces(Vector3<float>(0.0f, 0.0f, 4000.0f));

		if (Input::isKeyPressed(Input::Left))
			physz1->SetAngularSpeed(Vector3<float>(0.0f, 0.0f, 40.0f));
		if (Input::isKeyPressed(Input::Right))
			physz1->SetAngularSpeed(Vector3<float>(0.0f, 0.0f, -40.0f));


		if (Input::isKeyPressed(Input::Escape))
			break;

		if (Input::isKeyPressed(Input::Space))
		{

			GOS.at(houboxu)->AddComponent(ComponentFactory::CreatePhysicsComponent(PS));
			GOS.at(houboxu)->AddComponent(ComponentFactory::CreateTransformable());
			GOS.at(houboxu)->GetComponent<Transformable>()->SetOrigin(0, 0, -200.0f);
			RS->Draw(GOS.at(houboxu));
			houboxu++;
		}

		if (Input::isKeyPressed(Input::Y))
		{
			PS->SetGravity(0);
		}
		if (Input::isKeyPressed(Input::U))
		{
			PS->SetGravity(98.1);
		}

		if (Input::isKeyPressed(Input::L))
		{
			float hax = (PS->deltaTime * 0.90);
			PS->deltaTime = hax;
		}
		if (Input::isKeyPressed(Input::T))
		{
			PS->deltaTime = PS->deltaTime * 1.1;
		}

		if (Input::isKeyPressed(Input::R))
		{
			float hax = (PS->deltaTime * -1);
			PS->deltaTime = hax;
		}
		if (Input::isKeyPressed(Input::E))
		{
			physz1->SetElasticity(physz1->GetElasticity() * 0.9);
		}
		if (Input::isKeyPressed(Input::Q))
		{
			physz1->SetElasticity(physz1->GetElasticity() * 1.1);
		}

		SM->UpdateSystems();

		QueryPerformanceCounter(&EndingTime);
		ElapsedMilliseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

		ElapsedMilliseconds.QuadPart *= 1000000;
		double as = ElapsedMilliseconds.QuadPart /= Frequency.QuadPart;
		//PS->deltaTime = (as / 1000000);
		std::cout << " deltat: " << as/1000000 << " s"<<std::endl;
	}
	
	return 0;
}