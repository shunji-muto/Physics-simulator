#include "stdafx.h"
#include "Score.h"

#pragma unmanaged

using namespace SolidSimulator;

Score::Score()
{
	m_onMouseL = m_onMouseR = m_onMouseM =false;
	testSphere = new RigidSphere(1.0, EVec3f(0, 5, 0), EVec3f(0, 0, 0));
}


void Score::BtnDownL(const EVec2i &p, OglForCLI *ogl)
{
	EVec3f rayPos, rayDir;
	m_onMouseL = true;
	ogl->BtnDown_Trans(p);

	camPos = ogl->GetCamPos();

	ogl->GetCursorRay(p, rayPos, rayDir);
	bool isPicked = testSphere->IsPickedObject(rayPos, rayDir);
	if(isPicked) testSphere->IsPickedTrue();
}


void Score::BtnDownR(const EVec2i &p, OglForCLI *ogl)
{
	m_onMouseR = true;
	ogl->BtnDown_Rot(p);
}


void Score::BtnDownM(const EVec2i &p, OglForCLI *ogl)
{
	m_onMouseM = true;
	ogl->BtnDown_Zoom(p);
}


void Score::BtnUpL(const EVec2i &p, OglForCLI *ogl)
{
	m_onMouseL = false;
	ogl->BtnUp();
	testSphere->IsPickedFalse();
}


void Score::BtnUpR(const EVec2i &p, OglForCLI *ogl)
{
	m_onMouseR = false;
	ogl->BtnUp();
}


void Score::BtnUpM(const EVec2i &p, OglForCLI *ogl)
{
	m_onMouseM = false;
	ogl->BtnUp();
}


void Score::MouseMove(const EVec2i &p, OglForCLI *ogl)
{
	bool isPicking = testSphere->IsPicking();
	//オブジェクトを掴んでいたり、ボタンを押しているとこの関数はスルー
	if (!m_onMouseL && !m_onMouseR && !m_onMouseM && isPicking) return;

	if (!isPicking) ogl->MouseMove(p);
}



void Score::StepTime()
{
	MainForm_RedrawMainPanel();
}

void Score::OnDraw()
{
	glDisable(GL_LIGHTING);
	//XYZ軸描画
	glBegin(GL_LINES);
	glColor3d(1, 0, 0); glVertex3d(0, 0, 0); glVertex3d(10, 0, 0);
	glColor3d(0, 1, 0); glVertex3d(0, 0, 0); glVertex3d(0, 10, 0);
	glColor3d(1, 0, 1); glVertex3d(0, 0, 0); glVertex3d(0, 0, 10);
	
	glColor3d(1, 0, 0); glVertex3fv(testSphere->c.data()); glVertex3fv(testSphere->b.data());
	glColor3d(0, 1, 0); glVertex3fv(testSphere->c.data()); glVertex3fv(testSphere->a.data());
	
	glEnd();

	glBegin(GL_POINTS);
	glVertex3fv(camPos.data());
	glEnd();

	testSphere->DrawObject();
}
