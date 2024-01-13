#pragma once

class Camera; 

struct DrawData
{
	Surface* m_Screen = nullptr;
	Camera* m_Camera = nullptr;
	int m_DrawColor = 0xff0000;

};

class Entity
{
public: 
	Entity(); 
	~Entity(); 
	virtual void Update(float deltaTime); 
	virtual void Draw(Surface* screen, Camera* camera, int color); 

	Tmpl8::float2 m_Position = Tmpl8::float2(0.f, 0.f); 
protected: 

private: 

};

