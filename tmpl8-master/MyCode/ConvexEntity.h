#pragma once
#include "Entity.h"

class ConvexEntity :
    public Entity
{
public: 
    ConvexEntity(); 
    ~ConvexEntity(); 

    void Update(float deltaTime) override;
    void Draw(Surface* screen, Camera* camera) override;

    void SetAmountOfVertices(int amountOfVertices); 
    void AddVertex(Tmpl8::float2 vertex); 
    
    std::vector<Tmpl8::float2> m_Vertices; 
private: 
};

