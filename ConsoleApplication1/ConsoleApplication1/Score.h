#pragma once

#pragma unmanaged

#include "MainForm.h"
#include "RigidPlane.h"
#include "RigidSphere.h"

class Score
{
private:
	bool m_onMouseL, m_onMouseR, m_onMouseM;
	int  m_pickedObjectId, m_pickedVertexId, m_flag;
	EVec3f m_rayPos, m_rayDir, m_grabForce, grabForce;
	
	RigidPlane  *testPlane;
	RigidSphere *testSphere;

	Score();

public:
	static Score *getInst()
	{
		static Score *m_singleton = new Score();
		return m_singleton;
	}

	void BtnDownL(const EVec2i &p, OglForCLI *ogl);
	void BtnDownR(const EVec2i &p, OglForCLI *ogl);
	void BtnDownM(const EVec2i &p, OglForCLI *ogl);
	void BtnUpL(const EVec2i &p, OglForCLI *ogl);
	void BtnUpR(const EVec2i &p, OglForCLI *ogl);
	void BtnUpM(const EVec2i &p, OglForCLI *ogl);
	void MouseMove(const EVec2i &p, OglForCLI *ogl);
	void OnDraw();
	void StepTime();
};

#pragma managed

