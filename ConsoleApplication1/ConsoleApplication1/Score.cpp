#include "stdafx.h"
#include "Score.h"

using namespace SolidSimulator;

Score::Score()
{
	m_onMouseL = m_onMouseR = m_onMouseM =false;
	m_flag = -1;
	m_pickedObjectId  = -1;
	m_grabForce = grabForce = EVec3f(0, 0, 0);
	
	m_objects.push_back(new RigidPlane (EVec3f(10, 1, 10), EVec3f(0, 0, 0)));
	m_objects.push_back(new RigidSphere(1.0f, 1.0f, EVec3f(0, 10, 0), EVec3f(0, 0, 0)));
}


void Score::BtnDownL(const EVec2i &p, OglForCLI *ogl)
{
	m_onMouseL = true;
	//ogl->BtnDown_Trans(p);

	//pick object
	ogl->GetCursorRay(p, m_rayPos, m_rayDir);
	for (int i = 0; i < m_objects.size(); ++i)
	{
		const bool isPicked = m_objects[i]->pickedObject(m_rayPos, m_rayDir);
		printf("isPicked = %d\n", isPicked);
		if (isPicked)
		{
			m_pickedObjectId = i;
			printf("m_pickedObjectId = %d\n", m_pickedObjectId);

		}
	}
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
	m_pickedObjectId = -1;
	m_grabForce = EVec3f(0, 0, 0);
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
	if (!m_onMouseL && !m_onMouseR && !m_onMouseM && m_pickedObjectId != -1) return;

	if (m_pickedObjectId == -1) ogl->MouseMove(p);
	else
	{
		//grab
		ogl->GetCursorRay(p, m_rayPos, m_rayDir);
		const EVec3f objPos = m_objects[m_pickedObjectId]->GetPosition();
		const float depth = (objPos - m_rayPos).norm();
		const EVec3f targetPos = m_rayPos + m_rayDir * depth;
		m_grabForce = targetPos - objPos;
	}

}



void Score::StepTime()
{
	for (int i = 0; i < m_objects.size(); ++i)
	{
		m_objects[i]->StepSimulation(m_grabForce);
	}
	MainForm_RedrawMainPanel();
}

void Score::OnDraw()
{
	glDisable(GL_LIGHTING);
	for (int i = 0; i < m_objects.size(); ++i)
	{
		m_objects[i]->DrawObject();
	}
}
