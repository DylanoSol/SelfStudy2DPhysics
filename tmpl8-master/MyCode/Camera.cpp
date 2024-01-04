#include "precomp.h"
#include "Camera.h"

Camera::Camera(Tmpl8::float2 position)
{
	m_Position = position; 
}

Camera::~Camera()
{

}

void Camera::SetPosition(Tmpl8::float2 position)
{
	m_Position = position; 
}

Tmpl8::float2 Camera::GetPosition()
{
	return m_Position;
}
