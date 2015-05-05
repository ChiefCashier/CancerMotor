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

RenderingContext* rendContext;

int main()
{
	Window window(0, L"asd", 800, 600);
	window.ShowAWindow();
	rendContext = new RenderingContext(&window);
	SystemManager* SM = new SystemManager();


	RenderingSystem* RS = new RenderingSystem(rendContext);
	PhysicsSystem* PS = new PhysicsSystem(90.81);

	SM->AddSystem(RS);
	SM->AddSystem(PS);

	LARGE_INTEGER StartingTime, EndingTime, ElapsedMilliseconds;
	LARGE_INTEGER Frequency;

	GameObject* obj = new GameObject("BOX_X.obj");
	GameObject* obj2 = new GameObject("pallo.obj");
	GameObject* obj3 = new GameObject("pallo.obj");

	Renderable* rendComp = ComponentFactory::CreateRenderable("pallo.obj", "sample.png");
	Renderable* rendComp2 = ComponentFactory::CreateRenderable("pallo.obj", "tribaltatuointi.png");
	Renderable* rendComp3 = ComponentFactory::CreateRenderable("pallo.obj", "tribaltatuointi.png");

	Physics* physz = ComponentFactory::CreatePhysicsComponent(PS);
	Physics* physz2 = ComponentFactory::CreatePhysicsComponent(PS);
	Physics* physz3 = ComponentFactory::CreatePhysicsComponent(PS);

	Transformable* transComp = ComponentFactory::CreateTransformable();
	Transformable* transComp2 = ComponentFactory::CreateTransformable();
	Transformable* transComp3 = ComponentFactory::CreateTransformable();

	
	physz2->SetMass(5);
	physz->SetMass(2.5);
	physz->SetElasticity(0.6);

	obj->AddComponent(rendComp);
	obj->AddComponent(transComp);
	obj->AddComponent(physz);

	obj2->AddComponent(rendComp2);
	obj2->AddComponent(transComp2);
	obj2->AddComponent(physz2);

	obj3->AddComponent(rendComp3);
	obj3->AddComponent(transComp3);
	obj3->AddComponent(physz3);

	transComp3->SetOrigin(-100, 50, -200.0f);
	transComp2->SetOrigin(100, 50, -200.0f);
	transComp->SetOrigin(0, 0, -200.0f);


	RS->Draw(obj);
	RS->Draw(obj2);
	RS->Draw(obj3);

	while (true)
	{
		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&StartingTime);


		if (Input::isKeyPressed(Input::L))
			std::cout << "X: " << transComp->GetOrigin()[0] << " Y: " << transComp->GetOrigin()[1] << " Z: " << transComp->GetOrigin()[2] << std::endl;

		window.WindowMessageCheck();

		
		
		if (Input::isKeyPressed(Input::W))
			physz->SetForces(Vector3<float>(0.0f, 4000.0f, 0.0f));
		if (Input::isKeyPressed(Input::S))
			physz->SetForces(Vector3<float>(0.0f, -4000.0f, 0.0f));
		if (Input::isKeyPressed(Input::D))
			physz->SetForces(Vector3<float>(4000.0f, 0.0f, 0.0f));
		if (Input::isKeyPressed(Input::A))
			physz->SetForces(Vector3<float>(-4000.0f, 0.0f, 0.0f));
		if (Input::isKeyPressed(Input::Up))
			physz->SetForces(Vector3<float>(0.0f, 0.0f, -4000.0f));
		if (Input::isKeyPressed(Input::Down))
			physz->SetForces(Vector3<float>(0.0f, 0.0f, 4000.0f));


		//float al = ((transComp->GetOrigin()[0] - transComp2->GetOrigin()[0])*(transComp->GetOrigin()[0] - transComp2->GetOrigin()[0]));
		//float ad = ((transComp->GetOrigin()[1] - transComp2->GetOrigin()[1])*(transComp->GetOrigin()[1] - transComp2->GetOrigin()[1]));
		//if (sqrt(al + ad) < 50)
		//{
		//	std::cout << "Collision!"<< std::endl;
		//}
			
		if (Input::isKeyPressed(Input::Escape))
			break;

		

		

		if (Input::isKeyPressed(Input::Space))
			physz->collision = true;

		
		

		SM->UpdateSystems();

		QueryPerformanceCounter(&EndingTime);
		ElapsedMilliseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

		ElapsedMilliseconds.QuadPart *= 1000000;
		double as = ElapsedMilliseconds.QuadPart /= Frequency.QuadPart;
		PS->deltaTime = (as / 1000000);
		std::cout << " deltat: " << as/1000000 << " s"<<std::endl;
	}
	
	return 0;
}