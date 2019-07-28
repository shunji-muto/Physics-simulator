#include "stdafx.h"
#include "OglForCLI.h"
#include "tmath.h"
#include "RigidPlane.h"
#include "Eigen"

RigidPlane::RigidPlane(const EVec3f &size, const EVec3f &position, const EVec3f &nomal)//, const EVec3f &rotation
{
	m_size = size;
	m_position = position;
	m_nomal = m_nomal;
	//m_rotation = rotation;
}

void RigidPlane::DrawObj()
{
	EVec3f vertPos0 = EVec3f(-m_size[0] / 2, m_size[1], -m_size[2] / 2) + m_position;
	EVec3f vertPos1 = EVec3f(-m_size[0] / 2, m_size[1], m_size[2] / 2) + m_position;
	EVec3f vertPos2 = EVec3f(m_size[0] / 2, m_size[1], m_size[2] / 2) + m_position;
	EVec3f vertPos3 = EVec3f(m_size[0] / 2, m_size[1], -m_size[2] / 2) + m_position;

	glBegin(GL_TRIANGLES);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3fv(vertPos0.data());
	glVertex3fv(vertPos1.data());
	glVertex3fv(vertPos2.data());
	
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3fv(vertPos0.data());
	glVertex3fv(vertPos2.data());
	glVertex3fv(vertPos3.data());

	glEnd();
}