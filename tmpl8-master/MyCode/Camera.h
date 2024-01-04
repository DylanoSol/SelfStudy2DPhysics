#pragma once

class Camera
{
public: 
	Camera(Tmpl8::float2 position); 
	~Camera(); 
	
	void SetPosition(Tmpl8::float2 position); 
	Tmpl8::float2 GetPosition(); 

private: 
	
	Tmpl8::float2 m_Position = float2(0.f, 0.f); 
};

