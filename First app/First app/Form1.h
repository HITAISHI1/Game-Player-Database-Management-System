#pragma once

#include "stdafx.h"
#include "Form2.h"
#include "Form3.h"
#include "Form4.h"
#include "Form5.h"

namespace Firstapp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

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
	private: System::Windows::Forms::Button^  login_btn;
	protected: 

	protected: 


	private: System::Windows::Forms::TextBox^  username_txt;
	private: System::Windows::Forms::TextBox^  password_txt;
	private: System::Windows::Forms::Label^  username_lbl;
	private: System::Windows::Forms::Label^  password_lbl;
	private: System::Windows::Forms::Button^  register_btn;
	private: System::Windows::Forms::CheckBox^  admin_login_chk;
	private: System::Windows::Forms::Label^  admin_password_lbl;
	private: System::Windows::Forms::TextBox^  admin_password_txt;
	private: System::Windows::Forms::Button^  admin_login_btn;
	public: System::Windows::Forms::GroupBox^  admin_grp;
	private: System::Windows::Forms::Button^  button1;
	public: 
	private: 






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
			this->login_btn = (gcnew System::Windows::Forms::Button());
			this->username_txt = (gcnew System::Windows::Forms::TextBox());
			this->password_txt = (gcnew System::Windows::Forms::TextBox());
			this->username_lbl = (gcnew System::Windows::Forms::Label());
			this->password_lbl = (gcnew System::Windows::Forms::Label());
			this->register_btn = (gcnew System::Windows::Forms::Button());
			this->admin_login_chk = (gcnew System::Windows::Forms::CheckBox());
			this->admin_password_lbl = (gcnew System::Windows::Forms::Label());
			this->admin_password_txt = (gcnew System::Windows::Forms::TextBox());
			this->admin_login_btn = (gcnew System::Windows::Forms::Button());
			this->admin_grp = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->admin_grp->SuspendLayout();
			this->SuspendLayout();
			// 
			// login_btn
			// 
			this->login_btn->Location = System::Drawing::Point(28, 147);
			this->login_btn->Name = L"login_btn";
			this->login_btn->Size = System::Drawing::Size(75, 37);
			this->login_btn->TabIndex = 2;
			this->login_btn->Text = L"Login";
			this->login_btn->UseVisualStyleBackColor = true;
			this->login_btn->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// username_txt
			// 
			this->username_txt->Location = System::Drawing::Point(104, 41);
			this->username_txt->Name = L"username_txt";
			this->username_txt->Size = System::Drawing::Size(166, 22);
			this->username_txt->TabIndex = 3;
			// 
			// password_txt
			// 
			this->password_txt->Location = System::Drawing::Point(104, 81);
			this->password_txt->Name = L"password_txt";
			this->password_txt->PasswordChar = '*';
			this->password_txt->Size = System::Drawing::Size(166, 22);
			this->password_txt->TabIndex = 4;
			// 
			// username_lbl
			// 
			this->username_lbl->AutoSize = true;
			this->username_lbl->Location = System::Drawing::Point(25, 46);
			this->username_lbl->Name = L"username_lbl";
			this->username_lbl->Size = System::Drawing::Size(73, 17);
			this->username_lbl->TabIndex = 5;
			this->username_lbl->Text = L"Username";
			// 
			// password_lbl
			// 
			this->password_lbl->AutoSize = true;
			this->password_lbl->Location = System::Drawing::Point(25, 86);
			this->password_lbl->Name = L"password_lbl";
			this->password_lbl->Size = System::Drawing::Size(69, 17);
			this->password_lbl->TabIndex = 6;
			this->password_lbl->Text = L"Password";
			// 
			// register_btn
			// 
			this->register_btn->Location = System::Drawing::Point(183, 147);
			this->register_btn->Name = L"register_btn";
			this->register_btn->Size = System::Drawing::Size(75, 37);
			this->register_btn->TabIndex = 7;
			this->register_btn->Text = L"Register";
			this->register_btn->UseVisualStyleBackColor = true;
			this->register_btn->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// admin_login_chk
			// 
			this->admin_login_chk->AutoSize = true;
			this->admin_login_chk->Location = System::Drawing::Point(45, 265);
			this->admin_login_chk->Name = L"admin_login_chk";
			this->admin_login_chk->Size = System::Drawing::Size(131, 21);
			this->admin_login_chk->TabIndex = 8;
			this->admin_login_chk->Text = L"Log in as Admin";
			this->admin_login_chk->UseVisualStyleBackColor = true;
			this->admin_login_chk->CheckedChanged += gcnew System::EventHandler(this, &Form1::Admin_login_chk_CheckedChanged);
			// 
			// admin_password_lbl
			// 
			this->admin_password_lbl->AutoSize = true;
			this->admin_password_lbl->Location = System::Drawing::Point(31, 27);
			this->admin_password_lbl->Name = L"admin_password_lbl";
			this->admin_password_lbl->Size = System::Drawing::Size(150, 17);
			this->admin_password_lbl->TabIndex = 9;
			this->admin_password_lbl->Text = L"Enter Admin Password";
			// 
			// admin_password_txt
			// 
			this->admin_password_txt->Location = System::Drawing::Point(33, 56);
			this->admin_password_txt->Name = L"admin_password_txt";
			this->admin_password_txt->PasswordChar = '*';
			this->admin_password_txt->Size = System::Drawing::Size(147, 22);
			this->admin_password_txt->TabIndex = 10;
			// 
			// admin_login_btn
			// 
			this->admin_login_btn->Location = System::Drawing::Point(34, 98);
			this->admin_login_btn->Name = L"admin_login_btn";
			this->admin_login_btn->Size = System::Drawing::Size(146, 23);
			this->admin_login_btn->TabIndex = 11;
			this->admin_login_btn->Text = L"Admin Login";
			this->admin_login_btn->UseVisualStyleBackColor = true;
			this->admin_login_btn->Click += gcnew System::EventHandler(this, &Form1::admin_login_btn_Click);
			// 
			// admin_grp
			// 
			this->admin_grp->Controls->Add(this->admin_password_lbl);
			this->admin_grp->Controls->Add(this->admin_login_btn);
			this->admin_grp->Controls->Add(this->admin_password_txt);
			this->admin_grp->Location = System::Drawing::Point(45, 292);
			this->admin_grp->Name = L"admin_grp";
			this->admin_grp->Size = System::Drawing::Size(200, 127);
			this->admin_grp->TabIndex = 12;
			this->admin_grp->TabStop = false;
			this->admin_grp->Text = L"Admin";
			this->admin_grp->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(45, 204);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 38);
			this->button1->TabIndex = 13;
			this->button1->Text = L"LeaderBoard";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 444);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->admin_grp);
			this->Controls->Add(this->admin_login_chk);
			this->Controls->Add(this->register_btn);
			this->Controls->Add(this->password_lbl);
			this->Controls->Add(this->username_lbl);
			this->Controls->Add(this->password_txt);
			this->Controls->Add(this->username_txt);
			this->Controls->Add(this->login_btn);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->admin_grp->ResumeLayout(false);
			this->admin_grp->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ constring=L"datasource=localhost;port=3306;username=root;password=password";
				 MySqlConnection^ conDataBase=gcnew MySqlConnection(constring);
				 MySqlCommand^ cmdDataBase=gcnew MySqlCommand("select * from database.login where username='"+this->username_txt->Text+"' and password ='"+this->password_txt->Text+"';",conDataBase);
				 MySqlDataReader^ myReader;
				 try{
					 conDataBase->Open();
					 myReader=cmdDataBase->ExecuteReader();
					 int flag=0;
					 while(myReader->Read()){
						 flag++;
						  
						 }
					 if(flag==0)
						{MessageBox::Show("Username and password not found");}
					 else  if(flag==1)
						{	this->Hide();							
							Form4^ f4=gcnew Form4(this->username_txt->Text);
							this->password_txt->Text="";
							f4->ShowDialog();
							Application::Exit();
							this->ShowDialog();
						}
					 else if(flag==2)
						{MessageBox::Show("Username and password is duplicate");}

				 }catch(Exception^ ex)
				 {MessageBox::Show(ex->Message);
				 }
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Hide();
			Form2^ f2=gcnew Form2();
			f2->ShowDialog();
			Application::Exit();
			this->ShowDialog();
		 }

private: System::Void Admin_login_chk_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (admin_login_chk->Checked)
				{admin_grp->Visible=true;
				}
			else
				{admin_grp->Visible=false;
				}
		 }


private: System::Void admin_login_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(String::Compare(admin_password_txt->Text,"password")==0)
				{this->Hide();
				 Form3^ f3=gcnew Form3();
				 f3->ShowDialog();
				 admin_password_txt->Text="";
				 Application::Exit();
				 this->ShowDialog();
				}
			 else
				{MessageBox::Show("Incorrect Password!!!!");
				}
		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 this->Hide();
				 Form5^ f5=gcnew Form5();
				 f5->ShowDialog();
				 Application::Exit();
				 this->ShowDialog();
		 }
};
}

