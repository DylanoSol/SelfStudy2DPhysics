#pragma once
#include "CollisionPair.h"

class PhysicsObject; 
class PhysicsScene
{
public: 
	PhysicsScene(); 
	~PhysicsScene(); 

	void Initialize(); 
	void UpdateScene(float deltaTime, int amountOfSubSteps = 1); 

	void AddPhysicsObject(PhysicsObject* object); 

private:
	std::vector<PhysicsObject*> m_PhysicsObjects; 

	std::vector<CollisionPair*> m_PairsLastFrame; 
	std::vector<CollisionPair*> m_PairsThisFrame; 

	void RemovePhysicsObjects(); 

};



