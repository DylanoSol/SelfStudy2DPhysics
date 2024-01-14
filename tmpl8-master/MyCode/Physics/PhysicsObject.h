#pragma once
class PhysicsObject
{
public: 
	PhysicsObject(); 
	~PhysicsObject(); 

	//


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

	//Make sure objects get removed at the end of a frame.
	bool m_IsMarkedForRemove = false;

private: 
	//Function Pointer Arrays for callbacks
	std::vector<void*> m_OnHitCallbacks; 
	std::vector<void*> m_OnCollideCallbacks; 
	std::vector<void*> m_OnLeaveCallbacks; 
};

