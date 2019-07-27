#pragma once

#pragma unmanaged

#include "MainForm.h"
#include "RigidPlane.h"

class Score
{
private:
	RigidPlane* testPlane;

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

