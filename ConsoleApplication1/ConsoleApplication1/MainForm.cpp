#pragma once


#include "stdafx.h"
#include "MainForm.h"


#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "User32.lib")


using namespace SolidSimulator;

MainForm::MainForm()
{
	m_bBtnDown = false;
	m_ogl = 0;
	InitializeComponent();
	m_ogl = new OglForCLI(GetDC((HWND)m_main_panel->Handle.ToPointer()));
}


///<summary>
///レンダリング関数
///</summary>
void MainForm::RedrawMainPanel()
{
	float fovY = 45.0;
	float nearDist = 0.1f;
	float farDist = 1000.0f;
	m_ogl->OnDrawBegin(m_main_panel->Width, m_main_panel->Height, fovY, nearDist, farDist);

	//ここにレンダリングルーチンを書く
	glBegin(GL_LINES);
	glColor3d(1, 0, 0); glVertex3d(0, 0, 0); glVertex3d(10, 0, 0);
	glColor3d(0, 1, 0); glVertex3d(0, 0, 0); glVertex3d(0, 10, 0);
	glColor3d(0, 0, 1); glVertex3d(0, 0, 0); glVertex3d(0, 0, 10);
	glEnd();

	m_ogl->OnDrawEnd();
}


