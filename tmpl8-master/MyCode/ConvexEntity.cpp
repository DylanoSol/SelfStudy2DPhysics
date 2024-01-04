#include "precomp.h"
#include "Camera.h"
#include "ConvexEntity.h"

ConvexEntity::ConvexEntity()
{
}

ConvexEntity::~ConvexEntity()
{

}

void ConvexEntity::Update(float deltaTime)
{

}

void ConvexEntity::Draw(Surface* screen, Camera* camera)
{
	for (size_t i = 0; i < m_Vertices.size() - 1; i++)
	{
		screen->Line(m_Vertices[i].x - camera->GetPosition().x + m_Position.x, m_Vertices[i].y - camera->GetPosition().y + m_Position.y, m_Vertices[i + 1].x - camera->GetPosition().x + m_Position.x, m_Vertices[i + 1].y - camera->GetPosition().y + m_Position.y, 0xff0000);
	}
	screen->Line(m_Vertices[m_Vertices.size() - 1].x - camera->GetPosition().x + m_Position.x, m_Vertices[m_Vertices.size() - 1].y - camera->GetPosition().y + m_Position.y, m_Vertices[0].x - camera->GetPosition().x + m_Position.x, m_Vertices[0].y - camera->GetPosition().y + m_Position.y, 0xff0000);
}

void ConvexEntity::SetAmountOfVertices(int amountOfVertices)
{
	m_Vertices.reserve(static_cast<size_t>(amountOfVertices)); 
}

void ConvexEntity::AddVertex(Tmpl8::float2 vertex)
{
	m_Vertices.push_back(vertex); 
}
