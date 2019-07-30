#include "stdafx.h"
#include "Score.h"
#include "MainForm.h"

using namespace SolidSimulator;

Score::Score()
{
	testPlane  = new RigidPlane (EVec3f(10, 1, 10), EVec3f(0, 0, 0));
	testSphere = new RigidSphere(1.0f, 1.0f, EVec3f(0, 10, 0), EVec3f(0, 0, 0));
}

void Score::StepTime()
{
	testSphere->StepSimulation(EVec3f(0, 0, 0));
	MainForm_RedrawMainPanel();
}

void Score::OnDraw()
{
	glDisable(GL_LIGHTING);
	testPlane ->DrawObject();
	testSphere->DrawObject();
}
