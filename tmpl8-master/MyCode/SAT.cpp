#include "precomp.h"
#include "SAT.h"

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
bool AreConvexShapesIntersecting(const ConvexEntity& entity0, const ConvexEntity& entity1)
{
	//Gathering all faces
	int amountOfFaces = entity0.m_Vertices.size() + entity1.m_Vertices.size(); 
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

	//Check line intersection for every face
	for (Face f : faces)
	{
		float2 faceVector = float2((f.m_VertexB.x - f.m_VertexA.x), (f.m_VertexB.y - f.m_VertexA.y)); 
		Line throughOrigin; 
		throughOrigin.m_Slope = -1.f / (faceVector.y / faceVector.x); 

		//Creating line out of Polygon 1 points

		//Creating line out of Polygon 2 points 

		//Intersect lines from these projected points 
	}

	//If all of the sides have intersected, the intersection has happened
	return true;
}
