#include "stdafx.h"
#include "RigidObject.h"

using namespace std;

RigidPlane::RigidPlane(const ObjectType &type, const float &width, const float &length, const float &mass, const EVec3f &position, const EVec3f &velocity) :RigidObject(type, mass, position, velocity)
{
  this->m_width = width;
  this->m_length = length;
  this->m_norm = EVec3f(0, 1, 0);
  this->m_verts.push_back(EVec3f(-this->m_width / 2, 0, -this->m_length / 2));
  this->m_verts.push_back(EVec3f( this->m_width / 2, 0, -this->m_length / 2));
  this->m_verts.push_back(EVec3f( this->m_width / 2, 0,  this->m_length / 2));
  this->m_verts.push_back(EVec3f(-this->m_width / 2, 0,  this->m_length / 2));
};

//other
//このプログラムではPlaneはxy平面に水平である
void RigidPlane::DrawObject()
{
  const static float diffG[4] = { 0.2f, 0.8f, 0.2f, 0.3f };
  const static float ambiG[4] = { 0.2f, 0.8f, 0.2f, 0.3f };
  const static float spec[4] = { 1,1,1,0.3f };
  const static float shin[1] = { 64.0f };
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffG);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiG);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);

  glEnable(GL_CULL_FACE);
  glDisable(GL_CULL_FACE);
  glBegin(GL_TRIANGLES);
  glColor3d(0, 0.5, 0);
  glNormal3f(0,1,0);
  
  //todo]xz平面以外にも対応させる
  glVertex3fv(this->m_verts[0].data());
  glVertex3fv(this->m_verts[1].data());
  glVertex3fv(this->m_verts[2].data());

  glVertex3fv(this->m_verts[0].data());
  glVertex3fv(this->m_verts[2].data());
  glVertex3fv(this->m_verts[3].data());
  glEnd();
}

bool RigidPlane::isPickedObject(const EVec3f &rayPos, const EVec3f &rayDir)
{

  return false;
}

void RigidPlane::StepSimulation(const EVec3f &force, const float &dt)
{
  //このプログラムではPlaneは不動
}


//for copy
RigidPlane::RigidPlane(const RigidPlane &src) :RigidObject(src)
{
  this->m_width = src.m_width;
  this->m_length = src.m_length;
}

//get
float RigidPlane::GetWidth()
{
  return this->m_width;
}
float RigidPlane::GetLength()
{
  return this->m_length;
}
EVec3f RigidPlane::GetNorm()
{
  return m_norm;
}
vector<EVec3f> RigidPlane::GetVertex()
{
  return this->m_verts;
}

