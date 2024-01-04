// Template, IGAD version 3
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2023

#include "precomp.h"
#include "game.h"
#include "MyCode/ConvexEntity.h"
#include "MyCode/SAT.h"


// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------

ConvexEntity testEnt; 
ConvexEntity testEnt2; 

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
	testEnt2.m_Position = float2(350.f, 300.f);
}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick(float deltaTime)
{

	// clear the screen to black
	screen->Clear( 0 );
	
	//m_Camera.SetPosition(m_Camera.GetPosition() + float2(1.f));
	testEnt.Draw(screen, &m_Camera); 
	testEnt2.Draw(screen, &m_Camera); 
	AreConvexShapesIntersecting(testEnt, testEnt2); 
	
}