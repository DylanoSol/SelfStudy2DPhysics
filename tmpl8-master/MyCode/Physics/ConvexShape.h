#pragma once
class ConvexShape
{
	//Needs to hold: Vertices
public: 
    ConvexShape(); 
    ConvexShape(std::string filePath); 
    ConvexShape(const std::vector<Tmpl8::float2>& vertices); 

    ~ConvexShape(); 

    void SetAmountOfVertices(int amountOfVertices);
    void AddVertex(Tmpl8::float2 vertex);

    std::vector<Tmpl8::float2> m_Vertices;
private:

};

