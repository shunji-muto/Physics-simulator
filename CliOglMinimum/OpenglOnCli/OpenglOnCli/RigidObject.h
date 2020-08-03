#pragma once

#pragma unmanaged

#include <vector>
#include "COMMON/tmath.h"
#include "COMMON/OglForCLI.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

class RigidPlane;
class RigidSphere;

using namespace std;

//既定クラス
class RigidObject
{
public:
  enum ObjectType
  {
    Sphere,
    Plane,
  };

protected:
  ObjectType m_type;
  float  m_mass;
  EVec3f m_force;
  EVec3f m_pos, m_velo;
  EVec3f m_rot, m_rotVelo;

public:
  RigidObject(const ObjectType &type, const float &mass, const EVec3f &position, const EVec3f &velocity);

  //other
  virtual void DrawObject() = 0;
  virtual bool isPickedObject(const EVec3f &rayPos, const EVec3f &rayDir) = 0;
  virtual void StepSimulation(const EVec3f &force, const float &dt);

  //for copy
  RigidObject(const RigidObject &src) { Copy(src); };
  void Copy(const RigidObject &src);

  //get
  float  GetMass();
  EVec3f GetPosition();
  EVec3f GetVelocity();
  EVec3f GetRotation();
  EVec3f GetRotVelo();
  ObjectType GetObjectType();
  EVec3f GetForce();
  virtual vector<EVec3f> GetVertex();

  //for sphere
  virtual float GetRadius();

  //for plane
  virtual float  GetWidth();
  virtual float  GetLength();
  virtual EVec3f GetNorm();

  //set
  void SetPosition(const EVec3f &position);
  void SetVelocity(const EVec3f &velocity);
  void SetRotation(const EVec3f &rotation);
  void SetRotVelo (const EVec3f &rotVelocity);
  void SetForce   (const EVec3f &force);
};


//球のクラス
class RigidSphere: public RigidObject
{
private:
  std::vector<EVec3f> vert, norm;
  
  float m_radius;

  static const int reso_i = 32, reso_j = 16;
  
public:
  RigidSphere(const ObjectType &type, const float &radius, const float &mass, const EVec3f &position, const EVec3f &velocity);
  
  //other
  EVec3f GetPosOnSphere(const float &phi, const float &theta);
  void DrawObject();
  bool isPickedObject(const EVec3f &rayPos, const EVec3f &rayDir);

  //for copy
  RigidSphere(const RigidSphere &src);
  
  //get
  float GetRadius();
};


//Planeのクラス
class RigidPlane :public RigidObject
{
private:
  float m_width, m_length;
  vector<EVec3f> m_verts;
  EVec3f m_norm;

public:
  RigidPlane(const ObjectType &type, const float &width, const float &length, const float &mass, const EVec3f &position, const EVec3f &velocity);

  //other
  void DrawObject();
  bool isPickedObject(const EVec3f &rayPos, const EVec3f &rayDir);
  void StepSimulation(const EVec3f &force, const float &dt);

  //copy
  RigidPlane(const RigidPlane &src);

  //get
  float GetWidth();
  float GetLength();
  EVec3f GetNorm();
  vector<EVec3f> GetVertex();

};
#pragma managed