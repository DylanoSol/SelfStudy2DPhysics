#pragma once
#include "Entity.h"

class PhysicsObject; 
class ConvexShape; 
class GameplayEntity :
    public Entity
{
public: 
    GameplayEntity() = delete; 
    GameplayEntity(float2 pos); 
    ~GameplayEntity();

    void Update(float deltaTime) override;
    void Draw(Surface* screen, Camera* camera, int color) override;

private:
    PhysicsObject* m_PhysicsObject = nullptr; 
 
};

