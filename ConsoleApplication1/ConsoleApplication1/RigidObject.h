#pragma once

#include "tmath.h"
#include "vector"
#include "OglForCLI.h"
#include "Score.h"


#pragma unmanaged
class RigidObject
{
public:
	enum ObjectType { E_Sphere, E_Cube, E_Plane };

protected:
	vector<EVec3f> m_vertexs;
	vector<EVec3f> m_normals;
	vector<EVec3i> m_polygonIds;

	EVec3f m_position, m_velocity;
	EVec3f m_rotation, m_rotVelo;
	float  m_massa;

	ObjectType m_objectType;

public:
	const EVec3f gravity = EVec3f(0, -9.8f, 0);

	RigidObject();
	virtual void DrawObject() = 0;
	virtual void StepSimulation(const EVec3f &force) = 0;
	virtual bool pickedObject(const EVec3f &rayPos, const EVec3f &rayDir) = 0;
	EVec3f getPosition();
	EVec3f getVelocity();
	float getMassa();
	void SetPosition(const EVec3f &position);
	void SetVelocity(const EVec3f &velocity);
	ObjectType getObjectType();

};

class RigidSphere : public RigidObject
{
private:
	float m_radius;

public:
	RigidSphere(const float &massa, const float &radius, const EVec3f &position, const EVec3f &velocity);
	bool pickedObject(const EVec3f &rayPos, const EVec3f &rayDir);
	void DrawObject();
	void StepSimulation(const EVec3f &externalForce);
};

class RididCube : public RigidObject
{

};
class RigidPlane : public RigidObject
{
private:
	EVec3f m_size;

public:
	RigidPlane(const EVec3f &size, const EVec3f &position);
	bool pickedObject(const EVec3f &rayPos, const EVec3f &rayDir)
	{
		//–¢ŽÀ‘•
		return false;
	}
	void DrawObject();
	void StepSimulation(const EVec3f &externalForce)
	{
		//–¢ŽÀ‘•
	}
};

#pragma managed