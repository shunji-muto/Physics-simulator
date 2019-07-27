#include "stdafx.h"
#include "Score.h"
#include "RigidPlane.h"
#include "MainForm.h"

using namespace SolidSimulator;

Score::Score()
{
	testPlane = new RigidPlane(EVec3f(10, 1, 10), EVec3f(-5, -10, -5), EVec3f(0, 1, 0));
}

void Score::StepTime()
{
	MainForm_RedrawMainPanel();
}

void Score::OnDraw()
{
	testPlane->drawObj();
}
