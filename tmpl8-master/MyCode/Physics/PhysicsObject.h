#pragma once
class ConvexShape; 
class PhysicsObject
{
public: 
	PhysicsObject(); 
	~PhysicsObject(); 

	//Callback interface
	void OnHit(); 
	void OnCollide(); 
	void OnLeave(); 

	void AddOnHitCallback(void (*ptr)());
	void AddOnCollideCallback(void (*ptr)());
	void AddOnLeaveCallback(void (*ptr)());

	void RemoveOnHitCallback(void (*ptr)());
	void RemoveOnCollideCallback(void (*ptr)());
	void RemoveOnLeaveCallback(void (*ptr)());

	void AttachShape(ConvexShape* shape);
	ConvexShape* GetShape(); 

	void SetPosition(float2 pos); 
	float2 GetPosition(); 

	//Make sure objects get removed at the end of a frame.
	bool m_IsMarkedForRemove = false;

private: 
	//Function Pointer Arrays for callbacks
	std::vector<void*> m_OnHitCallbacks; 
	std::vector<void*> m_OnCollideCallbacks; 
	std::vector<void*> m_OnLeaveCallbacks; 

	Tmpl8::float2 m_Position = float2(0.f); 

	ConvexShape* m_Shape = nullptr; 
};

