#pragma once
#include "COMMON/OglForCLI.h"
#include "RigidObject.h"
#include "CollisionCalculator.h"
#include <vector>

using namespace std;

#pragma unmanaged 

class EventManager
{
private:
  //ä÷êî
  EventManager();

  //ïœêî
  bool m_btn_right, m_btn_left, m_btn_middle;
  EVec3f m_cursorPos, m_cursorDir;
  int m_pickObjID;
  float m_dt;
  vector<RigidObject*> m_object;
  CollisionCalculator *m_calcCollision;
 
public: 
  //ä÷êî
  static EventManager* GetInst(){
    static EventManager p;
    return &p;
  }

  //MainFormÇ©ÇÁÇÃÉCÉxÉìÉg
  void BtnDownLeft  (int x, int y, OglForCLI *ogl);
  void BtnDownMiddle(int x, int y, OglForCLI *ogl);
  void BtnDownRight (int x, int y, OglForCLI *ogl);
  void BtnUpLeft    (int x, int y, OglForCLI *ogl);
  void BtnUpMiddle  (int x, int y, OglForCLI *ogl);
  void BtnUpRight   (int x, int y, OglForCLI *ogl);
  void MouseMove    (int x, int y, OglForCLI *ogl);
  void ClickGenerateBtn();
  

  void DrawScene();
  void Step();
};



#pragma managed

