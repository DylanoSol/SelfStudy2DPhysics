#include "precomp.h"
#include "ConvexShape.h"

ConvexShape::ConvexShape()
{
}

ConvexShape::ConvexShape(std::string filePath)
{
	//Implement loading from JSON file later on.
	assert(0); 
}

ConvexShape::ConvexShape(const std::vector<Tmpl8::float2>& vertices)
{
	m_Vertices.clear(); 
	m_Vertices.reserve(vertices.size()); 
	for (size_t i = 0; i < vertices.size(); i++)
	{
		m_Vertices.emplace_back(vertices[i]); 
	}
}

ConvexShape::~ConvexShape()
{
	
}

void ConvexShape::SetAmountOfVertices(int amountOfVertices)
{
	m_Vertices.reserve(amountOfVertices); 
}

void ConvexShape::AddVertex(Tmpl8::float2 vertex)
{
	m_Vertices.emplace_back(vertex); 
}
