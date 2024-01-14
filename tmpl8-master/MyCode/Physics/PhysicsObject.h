#pragma once
class PhysicsObject
{
public: 
	PhysicsObject(); 
	~PhysicsObject(); 

	void OnHit(); 
	void OnCollide(); 
	void OnLeave(); 

	void AddOnHitCallback(void (*ptr)());
	void AddOnCollideCallback(void (*ptr)());
	void AddOnLeaveCallback(void (*ptr)());

	void RemoveOnHitCallback(void (*ptr)());
	void RemoveOnCollideCallback(void (*ptr)());
	void RemoveOnLeaveCallback(void (*ptr)());

private: 
	//Function Pointer Arrays for callbacks
	std::vector<void*> m_OnHitCallbacks; 
	std::vector<void*> m_OnCollideCallbacks; 
	std::vector<void*> m_OnLeaveCallbacks; 
};

