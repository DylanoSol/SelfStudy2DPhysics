// Template, IGAD version 3
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2023

#include "precomp.h"
#include "game.h"
#include "MyCode/Physics/ConvexEntity.h"
#include "MyCode/Physics/SAT.h"
#include "MyCode/Physics/PhysicsObject.h"
#include "MyCode/Physics/CollisionPair.h"


// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------

ConvexEntity testEnt; 
ConvexEntity testEnt2; 
ConvexEntity testEnt3; 

PhysicsObject* test = new PhysicsObject(); 


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
	testEnt.SetAmountOfVertices(5); 
	testEnt.AddVertex(float2(20.f, 40.f));
	testEnt.AddVertex(float2(20.f, 200.f));
	testEnt.AddVertex(float2(80.f, 200.f));
	testEnt.AddVertex(float2(80.f, 120.f));
	testEnt.AddVertex(float2(50.f, 80.f));
	testEnt.m_Position = float2(400.f, 400.f); 

	testEnt2.SetAmountOfVertices(5);
	testEnt2.AddVertex(float2(20.f, 40.f));
	testEnt2.AddVertex(float2(20.f, 200.f));
	testEnt2.AddVertex(float2(80.f, 200.f));
	testEnt2.AddVertex(float2(80.f, 120.f));
	testEnt2.AddVertex(float2(50.f, 80.f));
	testEnt2.m_Position = float2(200.f, 300.f);

	testEnt3.SetAmountOfVertices(4); 
	testEnt3.AddVertex(float2(-1000.f, 0.f)); 
	testEnt3.AddVertex(float2(-1000.f, 10.f));
	testEnt3.AddVertex(float2(1000.f, 10.f));
	testEnt3.AddVertex(float2(1000.f, 0.f));
	testEnt3.m_Position = float2(0.f, 800.f); 

	void (*functionPointer1)() = &Test1;
	void (*functionPointer2)() = &Test2;
	void (*functionPointer3)() = &Test3;

	test->AddOnHitCallback(functionPointer1); 
	test->AddOnHitCallback(functionPointer2); 
	test->AddOnHitCallback(functionPointer3); 
	test->RemoveOnHitCallback(functionPointer3); 
	test->OnHit(); 
}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick(float deltaTime)
{
	int color = 0xff0000; 
	// clear the screen to black
	screen->Clear( 0 );

	if (GetAsyncKeyState(VK_UP))
		testEnt2.m_Position.y--; 

	if (GetAsyncKeyState(VK_DOWN))
		testEnt2.m_Position.y++;

	if (GetAsyncKeyState(VK_LEFT))
		testEnt2.m_Position.x--;

	if (GetAsyncKeyState(VK_RIGHT))
		testEnt2.m_Position.x++;
	
	//testEnt2.m_Position.y += 0.1f; 
	//m_Camera.SetPosition(m_Camera.GetPosition() + float2(1.f));
	CollisionPair* pair = new CollisionPair(); 
	int color2 = 0xff0000; 
	if (AreConvexShapesIntersecting(testEnt, testEnt2, pair))
	{
		color = 0xffff00;
	}

	if (AreConvexShapesIntersecting(testEnt3, testEnt2, pair))
	{
		color2 = 0xffff00;
	}
	delete pair; 
	testEnt.Draw(screen, &m_Camera, color); 
	testEnt2.Draw(screen, &m_Camera, color); 
	testEnt3.Draw(screen, &m_Camera, color2); 
	
}