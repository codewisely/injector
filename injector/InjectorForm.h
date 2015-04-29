#pragma once
#include <string>
#include "ProcessForm.h"
extern bool Inject(System::String^ process, System::String^ dll);

namespace injector {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class InjectorForm : public System::Windows::Forms::Form
	{
	public:
		InjectorForm(void)
		{
			InitializeComponent();
			openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &injector::InjectorForm::OnFileOk);
		}

	protected:
		~InjectorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  injectButton;
	protected:



	private: System::Windows::Forms::TextBox^  processBox1;
	private: System::Windows::Forms::TextBox^  libraryBox1;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	public: System::Windows::Forms::Label^  statusLabel;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;
	protected:






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(InjectorForm::typeid));
			this->injectButton = (gcnew System::Windows::Forms::Button());
			this->processBox1 = (gcnew System::Windows::Forms::TextBox());
			this->libraryBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->statusLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// injectButton
			// 
			this->injectButton->Location = System::Drawing::Point(8, 136);
			this->injectButton->Name = L"injectButton";
			this->injectButton->Size = System::Drawing::Size(230, 31);
			this->injectButton->TabIndex = 0;
			this->injectButton->Text = L"Inject!";
			this->injectButton->UseVisualStyleBackColor = true;
			this->injectButton->Click += gcnew System::EventHandler(this, &InjectorForm::injectButton_Click);
			// 
			// processBox1
			// 
			this->processBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->processBox1->Location = System::Drawing::Point(6, 19);
			this->processBox1->Name = L"processBox1";
			this->processBox1->ReadOnly = true;
			this->processBox1->Size = System::Drawing::Size(218, 20);
			this->processBox1->TabIndex = 4;
			this->processBox1->Text = L"<click to choose>";
			this->processBox1->Click += gcnew System::EventHandler(this, &InjectorForm::processBox1_Click);
			this->processBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InjectorForm::processBox1_KeyPress);
			// 
			// libraryBox1
			// 
			this->libraryBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->libraryBox1->Location = System::Drawing::Point(6, 19);
			this->libraryBox1->Name = L"libraryBox1";
			this->libraryBox1->ReadOnly = true;
			this->libraryBox1->Size = System::Drawing::Size(218, 20);
			this->libraryBox1->TabIndex = 5;
			this->libraryBox1->Text = L"<click to browse>";
			this->libraryBox1->Click += gcnew System::EventHandler(this, &InjectorForm::libraryBox1_Click);
			this->libraryBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InjectorForm::libraryBox1_KeyPress);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->processBox1);
			this->groupBox1->Location = System::Drawing::Point(8, 8);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(232, 52);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Target process";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->libraryBox1);
			this->groupBox2->Location = System::Drawing::Point(8, 72);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(230, 52);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"DLL library";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"DLL files|*.dll";
			// 
			// statusLabel
			// 
			this->statusLabel->AutoSize = true;
			this->statusLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->statusLabel->ForeColor = System::Drawing::Color::Yellow;
			this->statusLabel->Location = System::Drawing::Point(80, 176);
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(89, 16);
			this->statusLabel->TabIndex = 8;
			this->statusLabel->Text = L"Initializing...";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(8, 176);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 16);
			this->label2->TabIndex = 9;
			this->label2->Text = L"STATUS:";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 600;
			this->timer1->Tick += gcnew System::EventHandler(this, &InjectorForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(248, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(62, 24);
			this->button1->TabIndex = 10;
			this->button1->Text = L"About";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &InjectorForm::button1_Click);
			// 
			// InjectorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(314, 201);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->injectButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"InjectorForm";
			this->Text = L"injecTyran";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: bool alreadyInjected;

private: System::Void libraryBox1_Click(System::Object^  sender, System::EventArgs^  e) {

	this->libraryBox1->Text = "";
	this->openFileDialog1->ShowDialog();

}

	void OnFileOk(System::Object ^sender, System::ComponentModel::CancelEventArgs ^e);
		 
private: System::Void injectButton_Click(System::Object^  sender, System::EventArgs^  e) {

	if (this->processBox1->Text == "" || this->processBox1->Text == "<click to choose>") {
		MessageBox::Show("Enter process name !");
		return;
	}
	if (this->libraryBox1->Text == "" || this->libraryBox1->Text == "<click to browse>") {
		MessageBox::Show("Enter library name !");
		return;
	}

	if (!this->libraryBox1->Text->Contains(".dll")) {
		MessageBox::Show("Invalid library selected!");
		return;
	}

	if (Inject(this->processBox1->Text, this->libraryBox1->Text) == true) alreadyInjected = true;
	else {
		alreadyInjected = false;
	}

}

private: System::Void processBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

	if (e->KeyChar == (char)0x0D || e->KeyChar == (char)0x20) processBox1_Click(sender, e);

}
private: System::Void libraryBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

	if (e->KeyChar == (char)0x0D || e->KeyChar == (char)0x20) libraryBox1_Click(sender, e);

}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (alreadyInjected){
		this->statusLabel->Text = "Injected!";
		this->statusLabel->ForeColor = Color::Green;
	}
	else {
		this->statusLabel->Text = "Not injected";
		this->statusLabel->ForeColor = Color::Red;
	}
}
private: System::Void processBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ procForm = gcnew ProcessForm();
	procForm->ShowDialog();
	processBox1->Text = ProcessForm::selection;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBoxA(0, "injecTyran\nSimple DLL injector\n\n(C) tyranek 2015", "About...", MB_OK | MB_ICONINFORMATION | MB_TASKMODAL);
}
};
}

void injector::InjectorForm::OnFileOk(System::Object ^sender, System::ComponentModel::CancelEventArgs ^e)
{
	libraryBox1->Text = openFileDialog1->FileName;
}
