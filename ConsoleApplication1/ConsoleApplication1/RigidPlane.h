#pragma once

#pragma unmanaged



class RigidPlane
{
private:
	EVec3f m_size, m_position, m_nomal;
public:
	RigidPlane(const EVec3f &size, const EVec3f &position, const EVec3f &nomal);
	void drawObj();
};

#pragma managed


