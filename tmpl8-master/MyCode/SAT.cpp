#include "precomp.h"
#include "SAT.h"
#include "Physics/CollisionPair.h"

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
bool AreConvexShapesIntersecting(ConvexEntity& entity0, ConvexEntity& entity1, CollisionPair* pair)
{
	//Clear the pair to make sure nothing is stored yet. Shouldn't be the case, but just an extra safety check. 
	pair->m_Distances.clear(); 

	//Gathering all faces
	int amountOfFaces = entity0.m_Vertices.size() + entity1.m_Vertices.size(); 

	//Reserve space for faces and distances. 
	pair->m_Distances.reserve(amountOfFaces); 
	std::vector<Face> faces; 
	faces.reserve(amountOfFaces); 

	//Gather faces from first Polygon 
	for (size_t i = 0; i < entity0.m_Vertices.size() - 1; i++)
	{
		faces.push_back(Face(entity0.m_Vertices[i] + entity0.m_Position, entity0.m_Vertices[i + 1] + entity0.m_Position));
	}
	//Last one needs to be done manually
	faces.push_back(Face(entity0.m_Vertices[entity0.m_Vertices.size() - 1] + entity0.m_Position, entity0.m_Vertices[0] + entity0.m_Position));

	//Gather faces from second Polygon 
	for (size_t i = 0; i < entity0.m_Vertices.size() - 1; i++)
	{
		faces.push_back(Face(entity1.m_Vertices[i] + entity1.m_Position, entity1.m_Vertices[i + 1] + entity1.m_Position));
	}

	//Last one needs to be done manually
	faces.push_back(Face(entity1.m_Vertices[entity0.m_Vertices.size() - 1] + entity1.m_Position, entity1.m_Vertices[0] + entity1.m_Position));

	float min1dDistance = INFINITY; 
	float2 storedAxis = float2(0.f); 
	//Check line intersection for every face
	for (Face f : faces)
	{
		float2 faceVector = normalize(float2((f.m_VertexB.x - f.m_VertexA.x), (f.m_VertexB.y - f.m_VertexA.y))); 
		float2 faceProjectionAxis = normalize(float2(-faceVector.y, faceVector.x));

		float min = INFINITY, max = -INFINITY; 

		//Creating line out of Polygon 1 points

		for (size_t i = 0; i < entity0.m_Vertices.size(); i++)
		{
			
			float projectionPoint = dot(entity0.m_Vertices[i] + entity0.m_Position, faceProjectionAxis); 
			min = std::min(min, projectionPoint); 
			max = std::max(max, projectionPoint); 
		}

		float min2 = INFINITY, max2 = -INFINITY;

		for (size_t i = 0; i < entity1.m_Vertices.size(); i++)
		{
			float projectionPoint = dot(entity1.m_Vertices[i] + entity1.m_Position, faceProjectionAxis);
			min2 = std::min(min2, projectionPoint);
			max2 = std::max(max2, projectionPoint);
		}

		//Intersect lines from these projected points 
		if (!(max2 >= min && max >= min2))
		{
			pair->m_Distances.clear(); 
			return false;
		}

		//Compute the shortest 1 dimensional distance. At the end, the projection axis with the smallest 1d distance is the one you are picking. 
		
		float pdist; 

		if (min < min2)
		{
			pdist = min2 - max; 
		}
		else
		{
			pdist = min - max2; 
		}

		//Can probably half the amount of checks here, since things seem to be repeating. 
		pdist = abs(pdist); 
		pair->m_Distances.emplace_back(pdist);

		if (pdist < min1dDistance)
		{
			pair->m_PointA = f.m_VertexA; 
			pair->m_PointB = f.m_VertexB; 

			min1dDistance = pdist;
			storedAxis = faceProjectionAxis;
		}

		//For now to test whether I can get the algorithm to work, make it so that Entity 2 always gets pushed away. 
	}

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

	//Get centers to push the object out
	float2 cA = GetCenterOfMass(verticesA);
	float2 cB = GetCenterOfMass(verticesB);

	//Flip when on right side
	if (dot(cB - cA, storedAxis) < 0.f)
	{
		storedAxis *= -1;
	}

	entity1.m_Position = entity1.m_Position + (storedAxis * min1dDistance); 
	//If all of the sides have intersected, the intersection has happened
	return true;
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
