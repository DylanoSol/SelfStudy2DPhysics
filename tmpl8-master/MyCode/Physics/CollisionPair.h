#pragma once
class PhysicsObject;
struct CollisionPair
{
	CollisionPair(PhysicsObject* a, PhysicsObject* b); 
	CollisionPair(); 

	PhysicsObject* m_ObjectA = nullptr; 
	PhysicsObject* m_ObjectB = nullptr; 
	std::vector<float> m_Distances;
};

