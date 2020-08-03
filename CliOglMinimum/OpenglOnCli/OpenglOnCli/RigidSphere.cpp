#include "stdafx.h"
#include "RigidObject.h"

#pragma unmanaged

using namespace std;

RigidSphere::RigidSphere(const ObjectType &type, const float &radius, const float &mass, const EVec3f &position, const EVec3f &velocity) :RigidObject(type, mass, position, velocity)
{
  this->m_radius = radius > 0 ? radius : 1;

  //í∏ì_ÇÃåvéZ
  for (int i = 0; i < reso_i; ++i)
  {
    for (int j = 0; j < reso_j; ++j)
    {
      this->norm.push_back(GetPosOnSphere(M_PI * i / (reso_i - 1.0f) - M_PI / 2.0f,
        2 * M_PI * j / (reso_j - 1.0f)));
      this->vert.push_back(m_radius * norm[j + i * reso_j]);
    }
  }
}

//other
EVec3f RigidSphere::GetPosOnSphere(const float &phi, const float &theta)
{
  return EVec3f(cos(phi) * cos(theta),
                sin(phi),
               -cos(phi) * sin(theta));
}

void RigidSphere::DrawObject()
{
  //ï`âÊèàóù
  const static float diff[4] = { 1.0f, 0.2f, 0, 0.3f };
  const static float ambi[4] = { 1.0f, 0.2f, 0, 0.3f };
  const static float spec[4] = { 1,1,1,0.3f };
  const static float shin[1] = { 64.0f };

  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);

  glPushMatrix();
  glTranslatef(m_pos[0], m_pos[1], m_pos[2]);
  glBegin(GL_TRIANGLES);
  for (int i = 0; i < reso_i - 1; ++i)
  {
    for (int j = 0; j < reso_j - 1; ++j)
    {
      int idx0 = reso_j * i + j, idx1 = reso_j * i + j + 1;
      int idx2 = reso_j * (i + 1) + j, idx3 = reso_j * (i + 1) + j + 1;
      glNormal3fv(norm[idx0].data()); glVertex3fv(vert[idx0].data());
      glNormal3fv(norm[idx2].data()); glVertex3fv(vert[idx2].data());
      glNormal3fv(norm[idx3].data()); glVertex3fv(vert[idx3].data());

      glNormal3fv(norm[idx0].data()); glVertex3fv(vert[idx0].data());
      glNormal3fv(norm[idx3].data()); glVertex3fv(vert[idx3].data());
      glNormal3fv(norm[idx1].data()); glVertex3fv(vert[idx1].data());
    }
  }
  glEnd();
  glPopMatrix();
}

bool RigidSphere::isPickedObject(const EVec3f &rayPos, const EVec3f &rayDir)
{
  const EVec3f dir = rayDir.normalized();
  const EVec3f a = dir.dot(this->m_pos - rayPos)*dir + rayPos;
  //const EVec3f a = (rayPos - this->m_pos).dot(rayDir.normalized())*rayDir.normalized() + rayPos;
  const float distance = (a - m_pos).norm();
  cout << distance << endl;
  return distance <= m_radius ? true : false;
}

//for copy
RigidSphere::RigidSphere(const RigidSphere &src) :RigidObject(src)
{
  this->m_radius = src.m_radius;
}

//get
float RigidSphere::GetRadius()
{
  return this->m_radius;
}
#pragma managed
