#include "stdafx.h"
#include "RigidObject.h"


RigidObject::RigidObject()
{
}

void RigidObject::SetPosition(const EVec3f &position)
{
	m_position = position;
}

void RigidObject::SetVelocity(const EVec3f &velocity)
{
	m_velocity = velocity;
}


EVec3f RigidObject::getPosition()
{
	return m_position;
}


EVec3f RigidObject::getVelocity()
{
	return m_velocity;
}

