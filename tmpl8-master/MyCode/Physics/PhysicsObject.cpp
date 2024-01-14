#include "precomp.h"
#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::OnHit()
{
}

void PhysicsObject::OnCollide()
{
}

void PhysicsObject::OnLeave()
{
}

void PhysicsObject::AddOnHitCallback(void (*ptr)())
{
	m_OnHitCallbacks.push_back(ptr);
}

void PhysicsObject::AddOnCollideCallback(void (*ptr)())
{
	m_OnCollideCallbacks.push_back(ptr);
}

void PhysicsObject::AddOnLeaveCallback(void (*ptr)())
{
	m_OnLeaveCallbacks.push_back(ptr);
}

void PhysicsObject::RemoveOnHitCallback(void (*ptr)())
{
	auto it = std::find(m_OnHitCallbacks.begin(), m_OnHitCallbacks.end(), ptr); 
	if (it == m_OnHitCallbacks.end())
	{
		printf("Object not in list"); 
		return; 
	}
	m_OnHitCallbacks.erase(it); 
}

void PhysicsObject::RemoveOnCollideCallback(void (*ptr)())
{
	auto it = std::find(m_OnCollideCallbacks.begin(), m_OnCollideCallbacks.end(), ptr);
	if (it == m_OnCollideCallbacks.end())
	{
		printf("Object not in list");
		return;
	}
	m_OnCollideCallbacks.erase(it);
}

void PhysicsObject::RemoveOnLeaveCallback(void (*ptr)())
{
	auto it = std::find(m_OnLeaveCallbacks.begin(), m_OnLeaveCallbacks.end(), ptr);
	if (it == m_OnLeaveCallbacks.end())
	{
		printf("Object not in list");
		return;
	}
	m_OnLeaveCallbacks.erase(it);
}
