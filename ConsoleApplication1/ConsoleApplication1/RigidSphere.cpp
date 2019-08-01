#include "stdafx.h"
#include "RigidObject.h"


RigidSphere::RigidSphere(const float &radius, const EVec3f &position, const EVec3f &velocity)
{
	m_radius   = radius;
	m_position = position;
	m_velocity = velocity;
	m_isPicking = false;
	a = b = c = EVec3f(0, 0, 0);

	const int stack = 16;//経線（縦）
	const int slice = 32;//緯線（横）

	//頂点座標を記憶
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
		}
	}

	//三角形を形成する頂点の組を記憶
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


void RigidSphere::DrawObject()
{
	glTranslated(m_position[0], m_position[1], m_position[2]);

	//描画
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < m_polygonIds.size(); ++i)
	{
		const int i0 = m_polygonIds[i][0];
		const int i1 = m_polygonIds[i][1];
		const int i2 = m_polygonIds[i][2];

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3fv(m_vertexs[i0].data());
		glVertex3fv(m_vertexs[i1].data());
		glVertex3fv(m_vertexs[i2].data());
	}
	glEnd();
}


bool RigidSphere::IsPickedObject(const EVec3f &rayPos, const EVec3f &rayDir)
{
	EVec3f rayDirUnitVector = rayDir.normalized();
	EVec3f rayPos2objPos    = m_position - rayPos;
	float  innerProduct     = rayDirUnitVector.dot(rayPos2objPos);
	EVec3f projection       = innerProduct * rayDirUnitVector + rayPos;
	a = projection;
	b = m_position;
	c = rayPos;
	printf("球の位置: %f %f %f\n", m_position[0], m_position[1], m_position[2]);
	printf("射影: %f %f %f\n", projection[0], projection[1], projection[2]);
	float  distance = (m_position - projection).norm();
	printf("距離: %f\n", distance);

	const  bool isPicked = distance < m_radius;
	return isPicked;
}

void RigidSphere::IsPickedTrue()
{
	m_isPicking = true;
}
void RigidSphere::IsPickedFalse()
{
	m_isPicking = false;
}

bool RigidSphere::IsPicking()
{
	return m_isPicking;
}

