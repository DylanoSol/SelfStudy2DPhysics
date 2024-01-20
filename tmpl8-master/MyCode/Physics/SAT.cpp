#include "precomp.h"
#include "SAT.h"
#include "CollisionPair.h"
#include <math.h>

//1: Get a face 
//2: Get the slope from this face
//3: Use slope / -1 to get the line that is perpendicular and goes through the origin 
//4: From every vertex on the polygon you are testing, get a perpendicular vector from the face, and calculate the point of intersection 
	// with the line through the origin 
//5: Create a line segment from the point the most left and the most right on the line. 
//6: Repeat 4 and 5 for the other polygon 
//7: Check for an intersection between the 2 lines
//8: If intersection, go to next face, if no intersection early out
//9: Repeat until there's no more faces left. 

//Does not take object rotation into account currently. To take object rotation into the account:
//All I need to do is rotate the vertices depending on the origin that is stated for the object. 

//New implementation derived from https://github.com/twobitcoder101/FlatPhysics
bool AreConvexShapesIntersecting(ConvexEntity& entity0, ConvexEntity& entity1, CollisionPair* pair)
{
	//Clear the pair to make sure nothing is stored yet. Shouldn't be the case, but just an extra safety check. 
	pair->m_Distances.clear(); 

	float minDistance = INFINITY; 
	float2 normal = float2(0.f); 

	//Gather all vertices.
	std::vector<float2> verticesA;
	std::vector<float2> verticesB; 

	verticesA.reserve(entity0.m_Vertices.size()); 
	verticesB.reserve(entity1.m_Vertices.size()); 

	for (size_t i = 0; i < entity0.m_Vertices.size(); i++)
	{
		verticesA.emplace_back(entity0.m_Vertices[i] + entity0.m_Position); 
	}

	for (size_t i = 0; i < entity1.m_Vertices.size(); i++)
	{
		verticesB.emplace_back(entity1.m_Vertices[i] + entity1.m_Position);
	}

	//Project vertices of entity0
	for (size_t i = 0; i < verticesA.size(); i++)
	{
		//Make sure you go make an edge from last to first. Eventually
		size_t otherIndex = i + 1;
		if (otherIndex == verticesA.size())
			otherIndex = 0;

		float2 VertexA = verticesA[i];
		float2 VertexB = verticesA[otherIndex];

		//Use the cross product to get the normal later
		float3 point1 = float3(VertexA.x, VertexA.y, 0);
		float3 point2 = float3(VertexB.x, VertexB.y, 0);

		//If counterclockwise doing a crossproduct with a negative z makes the normal point outwards
		float3 faceVector = cross(normalize(point2 - point1), float3(0, 0, -1));

		float2 faceProjectionAxis = normalize(float2(faceVector.x, faceVector.y));

		float min, max, min2, max2; 

		ProjectVertices(verticesA, faceProjectionAxis, min, max); 
		ProjectVertices(verticesB, faceProjectionAxis, min2, max2); 

		//No possible overlap
		if (min >= max2 || min2 >= max)
			return false; 

		float dist = fminf(max2 - min, max - min2); 

		if (dist < minDistance)
		{
			minDistance = dist; 
			normal = faceProjectionAxis; 
		}
	}

	//Project vertices of entity1 
	for (size_t i = 0; i < verticesB.size(); i++)
	{
		//Make sure you go make an edge from last to first. Eventually
		size_t otherIndex = i + 1;
		if (otherIndex == verticesB.size())
			otherIndex = 0;

		float2 VertexA = verticesB[i];
		float2 VertexB = verticesB[otherIndex];

		//Use the cross product to make sure all of the normals are facing outwards. 
		float3 point1 = float3(VertexA.x, VertexA.y, 0);
		float3 point2 = float3(VertexB.x, VertexB.y, 0);

		float3 faceVector = cross(normalize(point2 - point1), float3(0, 0, -1));

		float2 faceProjectionAxis = normalize(float2(faceVector.x, faceVector.y));

		float min, max, min2, max2;

		ProjectVertices(verticesA, faceProjectionAxis, min, max);
		ProjectVertices(verticesB, faceProjectionAxis, min2, max2);

		//No possible overlap
		if (min >= max2 || min2 >= max)
			return false;

		float dist = fminf(max2 - min, max - min2);

		if (dist < minDistance)
		{
			minDistance = dist;
			normal = faceProjectionAxis;
		}
	}

	//Get centers to push the object out
	float2 cA = GetCenterOfMass(verticesA); 
	float2 cB = GetCenterOfMass(verticesB); 

	//Flip when on right side
	if (dot(cB - cA, normal) < 0.f)
	{
		normal *= -1; 
	}

	entity1.m_Position = entity1.m_Position + normal * minDistance; 

	return true;
}

void ProjectVertices(const std::vector<float2>& vertices, const float2& projectionAxis, float& min, float& max)
{
	min = INFINITY; 
	max = -INFINITY; 

	for (size_t i = 0; i < vertices.size(); i++)
	{
		float2 point = vertices[i]; 

		float projectionPoint = dot(point, projectionAxis); 

		if (projectionPoint < min)
			min = projectionPoint; 

		if (projectionPoint > max)
			max = projectionPoint; 
	}
}

float2 GetCenterOfMass(const std::vector<float2>& vertices)
{
	float sumX = 0.f; 
	float sumY = 0.f; 

	for (size_t i = 0; i < vertices.size(); i++)
	{
		sumX += vertices[i].x; 
		sumY += vertices[i].y; 
	}

	float invAmount = 1.f / static_cast<float>(vertices.size()); 
	float2 average = float2(sumX * invAmount, sumY * invAmount); 
	return average;
}
