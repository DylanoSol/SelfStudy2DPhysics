#pragma once
class PhysicsScene
{
public: 
	PhysicsScene(); 
	~PhysicsScene(); 

	void Initialize(); 
	void UpdateScene(float deltaTime, int amountOfSubSteps = 1); 

private:

};

