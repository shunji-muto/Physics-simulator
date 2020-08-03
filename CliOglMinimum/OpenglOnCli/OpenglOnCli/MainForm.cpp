#include "stdafx.h"
#include <iostream>

#include "MainForm.h"
#include "EventManager.h"


using namespace OpenglOnCli;

#pragma comment( lib, "opengl32.lib" )
#pragma comment( lib, "glu32.lib" )
#pragma comment( lib, "gdi32.lib" )
#pragma comment( lib, "User32.lib" )











//double buffering用のハック
//https://www.codeproject.com/Questions/226895/Double-buffered-painting-of-a-panel
public ref class MyPanel :  public System::Windows::Forms::Panel
{
public:
    void SetStyle(System::Windows::Forms::ControlStyles flag, System::Boolean value)
    {
        System::Windows::Forms::Control::SetStyle(flag, value);
    }
};


static void CALLBACK MyTimerProc(
  HWND hWnd,           // handle of CWnd that called SetTimer
  UINT nMsg,           // WM_TIMER
  UINT_PTR nIDEvent,   // timer identification
  DWORD dwTime         // system time
)
{
  EventManager::GetInst()->Step();
}




MainForm::MainForm(void)
{
  m_ogl = 0;
  InitializeComponent();
  m_ogl = new OglForCLI(GetDC((HWND)m_main_panel->Handle.ToPointer()));
  SetTimer((HWND)m_main_panel->Handle.ToPointer(), 1, 30, &MyTimerProc);
}



System::Void MainForm::m_main_panel_Paint(
    System::Object^  sender, 
    System::Windows::Forms::PaintEventArgs^  e)
{
  RedrawMainPanel();
}



System::Void MainForm::m_main_panel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
  if (e->Button == System::Windows::Forms::MouseButtons::Left  ) 
    EventManager::GetInst()->BtnDownLeft( e->X, e->Y , m_ogl );
  if (e->Button == System::Windows::Forms::MouseButtons::Middle) 
    EventManager::GetInst()->BtnDownMiddle( e->X, e->Y , m_ogl );
  if (e->Button == System::Windows::Forms::MouseButtons::Right ) 
    EventManager::GetInst()->BtnDownRight( e->X, e->Y , m_ogl );
}

System::Void MainForm::m_main_panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
  EventManager::GetInst()->MouseMove( e->X, e->Y , m_ogl );
}

System::Void MainForm::m_main_panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
  if (e->Button == System::Windows::Forms::MouseButtons::Left  ) 
    EventManager::GetInst()->BtnUpLeft( e->X, e->Y , m_ogl );
  if (e->Button == System::Windows::Forms::MouseButtons::Middle) 
    EventManager::GetInst()->BtnUpMiddle( e->X, e->Y , m_ogl );
  if (e->Button == System::Windows::Forms::MouseButtons::Right ) 
    EventManager::GetInst()->BtnUpRight( e->X, e->Y , m_ogl );
}


System::Void MainForm::m_main_panel_Resize(System::Object^  sender, System::EventArgs^  e)
{
}

System::Void MainForm::MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
  std::cout << (int) e->KeyCode << "\n";
}


System::Void MainForm::MainForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{

}

System::Void MainForm::GenerateButton_Click(System::Object^  sender, System::EventArgs^  e)
{
  EventManager::GetInst()->ClickGenerateBtn();
}




void MainForm::RedrawMainPanel()
{
  static bool isFirst = true;

  if (isFirst)
  {
    isFirst = false;

    m_ogl->SetBgColor(0.8f, 0.8f, 0.8f, 0.5f);
    m_ogl->SetCam(EVec3f(0, 10, -30), EVec3f(0, 0, 0), EVec3f(0, 1, 0));
  }

  float  fovY     = 45.0;
  float  nearDist = 0.1f;
  float  farDist  = 1000.0f;
  m_ogl->OnDrawBegin(m_main_panel->Width, m_main_panel->Height,   
                     fovY, nearDist, farDist);
  
  EventManager::GetInst()->DrawScene();


  m_ogl->OnDrawEnd();
}
