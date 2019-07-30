#pragma once

#include "stdio.h"
#include "OglForCLI.h"
#include "Score.h"



namespace SolidSimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		OglForCLI *m_ogl;
		bool m_bBtnDown;
		static MainForm^ m_singleton;
		MainForm::MainForm();
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
		System::Windows::Forms::Panel^  m_main_panel;
		System::ComponentModel::BackgroundWorker^  backgroundWorker1;
		System::ComponentModel::Container ^components;


	public:
		void RedrawMainPanel();
		static MainForm^ getInst()
		{
			if (m_singleton == nullptr) m_singleton = gcnew MainForm();
			return m_singleton;
		}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->m_main_panel = (gcnew System::Windows::Forms::Panel());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// m_main_panel
			// 
			this->m_main_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->m_main_panel->AutoSize = true;
			this->m_main_panel->Location = System::Drawing::Point(4, 2);
			this->m_main_panel->Name = L"m_main_panel";
			this->m_main_panel->Size = System::Drawing::Size(276, 257);
			this->m_main_panel->TabIndex = 0;
			this->m_main_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::m_main_panel_Paint);
			this->m_main_panel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::m_main_panel_MouseDown);
			this->m_main_panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::m_main_panel_MouseMove);
			this->m_main_panel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::m_main_panel_MouseUp);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->m_main_panel);
			this->Name = L"MainForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
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
	private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void MainForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e);
};

	inline void MainForm_RedrawMainPanel() 
	{
		MainForm::getInst()->RedrawMainPanel();
	}
}
