#pragma once

#pragma unmanaged

#include "MainForm.h"
#include "RigidPlane.h"
#include "RigidSphere.h"

class Score
{
private:
	RigidPlane  *testPlane;
	RigidSphere *testSphere;

public:
	Score();

	static Score *getInst()
	{
		static Score *m_singleton = new Score();
		return m_singleton;
	}

	void OnDraw();

	void StepTime();
};

#pragma managed

