#include "stdafx.h"
#include "RigidObject.h"

#pragma unmanaged

using namespace std;

RigidObject::RigidObject(const ObjectType &type, const float &mass, const EVec3f &position, const EVec3f &velocity)
{
  this->m_type    = type;
  this->m_force   = EVec3f(0, 0, 0);
  this->m_mass    = mass > 0 ? mass : 0;
  this->m_pos     = position;
  this->m_velo    = velocity;
  this->m_rot     = EVec3f(0, 0, 0);
  this->m_rotVelo = EVec3f(0, 0, 0);
}

//other
void RigidObject::StepSimulation(const EVec3f &force,const float &dt)
{
  EVec3f gravity = EVec3f(0, -9.8, 0);
  EVec3f toalForce = force + m_force + this->m_mass * gravity;
  m_force = EVec3f(0, 0, 0);

  EVec3f a = toalForce / this->m_mass;
  this->m_velo += a * dt;
  this->m_pos  += m_velo * dt;
}

//copy
void RigidObject::Copy(const RigidObject &src)
{
  this->m_type    = src.m_type;
  this->m_mass    = src.m_mass;
  this->m_pos     = src.m_pos;
  this->m_velo    = src.m_velo;
  this->m_rot     = src.m_rot;
  this->m_rotVelo = src.m_rotVelo;
}

//get
float  RigidObject::GetMass()
{
  return this->m_mass;
}

EVec3f RigidObject::GetPosition()
{
  return this->m_pos;
}

EVec3f RigidObject::GetVelocity()
{
  return this->m_velo;
}

EVec3f RigidObject::GetRotation()
{
  return this->m_rot;
}

EVec3f RigidObject::GetRotVelo()
{
  return this->m_rotVelo;
}

RigidObject::ObjectType RigidObject::GetObjectType()
{
  return this->m_type;
}

EVec3f RigidObject::GetForce()
{
  return m_force;
}

float RigidObject::GetRadius()
{
  cout << "not sphere" << endl;
  return 0;
}

float  RigidObject::GetWidth()
{
  cout << "not plane" << endl;
  return 0;
}

float  RigidObject::GetLength()
{
  cout << "not plane" << endl;
  return 0;
}

EVec3f RigidObject::GetNorm()
{
  cout << "not plane" << endl;
  return EVec3f(0, 0, 0);
}

vector<EVec3f> RigidObject::GetVertex()
{
  return {};
}

//set
void RigidObject::SetPosition(const EVec3f &position)
{
  this->m_pos = position;
}

void RigidObject::SetVelocity(const EVec3f &velocity)
{
  this->m_velo = velocity;
}

void RigidObject::SetRotation(const EVec3f &rotation)
{
  this->m_rot = rotation;
}

void RigidObject::SetRotVelo(const EVec3f &rotVelocity)
{
  this->m_rotVelo = rotVelocity;
}

void RigidObject::SetForce(const EVec3f &force)
{
  m_force = force;
}


#pragma managed
