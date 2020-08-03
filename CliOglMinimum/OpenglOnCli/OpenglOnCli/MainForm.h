#pragma once


#include "COMMON/OglForCLI.h"




namespace OpenglOnCli {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm の概要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

	private:
		MainForm(void);
    OglForCLI *m_ogl;  
  private: System::Windows::Forms::Button^  GenerateButton;


  private: 
    static MainForm^ m_singleton;

  public: 
    static MainForm^ GetInst() 
    {
      if (m_singleton == nullptr) m_singleton = gcnew MainForm();
      return m_singleton;
    }
    void RedrawMainPanel();




	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Panel^  m_main_panel;
  protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
      this->m_main_panel = (gcnew System::Windows::Forms::Panel());
      this->GenerateButton = (gcnew System::Windows::Forms::Button());
      this->SuspendLayout();
      // 
      // m_main_panel
      // 
      this->m_main_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
        | System::Windows::Forms::AnchorStyles::Left)
        | System::Windows::Forms::AnchorStyles::Right));
      this->m_main_panel->AutoSize = true;
      this->m_main_panel->Location = System::Drawing::Point(12, 12);
      this->m_main_panel->Name = L"m_main_panel";
      this->m_main_panel->Size = System::Drawing::Size(451, 407);
      this->m_main_panel->TabIndex = 0;
      this->m_main_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::m_main_panel_Paint);
      this->m_main_panel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::m_main_panel_MouseDown);
      this->m_main_panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::m_main_panel_MouseMove);
      this->m_main_panel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::m_main_panel_MouseUp);
      this->m_main_panel->Resize += gcnew System::EventHandler(this, &MainForm::m_main_panel_Resize);
      // 
      // GenerateButton
      // 
      this->GenerateButton->Location = System::Drawing::Point(388, 425);
      this->GenerateButton->Name = L"GenerateButton";
      this->GenerateButton->Size = System::Drawing::Size(75, 23);
      this->GenerateButton->TabIndex = 1;
      this->GenerateButton->Text = L"球を増やす";
      this->GenerateButton->UseVisualStyleBackColor = true;
      this->GenerateButton->Click += gcnew System::EventHandler(this, &MainForm::GenerateButton_Click);
      // 
      // MainForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(475, 451);
      this->Controls->Add(this->GenerateButton);
      this->Controls->Add(this->m_main_panel);
      this->Name = L"MainForm";
      this->Text = L"MainForm";
      this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
      this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void m_main_panel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
  private: System::Void m_main_panel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
  private: System::Void m_main_panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
  private: System::Void m_main_panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
  private: System::Void m_main_panel_Resize(System::Object^  sender, System::EventArgs^  e);
  private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
  private: System::Void MainForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
  private: System::Void GenerateButton_Click(System::Object^  sender, System::EventArgs^  e);
};

  inline void MainForm_RedrawPanel(){
    MainForm::GetInst()->RedrawMainPanel();
  }
}
