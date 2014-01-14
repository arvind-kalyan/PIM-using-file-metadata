#pragma once
#include"Tools.h"
#include"newUser.h"
#using <System.dll>
#include <iostream>
#include <fstream>
#include"Main.h"

namespace gui {
	using namespace newUser;
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::IO;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: array< System::Windows::Forms::CheckBox^>^  checkBoxes;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Panel^  panel1;




	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::ToolStripMenuItem^  minimizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  restoreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  metadataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  printMetadataToConsoleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  restoreToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hashValueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  logoutAndExitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addUserToolStripMenuItem;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Panel^  panel2;

	private: System::Windows::Forms::TreeView^  treeView1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel3;
	private: array<String^>^ checklist;
	private: int chkCount;//length of checkbox array
	private: static Form1^ current;
	

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			
			current = this;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBoxes = gcnew array < System::Windows::Forms::CheckBox^>(20);
			this->checklist = gcnew array<String^>(20);
			this-> chkCount = GetRepository(checklist);
			for (int i = 0; i < this->chkCount; i++)
			{
				this->checkBoxes[i] = (gcnew System::Windows::Forms::CheckBox());
			}
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip());
			//this->contextMenuStrip1->SuspendLayout();
			this->printMetadataToConsoleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->minimizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->metadataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hashValueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restoreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restoreToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->logoutAndExitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addUserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(152, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(243, 21);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Remove";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(572, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(363, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = "Welcome "+GetCurrentUser()+" !";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Silver;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(12, 27);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(333, 351);
			this->panel1->TabIndex = 8;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			loadCheckBoxes();
			this->panel4->Location = System::Drawing::Point(3, 50);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(315, 281);
			this->panel4->TabIndex = 5;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->toolToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(969, 24);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				
					 this->restoreToolStripMenuItem, this->restoreToolStripMenuItem1, this->closeToolStripMenuItem,
					this->addUserToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// minimizeToolStripMenuItem
			// 
			this->minimizeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				
					this->fileToolStripMenuItem1,  this->hashValueToolStripMenuItem
			});
			this->minimizeToolStripMenuItem->Name = L"minimizeToolStripMenuItem";
			this->minimizeToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->minimizeToolStripMenuItem->Text = L"Share";
			this->minimizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::minimizeToolStripMenuItem_Click);
			// 
			// metadataToolStripMenuItem
			// 
			this->metadataToolStripMenuItem->Name = L"metadataToolStripMenuItem";
			this->metadataToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->metadataToolStripMenuItem->Text = L"Extract Metadata to File";
			this->metadataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::metadataToolStripMenuItem_Click);

			// 
			// fileToolStripMenuItem1
			// 
			this->fileToolStripMenuItem1->Name = L"fileToolStripMenuItem1";
			this->fileToolStripMenuItem1->Size = System::Drawing::Size(143, 22);
			this->fileToolStripMenuItem1->Text = L"File Copy";
			this->fileToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::fileToolStripMenuItem1_Click);

			// 
			// hashValueToolStripMenuItem
			// 
			this->hashValueToolStripMenuItem->Name = L"hashValueToolStripMenuItem";
			this->hashValueToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->hashValueToolStripMenuItem->Text = L"Hash Value";
			this->hashValueToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::hashToolStripMenuItem_Click);

			// 
			// restoreToolStripMenuItem
			// 
			this->restoreToolStripMenuItem->Name = L"restoreToolStripMenuItem";
			this->restoreToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->restoreToolStripMenuItem->Text = L"Logout";
			this->restoreToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::restoreToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->printMetadataToConsoleToolStripMenuItem });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(210, 48);
			// 
			// printMetadataToConsoleToolStripMenuItem
			// 
			this->printMetadataToConsoleToolStripMenuItem->Name = L"printMetadataToConsoleToolStripMenuItem";
			this->printMetadataToConsoleToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->printMetadataToConsoleToolStripMenuItem->Text = L"Print Metadata toConsole";
			this->printMetadataToConsoleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::pToolStripMenuItem_Click);



			// 
			// restoreToolStripMenuItem1
			// 
			this->restoreToolStripMenuItem1->Name = L"restoreToolStripMenuItem1";
			this->restoreToolStripMenuItem1->Size = System::Drawing::Size(135, 22);
			this->restoreToolStripMenuItem1->Text = L"Restore";
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->logoutAndExitToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			// 
			// logoutAndExitToolStripMenuItem
			// 
			this->logoutAndExitToolStripMenuItem->Name = L"logoutAndExitToolStripMenuItem";
			this->logoutAndExitToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->logoutAndExitToolStripMenuItem->Text = L"Logout and Exit";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->ShortcutKeyDisplayString = "Alt + F4";
			this->exitToolStripMenuItem->ShortcutKeys = Keys::Alt | Keys::F4;
			this->exitToolStripMenuItem->ShowShortcutKeys = true;
			this->exitToolStripMenuItem->ToolTipText = L"Exit without saving changes to User Account";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);

			// 
			// addUserToolStripMenuItem
			// 
			this->addUserToolStripMenuItem->Name = L"addUserToolStripMenuItem";
			this->addUserToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->addUserToolStripMenuItem->Text = L"Add User";
			this->addUserToolStripMenuItem->ShortcutKeyDisplayString = "Ctrl +N";
			this->addUserToolStripMenuItem->ShortcutKeys = Keys::Control | Keys::N;

			this->addUserToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::addUserToolStripMenuItem_Click);

			// 
			// toolToolStripMenuItem
			// 
			this->toolToolStripMenuItem->Name = L"toolToolStripMenuItem";
			this->toolToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->toolToolStripMenuItem->Text = L"Tools";
			this->toolToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {

				this->minimizeToolStripMenuItem, this->metadataToolStripMenuItem
			});
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::helpToolStripMenuItem_Click);
			
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(940, 0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(29, 24);
			this->button3->TabIndex = 12;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->HelpRequest += gcnew System::EventHandler(this, &Form1::folderBrowserDialog1_HelpRequest);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Wheat;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->treeView1);
			this->panel2->Location = System::Drawing::Point(351, 28);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(606, 350);
			this->panel2->TabIndex = 13;
			
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->textBox2);
			this->panel3->Location = System::Drawing::Point(4, 129);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(595, 214);
			this->panel3->TabIndex = 1;
			// 
			// tableLayoutPanel1
			// 
			this->textBox2->Location = System::Drawing::Point(4, 4);
			this->textBox2->Name = L"textBox1";
			this->textBox2->Multiline = true;
			this->textBox2->Size = System::Drawing::Size(595, 300);
			this->textBox2->TabIndex = 6;
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(4, 4);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(595, 118);
			this->treeView1->TabIndex = 0;
			this->treeView1->NodeMouseDoubleClick += gcnew System::Windows::Forms::TreeNodeMouseClickEventHandler(this, &Form1::treeView1_NodeMouseDoubleClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(969, 390);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"Form1";
			this->Text = L"File Management System";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

			Thread^ dirMonitor = gcnew Thread(gcnew ThreadStart(InitiateMonitor));
			dirMonitor->Start();

		}
