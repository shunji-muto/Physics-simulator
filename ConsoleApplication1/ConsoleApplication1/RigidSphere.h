#pragma once

#include "tmath.h"
#include "vector"

#pragma unmanaged 
class RigidSphere
{
private:
	float m_radius;
	float m_massa;
	EVec3f m_position;
	EVec3f m_velocity;
	vector<EVec3f> m_vertexs;
	vector<EVec3f> m_normals;
	vector<EVec3i> m_polygonIds;
	const EVec3f gravity = EVec3f(0, -9.8f, 0);


public:
	RigidSphere(const float &massa, const float &radius, const EVec3f &position, const EVec3f &velocity);
	void DrawObj();
	void RigidSphere::StepSimulation(const EVec3f &externalForce);
};

#pragma managed 


