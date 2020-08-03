#pragma once

#include "RigidObject.h"

#pragma unmanaged



class CollisionCalculator
{
private:
  float m_dt;
  
  void SimulateCollision_SphereSphere(RigidObject &sphere1, RigidObject &sphere2);
  void SimulateCollision_SpherePlane(RigidObject &sphere, RigidObject &plane);
  void SimulateCollision_PlanePlane(RigidObject &plane1, RigidObject &plane2);

public:
  CollisionCalculator(const float &dt);
  void CollisionDetection(RigidObject &obj1, RigidObject &obj2);

};

#pragma managed