#pragma endregion
		void loadCheckBoxes()
		{
			if (this->panel4->HasChildren)
			{
				int n = this->chkCount-1;
				for (int i = 0; i < chkCount; i++)
				{
					
						this->panel4->Controls->RemoveAt(n);
						n--;
				}
			}
			int k = 0;
			for (int i = 0; i < chkCount; i++)
			{

				if (this->checklist[i] != nullptr)
				{
					this->checkBoxes[i]->AutoSize = true;
					this->checkBoxes[i]->Name = L"checkBox1";
					this->checkBoxes[i]->Location = System::Drawing::Point(15, 25 * (k + 1));
					this->checkBoxes[i]->Size = System::Drawing::Size(88, 17);
					this->checkBoxes[i]->TabIndex = i;
					this->checkBoxes[i]->Text = checklist[i];
					this->checkBoxes[i]->UseVisualStyleBackColor = true;
					this->checkBoxes[i]->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_CheckedChanged);

					
					this->panel4->Controls->Add(this->checkBoxes[i]);
					k++;
				}
			}

		}

		bool checklistContains(String^ str)
		{
			
			for (int i = 0; i < this->chkCount; i++)
			{
				if (this->checklist[i] != nullptr && str->Contains(this->checklist[i]))
				{
					MessageBox::Show("Directory Already Added");
					return true;
				}
			}
			return false;

		}
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 if (SearchResult(textBox1->Text) == -1)
					 MessageBox::Show("No matches Found");
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 if (this->chkCount > 0)
				 {
					 int n = this->chkCount;
					 for (int i = 0; i < n; i++)
					 {
						 if (this->checkBoxes[i]!=nullptr && this->checkBoxes[i]->Checked)
						 {
							 treeView1->Nodes->RemoveByKey(checklist[i]);
							 RemoveRepository(checklist[i]);
							 this->checkBoxes[i] = nullptr;
							 this->checklist[i] = nullptr;
							 loadCheckBoxes();
							 this->chkCount--;


						 }
					 }
					 
				 }
				

			 }
	private: System::Void minimizeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }
	private: System::Void pToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 try{
					 String^ fn = FindAbsolutePath(current->treeView1->SelectedNode->Text, current->treeView1->SelectedNode->Parent->Text)->Replace("\\", "\\\\");
					 Console::WriteLine(PrintFileMetadata(fn));
					 MessageBox::Show("Metadata Printed on the Console");
				 }
				 catch (Exception^ e)
				 {
					 MessageBox::Show("No File Selected");
				 }

			 }
	private: System::Void restoreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 SetCurrentUser("none");
				 this->Close();

	}
	private: System::Void hashToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 try
				 {
					 String^ fn = FindAbsolutePath(current->treeView1->SelectedNode->Text, current->treeView1->SelectedNode->Parent->Text)->Replace("\\", "\\\\");
					 MessageBox::Show(GetHash(fn));
				 }
				 catch (Exception^ e)
				 {
					 MessageBox::Show("No File Selected");
				 }

			 }
	private: System::Void addUserToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 newUser1^ test = gcnew newUser1();
				 test->Show();
	}
    private: System::Void fileToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
				 folderBrowserDialog1->ShowDialog();
				 if (folderBrowserDialog1->SelectedPath->Length > 0)
				 {
					 try
					 {
						 String^ fn = FindAbsolutePath(current->treeView1->SelectedNode->Text, current->treeView1->SelectedNode->Parent->Text)->Replace("\\", "\\\\");

						 if (System::IO::File::Exists(fn))
						 {
							 System::IO::File::Copy(fn, folderBrowserDialog1->SelectedPath + current->treeView1->SelectedNode->Text, true);
							 MessageBox::Show("File Extracted");
						 }
						 else
							 MessageBox::Show("No File Found");
					 }
					 catch (Exception^ e)
					 {
						 MessageBox::Show("No File Selected");
					 }

				 }
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
			 folderBrowserDialog1->ShowDialog();
			 if (folderBrowserDialog1->SelectedPath->Length>0 && this->chkCount<19 && !checklistContains(folderBrowserDialog1->SelectedPath))
			 {
				 this->checkBoxes[this->chkCount] = (gcnew System::Windows::Forms::CheckBox());
				 this->checklist[this->chkCount] = folderBrowserDialog1->SelectedPath;
				 this->checkBoxes[this->chkCount]->AutoSize = true;
				 this->checkBoxes[this->chkCount]->Location = System::Drawing::Point(15, 25*(this->chkCount+1));
				 this->checkBoxes[this->chkCount]->Name = L"chkBox";
				 this->checkBoxes[this->chkCount]->Size = System::Drawing::Size(88, 17);
				 this->checkBoxes[this->chkCount]->TabIndex = this->chkCount;
				 this->checkBoxes[this->chkCount]->Text = this->checklist[this->chkCount];
				 this->checkBoxes[this->chkCount]->UseVisualStyleBackColor = true;
				 this->checkBoxes[this->chkCount]->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_CheckedChanged);

				 this->panel4->Controls->Add(this->checkBoxes[this->chkCount]);
				 AddRepository(this->checklist[this->chkCount]);
				 this->chkCount++;
				 
			 }
				
			 
		 }
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

}
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::Diagnostics::Process::Start("D:\\Projects\\C,C++,C\\FMS\\Resources\\manual.pdf");

}
private: System::Void metadataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 folderBrowserDialog1->ShowDialog();
			 if (folderBrowserDialog1->SelectedPath->Length > 0)
			 {
				 try{
					 char* path = (char*)(void*)Marshal::StringToHGlobalAnsi(folderBrowserDialog1->SelectedPath + "metadata.txt");
					 ofstream myfile;
					 myfile.open(path);
					 String^ fn = FindAbsolutePath(current->treeView1->SelectedNode->Text, current->treeView1->SelectedNode->Parent->Text)->Replace("\\", "\\\\");

					 myfile<< (char*)(void*)Marshal::StringToHGlobalAnsi(PrintFileMetadata(fn));
					 myfile.close();
				 }
				 catch (Exception^ e)
				 {
					 MessageBox::Show("No File Selected");
				 }
			 }

		 }
	private: System::Void checkBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
				 System::Windows::Forms::CheckBox^ chkd = safe_cast<System::Windows::Forms::CheckBox^>(sender);
				 DirectoryInfo^ dir = gcnew DirectoryInfo(chkd->Text);
				 if (chkd->Checked)
				 {
					 TreeNode^ init = gcnew TreeNode(chkd->Text);
					 
					 loadDirectory(dir, init);
				 }
				 else
				 {
					 treeView1->Nodes->RemoveByKey(dir->FullName);
					
					 
				 }
				 treeView1->EndUpdate();
				 
	
	}
			
			 delegate void SetTextCallback(String^ text);
			public: static void LogTextBox(String^ message){
						
						if (current->textBox2->InvokeRequired)
						{
							SetTextCallback^ d = gcnew SetTextCallback(LogTextBox);
							current->Invoke(d, message);
						}
						else
						{
							
							current->textBox2->Text += message + "\r\n";
							if (message->IndexOf(".")>=0)
								UpdateFileintoRepository(message);
							
						}
			 }

			
			 void loadDirectory(DirectoryInfo^ dir, TreeNode^ parent)
			 {
				 
				 try{

					 array<DirectoryInfo^>^directories = dir->GetDirectories();
					 array<FileInfo^>^files = dir->GetFiles();
					 System::Collections::IEnumerator^ Enum = directories->GetEnumerator();

					 array<TreeNode^>^ child = gcnew array < TreeNode^>(directories->Length + files->Length);
					 int i = 0;
					 while (Enum->MoveNext())
					 {

						 DirectoryInfo^ dInfo = safe_cast<DirectoryInfo^>(Enum->Current);
						 child[i] = gcnew TreeNode(dInfo->Name);
						 child[i]->ContextMenuStrip = contextMenuStrip1;
						 i++;

					 }
					 Enum = files->GetEnumerator();
					 while (Enum->MoveNext())
					 {

						 FileInfo^ fInfo = safe_cast<FileInfo^>(Enum->Current);
						 child[i] = gcnew TreeNode(fInfo->Name);
						 child[i]->ContextMenuStrip = contextMenuStrip1;
						 i++;

					 }

					 TreeNode^ Parent = parent->Parent;
					 TreeNode^ treeNode = gcnew TreeNode(dir->Name, child);
					 Enum = directories->GetEnumerator();
					 i = 0;
					 while (Enum->MoveNext())
					 {

						 DirectoryInfo^ dInfo = safe_cast<DirectoryInfo^>(Enum->Current);
						 loadDirectory(dInfo, child[i]);
						 i++;

					 }
					 if (Parent != nullptr){
						 Parent->Nodes->Remove(parent);
						 Parent->Nodes->Add(treeNode);

					 }
					 else
					 {
						 treeView1->Nodes->Remove(parent);
						 treeNode->Name = dir->FullName;

						 treeView1->Nodes->Add(treeNode);
						 treeView1->EndUpdate();
					 }


				 }
				 catch (Exception^ e)
				 {
					 MessageBox::Show(e->Message);
				 }
			 }
	private: System::Void treeView1_NodeMouseDoubleClick(System::Object^  sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^  e)
			{
						 if (e->Button == System::Windows::Forms::MouseButtons::Left){
							 try
							 {
								 // Look for a file extension. 
								 if (e->Node->Text->Contains("."))
								 {
									 String^ addr = FindAbsolutePath(e->Node->Text, e->Node->Parent->Text)->Replace("\\", "\\\\");
									 System::Diagnostics::Process::Start(addr);
								 }
							 }
							 // If the file is not found, handle the exception and inform the user. 
							 catch (Exception^ e)
							 {
								 MessageBox::Show(e->Message);
							 }
						 }
			}
	
};
}

