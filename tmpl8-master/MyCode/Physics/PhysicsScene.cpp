#include "precomp.h"
#include "PhysicsScene.h"
#include "PhysicsObject.h"

PhysicsScene::PhysicsScene()
{
}

PhysicsScene::~PhysicsScene()
{
}

void PhysicsScene::Initialize()
{
}

void PhysicsScene::UpdateScene(float deltaTime, int amountOfSubSteps)
{
}

void PhysicsScene::AddPhysicsObject(PhysicsObject* object)
{
	m_PhysicsObjects.push_back(object); 
}

void PhysicsScene::RemovePhysicsObjects()
{
	for (PhysicsObject* object : m_PhysicsObjects)
	{
		if (object->m_IsMarkedForRemove)
		{
			auto it = std::find(m_PhysicsObjects.begin(), m_PhysicsObjects.end(), object);
			m_PhysicsObjects.erase(it);
		}
	}
}
