#pragma once

extern void UpdateList(System::Windows::Forms::ListBox^);

namespace injector {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ProcessForm
	/// </summary>

	public ref class ProcessForm : public System::Windows::Forms::Form
	{
	public:
		ProcessForm(void)
		{
			InitializeComponent();
			UpdateList(this->listBox1);
		}

	protected:

		~ProcessForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ProcessForm::typeid));
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(0, 0);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(280, 199);
			this->listBox1->TabIndex = 0;
			this->listBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProcessForm::listBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(0, 200);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(280, 24);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Select";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ProcessForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(0, 224);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(280, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Refresh list";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ProcessForm::button2_Click);
			// 
			// ProcessForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(280, 248);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ProcessForm";
			this->Text = L"ProcessForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	public: static System::String^ selection;

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		listBox1->Items->Clear();
		UpdateList(this->listBox1);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		selection = listBox1->SelectedItem->ToString();
		delete this;
	}
	private: System::Void listBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == (char)0x0D || e->KeyChar == (char)0x20) button1_Click(sender, e);
		if (e->KeyChar == (char)0x1B) delete this;
	}
};
}