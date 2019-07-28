#include "stdafx.h"
#include "RigidSphere.h"
#include "tmath.h"
#include "OglForCLI.h"


RigidSphere::RigidSphere(const float &radius, const EVec3f &position)
{
	m_radius   = radius;
	m_position = position;

	const int stack = 8;//�o���i�c�j
	const int slice = 16;//�ܐ��i���j

	//���_���W���L��
	for (int i = 0; i <= slice; ++i)
	{
		const float phi = i / (float)slice;
		const float y   = cos((float)M_PI * phi) * m_radius;
		const float r   = sin((float)M_PI * phi) * m_radius;

		for (int j = 0; j <= stack; ++j)
		{
			const float pi = j / (float)stack;
			const float z = cos((float)M_PI * pi * 2) * r;
			const float x = sin((float)M_PI * pi * 2) * r;
		
			m_vertexs.push_back(EVec3f(x, y, z));
			//m_vertexs.push_back(EVec3f(x, y, z) / m_radius);
		}
	}

	//�O�p�`���`�����钸�_�̑g���L��
	for (int j = 0; j < slice; ++j)
	{
		for (int i = 0; i < stack; ++i)
		{
			const int vert0 = stack * j + i;
			const int vert1 = vert0 + 1;
			const int vert2 = vert0 + stack;
			const int vert3 = vert2 + 1;

			m_polygonIds.push_back(EVec3i(vert0, vert2, vert3));
			m_polygonIds.push_back(EVec3i(vert0, vert1, vert3));
		}
	}
}

void RigidSphere::DrawObj()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < m_polygonIds.size(); ++i)
	{
		const int i0 = m_polygonIds[i][0];
		const int i1 = m_polygonIds[i][1];
		const int i2 = m_polygonIds[i][2];

		glVertex3fv(m_vertexs[i0].data());
		glVertex3fv(m_vertexs[i1].data());
		glVertex3fv(m_vertexs[i2].data());
	}
	glEnd();
}