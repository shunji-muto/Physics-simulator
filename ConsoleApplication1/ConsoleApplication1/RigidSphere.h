#pragma once

#include "tmath.h"
#include "vector"

#pragma unmanaged 
class RigidSphere
{
private:
	float  m_radius;
	EVec3f m_position;
	vector<EVec3f> m_vertexs;
	vector<EVec3f> m_noamls;
	vector<EVec3i> m_polygonIds;

public:
	RigidSphere(const float &radius, const EVec3f &position);
	void DrawObj();

};

#pragma managed 


