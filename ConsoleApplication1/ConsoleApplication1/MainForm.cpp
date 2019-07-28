#pragma once


#include "stdafx.h"
#include "MainForm.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "User32.lib")


using namespace SolidSimulator;




///<summary>
///レンダリング関数
///</summary>
void MainForm::RedrawMainPanel()
{
	float fovY = 45.0;
	float nearDist = 0.1f;
	float farDist = 1000.0f;
	static bool  isFirst = true;
	
	if (isFirst)
	{
		isFirst = false;

		m_ogl->SetCam(EVec3f(5, 10, 30), EVec3f(0, 0, 0), EVec3f(0, 1, 0));
	}

	m_ogl->OnDrawBegin(m_main_panel->Width, m_main_panel->Height, fovY, nearDist, farDist);
	//ここにレンダリングルーチンを書く
	Score::getInst()->OnDraw();
	m_ogl->OnDrawEnd();
}


static void CALLBACK MyTimerProc(
	HWND hWnd,           // handle of CWnd that called SetTimer
	UINT nMsg,           // WM_TIMER
	UINT_PTR nIDEvent,   // timer identification
	DWORD dwTime         // system time
)
{
	Score::getInst()->StepTime();
}

MainForm::MainForm()
{
	m_bBtnDown = false;
	m_ogl = 0;
	InitializeComponent();
	m_ogl = new OglForCLI(GetDC((HWND)m_main_panel->Handle.ToPointer()));
	SetTimer((HWND)m_main_panel->Handle.ToPointer(), 1, 10, &MyTimerProc);
}
