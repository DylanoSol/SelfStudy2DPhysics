#pragma once
class PhysicsObject;
class ConvexEntity; 
struct CollisionPair
{
	CollisionPair(PhysicsObject* a, PhysicsObject* b); 
	CollisionPair(); 

	PhysicsObject* m_ObjectA = nullptr; 
	PhysicsObject* m_ObjectB = nullptr; 

	float2 m_PointA = float2(0.f); 
	float2 m_PointB = float2(0.f); 

	std::vector<float> m_Distances;
	float2 m_SeperationVector = float2(0.f); 
	float m_SeperationDistance = 0.f; 
};

