#include "precomp.h"
#include "PhysicsObject.h"
#include "ConvexShape.h"

PhysicsObject::PhysicsObject()
{
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::OnHit()
{
	for (auto ptr : m_OnHitCallbacks)
	{
		auto function = reinterpret_cast<void(*)()>(ptr); 
		function(); 
	}
}

void PhysicsObject::OnCollide()
{
	for (auto ptr : m_OnCollideCallbacks)
	{
		auto function = reinterpret_cast<void(*)()>(ptr);
		function();
	}
}

void PhysicsObject::OnLeave()
{
	for (auto ptr : m_OnLeaveCallbacks)
	{
		auto function = reinterpret_cast<void(*)()>(ptr);
		function();
	}
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

void PhysicsObject::AttachShape(ConvexShape* shape)
{
	if (m_Shape != nullptr)
	{
		delete m_Shape; 
		m_Shape = nullptr; 
	}

	m_Shape = shape; 
}

ConvexShape* PhysicsObject::GetShape()
{
	return m_Shape;
}

void PhysicsObject::SetPosition(float2 pos)
{
	m_Position = pos; 
}

float2 PhysicsObject::GetPosition()
{
	return m_Position; 
}
