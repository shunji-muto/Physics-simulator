#pragma once


#include "stdafx.h"
#include "MainForm.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "User32.lib")


using namespace SolidSimulator;

System::Void MainForm::m_main_panel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	RedrawMainPanel();
}
System::Void MainForm::m_main_panel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	m_bBtnDown = true;
	if (e->Button == System::Windows::Forms::MouseButtons::Left)   m_ogl->BtnDown_Trans(EVec2i(e->X, e->Y));
	if (e->Button == System::Windows::Forms::MouseButtons::Middle) m_ogl->BtnDown_Zoom(EVec2i(e->X, e->Y));
	if (e->Button == System::Windows::Forms::MouseButtons::Right)  m_ogl->BtnDown_Rot(EVec2i(e->X, e->Y));
}
System::Void MainForm::m_main_panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	m_ogl->BtnUp();
	m_bBtnDown = false;
}
System::Void MainForm::m_main_panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (m_bBtnDown)
	{
		m_ogl->MouseMove(EVec2i(e->X, e->Y));
		this->RedrawMainPanel();
	}
}
System::Void MainForm::MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	//未実装
}
System::Void MainForm::MainForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	//未実装
}
System::Void MainForm::MainForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	//未実装
}


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
