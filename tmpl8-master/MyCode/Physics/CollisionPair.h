#pragma once
class PhysicsObject;
struct CollisionPair
{
	CollisionPair(PhysicsObject* a, PhysicsObject* b); 
	PhysicsObject* m_ObjectA = nullptr; 
	PhysicsObject* m_ObjectB = nullptr; 
};

