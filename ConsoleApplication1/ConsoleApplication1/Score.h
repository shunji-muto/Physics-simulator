#pragma once


#include "MainForm.h"
#include "RigidObject.h"
#include "vector"
#include "OglForCLI.h"
#include "Eigen"

#pragma unmanaged

class Score
{
private:
	bool m_onMouseL, m_onMouseR, m_onMouseM;
	int  m_pickedObjectId, m_flag;
	EVec3f m_rayPos, m_rayDir, m_grabForce, grabForce;
	std::vector<RigidObject*> m_objects;
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

