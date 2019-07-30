#include "stdafx.h"
#include "RigidObject.h"


RigidSphere::RigidSphere(const float &massa, const float &radius, const EVec3f &position, const EVec3f &velocity)
{
	m_massa = massa;
	m_radius   = radius;
	m_position = position;
	m_velocity = velocity;

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
			m_normals.push_back(EVec3f(x, y, z) / m_radius);
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


float RigidSphere::GetRadius()
{
	return m_radius;
}


void RigidSphere::StepSimulation(const EVec3f &externalForce)
{
	const float  dt      = 0.01f;
	//const EVec3f totalForce = externalForce + gravity * m_massa;
	const EVec3f totalForce = externalForce;

	//f->a(F=m*a)
	EVec3f acceleration = totalForce / m_massa;

	//a->v
	m_velocity += dt * acceleration;

	//v->pos
	m_position += dt * m_velocity;

	if( (m_position[1] - m_radius) < 0) m_velocity[1] = -m_velocity[1];
}



bool RigidSphere::pickedObject(const EVec3f &rayPos, const EVec3f &rayDir)
{
	const EVec3f h = rayPos + (m_position - rayPos).dot(rayDir)*rayDir;
	const float distance = (h - m_position).norm();
	const bool isPicked = distance < m_radius;
	return isPicked;
}


void RigidSphere::DrawObject()
{
	/*float   shin[1] = { 64 };
	EVec4f  spec(1, 1, 1, 0.5), diff(0.5f, 0.5f, 0.5f, 0.5f), ambi(0.5f, 0.5f, 0.5f, 0.5f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec.data());
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff.data());
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi.data());
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);
*/
	glTranslated(m_position[0], m_position[1], m_position[2]);

	//描画
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < m_polygonIds.size(); ++i)
	{
		const int i0 = m_polygonIds[i][0];
		const int i1 = m_polygonIds[i][1];
		const int i2 = m_polygonIds[i][2];
		 
		glColor3f(1.0f, 0.0f, 0.0f);
		glNormal3fv(m_normals[i0].data());
		glVertex3fv(m_vertexs[i0].data());
		glNormal3fv(m_normals[i1].data());
		glVertex3fv(m_vertexs[i1].data());
		glNormal3fv(m_normals[i2].data());
		glVertex3fv(m_vertexs[i2].data());
	}
	glEnd();
}