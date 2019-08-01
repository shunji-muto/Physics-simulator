#pragma once


#include "MainForm.h"
#include "RigidObject.h"
#include "vector"
#include "OglForCLI.h"

#pragma unmanaged

class Score
{
private:
	bool m_onMouseL, m_onMouseR, m_onMouseM; 
	RigidSphere *testSphere;
	EVec3f camPos;
	////object
	//EVec3f m_pos, m_vel;
	//float m_radius; 

	////picking 
	//bool   m_isPicking;
	//EVec3f m_pickPos;

	//int  m_pickedObjectId;
	//ゆかかく
	//球かく
	//球ぴっくする
	//球動かす
	//球引っ張る

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

