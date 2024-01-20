#include "precomp.h"
#include "GameplayEntity.h"
#include "Physics/PhysicsObject.h"
#include "Physics/ConvexShape.h"
#include "Camera.h"

GameplayEntity::GameplayEntity(float2 pos)
{
	m_Position = pos; 
}

GameplayEntity::~GameplayEntity()
{
}

void GameplayEntity::Update(float deltaTime)
{
	printf("Temporary GameObject Update call, oh yea here is deltatime lmfao: %f \n", deltaTime); 
}

void GameplayEntity::Draw(Surface* screen, Camera* camera, int color)
{
	if (m_PhysicsObject != nullptr)
	{
		//Since I will only be supporting Convex Shapes right now, every Gameplay Entity that I draw can be visualized like this for now. 
		ConvexShape* shape = m_PhysicsObject->GetShape(); 

		for (size_t i = 0; i < shape->m_Vertices.size() - 1; i++)
		{
			screen->Line(shape->m_Vertices[i].x - camera->GetPosition().x + m_Position.x, shape->m_Vertices[i].y - camera->GetPosition().y + m_Position.y, shape->m_Vertices[i + 1].x - camera->GetPosition().x + m_Position.x, shape->m_Vertices[i + 1].y - camera->GetPosition().y + m_Position.y, color);
		}
		screen->Line(shape->m_Vertices[shape->m_Vertices.size() - 1].x - camera->GetPosition().x + m_Position.x, shape->m_Vertices[shape->m_Vertices.size() - 1].y - camera->GetPosition().y + m_Position.y, shape->m_Vertices[0].x - camera->GetPosition().x + m_Position.x, shape->m_Vertices[0].y - camera->GetPosition().y + m_Position.y, color);
	}
}
