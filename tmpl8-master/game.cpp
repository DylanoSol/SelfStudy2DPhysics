// Template, IGAD version 3
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2023

#include "precomp.h"
#include "game.h"
#include "MyCode/Physics/SAT.h"
#include "MyCode/Physics/PhysicsObject.h"
#include "MyCode/Physics/CollisionPair.h"
#include "MyCode/Physics/ConvexShape.h"
#include "MyCode/GameplayEntity.h"
#include "json.hpp"


// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------

ConvexShape testShape; 
ConvexShape testShape2; 
ConvexShape testShape3; 

PhysicsObject* test = new PhysicsObject(); 
PhysicsObject* test2 = new PhysicsObject();
PhysicsObject* test3 = new PhysicsObject();

GameplayEntity testEntity(test->GetPosition());
GameplayEntity testEntity2(test2->GetPosition());
GameplayEntity testEntity3(test3->GetPosition());


void Test1()
{
	printf("g");
}

void Test2()
{
	printf("g");
}

void Test3()
{
	printf("g");
}



void Game::Init()
{
	//Horrible way to do this. I am aware. For now, I do not care

	//Vertices should be added CounterClockwise. 
	testShape.SetAmountOfVertices(5); 
	testShape.AddVertex(float2(20.f, 40.f));
	testShape.AddVertex(float2(20.f, 200.f));
	testShape.AddVertex(float2(80.f, 200.f));
	testShape.AddVertex(float2(80.f, 120.f));
	testShape.AddVertex(float2(50.f, 80.f));
	
	test->SetPosition(float2(400.f, 400.f)); 
	test->AttachShape(&testShape);

	testShape2.SetAmountOfVertices(5);
	testShape2.AddVertex(float2(20.f, 40.f));
	testShape2.AddVertex(float2(20.f, 200.f));
	testShape2.AddVertex(float2(80.f, 200.f));
	testShape2.AddVertex(float2(80.f, 120.f));
	testShape2.AddVertex(float2(50.f, 80.f));

	test2->SetPosition(float2(200.f, 300.f)); 
	test2->AttachShape(&testShape2); 

	testShape3.SetAmountOfVertices(4); 
	testShape3.AddVertex(float2(-1000.f, 0.f)); 
	testShape3.AddVertex(float2(-1000.f, 10.f));
	testShape3.AddVertex(float2(1000.f, 10.f));
	testShape3.AddVertex(float2(1000.f, 0.f));

	test3->SetPosition(float2(0.f, 800.f)); 
	test3->AttachShape(&testShape3);

	void (*functionPointer1)() = &Test1;
	void (*functionPointer2)() = &Test2;
	void (*functionPointer3)() = &Test3;

	test->AddOnHitCallback(functionPointer1); 
	test->AddOnHitCallback(functionPointer2); 
	test->AddOnHitCallback(functionPointer3); 
	test->RemoveOnHitCallback(functionPointer3); 
	test->OnHit(); 

	testEntity.m_PhysicsObject = test; 
	testEntity2.m_PhysicsObject = test2;
	testEntity3.m_PhysicsObject = test3;
}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick(float deltaTime)
{
	nlohmann::ordered_json jsonData;
	jsonData.push_back("s"); 

	int color = 0xff0000; 
	// clear the screen to black
	screen->Clear( 0 );

	if (GetAsyncKeyState(VK_UP))
		test2->SetPosition(float2(test2->GetPosition().x, test2->GetPosition().y - 1));

	if (GetAsyncKeyState(VK_DOWN))
		test2->SetPosition(float2(test2->GetPosition().x, test2->GetPosition().y + 1));

	if (GetAsyncKeyState(VK_LEFT))
		test2->SetPosition(float2(test2->GetPosition().x - 1, test2->GetPosition().y));

	if (GetAsyncKeyState(VK_RIGHT))
		test2->SetPosition(float2(test2->GetPosition().x + 1, test2->GetPosition().y));


	
	//testEnt2.m_Position.y += 0.1f; 
	//m_Camera.SetPosition(m_Camera.GetPosition() + float2(1.f));
	CollisionPair* pair = new CollisionPair(); 
	int color2 = 0xff0000; 
	if (AreConvexShapesIntersecting(test, test2, pair))
	{
		color = 0xffff00;
	}

	if (AreConvexShapesIntersecting(test3, test2, pair))
	{
		color2 = 0xffff00;
	}
	delete pair; 

	testEntity.Update(0.f); 
	testEntity2.Update(0.f); 
	testEntity3.Update(0.f); 

	testEntity.Draw(screen, &m_Camera, color); 
	testEntity2.Draw(screen, &m_Camera, color); 
	testEntity3.Draw(screen, &m_Camera, color2); 
	
}