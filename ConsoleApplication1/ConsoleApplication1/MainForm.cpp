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
	if (e->Button == System::Windows::Forms::MouseButtons::Left)   Score::getInst()->BtnDownL(EVec2i(e->X, e->Y), m_ogl);
	if (e->Button == System::Windows::Forms::MouseButtons::Middle) Score::getInst()->BtnDownM(EVec2i(e->X, e->Y), m_ogl);
	if (e->Button == System::Windows::Forms::MouseButtons::Right)  Score::getInst()->BtnDownR(EVec2i(e->X, e->Y), m_ogl);
}
System::Void MainForm::m_main_panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left)   Score::getInst()->BtnUpL(EVec2i(e->X, e->Y), m_ogl);
	if (e->Button == System::Windows::Forms::MouseButtons::Middle) Score::getInst()->BtnUpM(EVec2i(e->X, e->Y), m_ogl);
	if (e->Button == System::Windows::Forms::MouseButtons::Right)  Score::getInst()->BtnUpR(EVec2i(e->X, e->Y), m_ogl);
}
System::Void MainForm::m_main_panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
		Score::getInst()->MouseMove(EVec2i(e->X, e->Y), m_ogl);
}
System::Void MainForm::MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	//–¢À‘•
}
System::Void MainForm::MainForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	//–¢À‘•
}
System::Void MainForm::MainForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	//–¢À‘•
}


///<summary>
///ƒŒƒ“ƒ_ƒŠƒ“ƒOŠÖ”
///</summary>
void MainForm::RedrawMainPanel()
{
	static bool isFirst = true;
	if (isFirst)
	{
		isFirst = false;

		m_ogl->SetCam(EVec3f(5, 10, 30), EVec3f(0, 0, 0), EVec3f(0, 1, 0));
	}

	m_ogl->OnDrawBegin(m_main_panel->Width, m_main_panel->Height, 45.0, 0.1f, 1000);
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
	m_ogl = 0;
	InitializeComponent();
	m_ogl = new OglForCLI(GetDC((HWND)m_main_panel->Handle.ToPointer()));
	SetTimer((HWND)m_main_panel->Handle.ToPointer(), 1, 10, &MyTimerProc);
}
