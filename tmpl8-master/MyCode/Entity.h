#pragma once

class Camera; 
class Entity
{
public: 
	Entity(); 
	~Entity(); 
	virtual void Update(float deltaTime); 
	virtual void Draw(Surface* screen, Camera* camera); 

	Tmpl8::float2 m_Position = Tmpl8::float2(0.f, 0.f); 
protected: 

private: 

};

