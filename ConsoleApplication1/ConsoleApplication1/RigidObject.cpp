#include "stdafx.h"
#include "RigidObject.h"


RigidObject::RigidObject()
{
	m_position = m_velocity = EVec3f(0, 0, 0);
	m_massa = 0;
}


void   RigidObject::SetPosition(const EVec3f &position)
{
	m_position = position;
}
void   RigidObject::SetVelocuty(const EVec3f &velocity)
{
	m_velocity = velocity;
}
EVec3f RigidObject::GetPosition()
{
	return m_position;
}
EVec3f RigidObject::GetVelocity() 
{
	return m_velocity;
}
float  RigidObject::GetMassa()
{
	return m_massa;
}