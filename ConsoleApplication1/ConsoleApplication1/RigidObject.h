#pragma once

#include "vector"
#include "tmath.h"
#include "OglForCLI.h"

#pragma unmanaged

class RigidObject
{
protected:
	EVec3f m_position, m_velocity;
	float m_massa;

	vector<EVec3f> m_vertexs;
	vector<EVec3f> m_normals;
	vector<EVec3i> m_polygonIds;


public:
	enum  ObjectType { E_Sphere, E_Cube, E_Plane };
	const EVec3f gravity = EVec3f(0, -9.8f, 0);


public:	
	RigidObject();

	virtual void DrawObject() = 0;
	virtual void StepSimulation(const EVec3f &externalForce) = 0;
	virtual bool pickedObject(const EVec3f &rayPos, const EVec3f &rayDir) = 0;

	void   SetPosition(const EVec3f &position);
	void   SetVelocuty(const EVec3f &velocity);
	EVec3f GetPosition();
	EVec3f GetVelocity();
	float  GetMassa();
};


class RigidSphere : public RigidObject
{
private:
	float m_radius;

public:
	RigidSphere(const float &massa, const float &radius, const EVec3f &position, const EVec3f &velocity);
	void DrawObject();
	void StepSimulation(const EVec3f &externalForce);
	bool pickedObject(const EVec3f &rayPos, const EVec3f &rayDir);

	float GetRadius();
};



class RigidPlane : public RigidObject
{
private:
	EVec3f m_size;
public:
	RigidPlane(const EVec3f &size, const EVec3f &position);
	void DrawObject();
	void StepSimulation(const EVec3f &externalForce)
	{
		//–¢ŽÀ‘•
	}
	bool pickedObject(const EVec3f &rayPos, const EVec3f &rayDir)
	{
		//–¢ŽÀ‘•
		return false;
	}

	EVec3f GetSize();
};

#pragma managed