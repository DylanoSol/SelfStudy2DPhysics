#include "precomp.h"
#include "CollisionPair.h"
#include "PhysicsObject.h"

CollisionPair::CollisionPair(PhysicsObject* a, PhysicsObject* b)
{
	m_ObjectA = a; 
	m_ObjectB = b; 
	m_Distances.clear(); 
}

CollisionPair::CollisionPair()
{
	m_Distances.clear();
}