#include "stdafx.h"
#include "OglForCLI.h"
#include "tmath.h"
#include "RigidPlane.h"

RigidPlane::RigidPlane(const EVec3f &size, const EVec3f &position, const EVec3f &nomal)
{
	m_size = size;
	m_position = position;
	m_nomal = m_nomal;
}

void RigidPlane::drawObj()
{
	
	glBegin(GL_TRIANGLES);

	glVertex3f( 0, 1,  0);
	glVertex3f(        0, 1, m_size[2]);
	glVertex3f(m_size[0], 1, m_size[0]);
	
	glVertex3f( 0, 1,  0);
	glVertex3f(m_size[0], 1,  0);
	glVertex3f(m_size[0], 1, m_size[2]);

	glEnd();
}
