#pragma once

#include "vector"
#include "tmath.h"
#include "Eigen"
#include "OglForCLI.h"

#pragma unmanaged
class RigidObject
{
protected:
	EVec3f m_position, m_velocity;

public:
	RigidObject();
};

class RigidSphere : public RigidObject
{
private:
	vector<EVec3f> m_vertexs;
	vector<EVec3i> m_polygonIds;
	float m_radius;
	bool m_isPicking;


public:
	RigidSphere(const float &radius, const EVec3f &position, const EVec3f &velocity);
	void DrawObject();
	void IsPickedFalse();
	void IsPickedTrue();
	bool IsPicking();
	bool IsPickedObject(const EVec3f &rayPos, const EVec3f &rayDir);
	EVec3f a, b, c;


};



#pragma managed