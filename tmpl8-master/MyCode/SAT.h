#pragma once

#include "ConvexEntity.h"

struct Ray
{
public: 
	float2 m_Start = 0.f;
	float m_Slope = 0.f; 
};

struct Line
{
public: 
	float m_Slope = 0.f; 
};

struct LineSegment
{
public: 
	float2 m_Start = 0.f; 
	float2 m_End = 0.f; 
};

struct Face
{
public: 
	Face() = delete;
	Face(float2 a, float2 b)
	{
		m_VertexA = a; 
		m_VertexB = b; 
	}
	float2 m_VertexA;
	float2 m_VertexB;
};

bool AreConvexShapesIntersecting(const ConvexEntity& entity0, const ConvexEntity& entity1);