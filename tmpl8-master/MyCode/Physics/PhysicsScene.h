#pragma once
#include "CollisionPair.h"

class PhysicsScene
{
public: 
	PhysicsScene(); 
	~PhysicsScene(); 

	void Initialize(); 
	void UpdateScene(float deltaTime, int amountOfSubSteps = 1); 

private:
	std::vector<CollisionPair*> m_PairsLastFrame; 
	std::vector<CollisionPair*> m_PairsThisFrame; 

};

