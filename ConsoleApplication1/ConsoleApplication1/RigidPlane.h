#pragma once

#pragma unmanaged



class RigidPlane
{
private:
	EVec3f m_size, m_position, m_nomal, m_rotation;
public:
	RigidPlane(const EVec3f &size, const EVec3f &position, const EVec3f &nomal);//, const EVec3f &rotation
	void DrawObj();
};

#pragma managed


