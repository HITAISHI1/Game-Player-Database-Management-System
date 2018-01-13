#pragma once




namespace Firstapp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:

		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
			this->Close();
		}
	private: System::Windows::Forms::TextBox^  username_txt;

	protected: 

	protected: 


	private: System::Windows::Forms::Label^  username_lbl;


	private: System::Windows::Forms::Label^  password_lbl;

	private: System::Windows::Forms::Label^  repeat_password_lbl;
	private: System::Windows::Forms::TextBox^  password_txt;
	private: System::Windows::Forms::TextBox^  repeat_password_txt;
	private: System::Windows::Forms::Button^  register_btn;







	protected: 

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
			this->username_txt = (gcnew System::Windows::Forms::TextBox());
			this->username_lbl = (gcnew System::Windows::Forms::Label());
			this->password_lbl = (gcnew System::Windows::Forms::Label());
			this->repeat_password_lbl = (gcnew System::Windows::Forms::Label());
			this->password_txt = (gcnew System::Windows::Forms::TextBox());
			this->repeat_password_txt = (gcnew System::Windows::Forms::TextBox());
			this->register_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// username_txt
			// 
			this->username_txt->Location = System::Drawing::Point(141, 21);
			this->username_txt->Name = L"username_txt";
			this->username_txt->Size = System::Drawing::Size(164, 22);
			this->username_txt->TabIndex = 0;
			// 
			// username_lbl
			// 
			this->username_lbl->AutoSize = true;
			this->username_lbl->Location = System::Drawing::Point(13, 21);
			this->username_lbl->Name = L"username_lbl";
			this->username_lbl->Size = System::Drawing::Size(73, 17);
			this->username_lbl->TabIndex = 3;
			this->username_lbl->Text = L"Username";
			// 
			// password_lbl
			// 
			this->password_lbl->AutoSize = true;
			this->password_lbl->Location = System::Drawing::Point(13, 75);
			this->password_lbl->Name = L"password_lbl";
			this->password_lbl->Size = System::Drawing::Size(69, 17);
			this->password_lbl->TabIndex = 4;
			this->password_lbl->Text = L"Password";
			// 
			// repeat_password_lbl
			// 
			this->repeat_password_lbl->AutoSize = true;
			this->repeat_password_lbl->Location = System::Drawing::Point(16, 125);
			this->repeat_password_lbl->Name = L"repeat_password_lbl";
			this->repeat_password_lbl->Size = System::Drawing::Size(119, 17);
			this->repeat_password_lbl->TabIndex = 5;
			this->repeat_password_lbl->Text = L"Repeat Password";
			// 
			// password_txt
			// 
			this->password_txt->Location = System::Drawing::Point(141, 75);
			this->password_txt->Name = L"password_txt";
			this->password_txt->PasswordChar = '*';
			this->password_txt->Size = System::Drawing::Size(164, 22);
			this->password_txt->TabIndex = 6;
			// 
			// repeat_password_txt
			// 
			this->repeat_password_txt->Location = System::Drawing::Point(141, 125);
			this->repeat_password_txt->Name = L"repeat_password_txt";
			this->repeat_password_txt->PasswordChar = '*';
			this->repeat_password_txt->Size = System::Drawing::Size(164, 22);
			this->repeat_password_txt->TabIndex = 7;
			// 
			// register_btn
			// 
			this->register_btn->Location = System::Drawing::Point(141, 174);
			this->register_btn->Name = L"register_btn";
			this->register_btn->Size = System::Drawing::Size(75, 43);
			this->register_btn->TabIndex = 8;
			this->register_btn->Text = L"Register";
			this->register_btn->UseVisualStyleBackColor = true;
			this->register_btn->Click += gcnew System::EventHandler(this, &Form2::register_btn_Click_1);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(325, 229);
			this->Controls->Add(this->register_btn);
			this->Controls->Add(this->repeat_password_txt);
			this->Controls->Add(this->password_txt);
			this->Controls->Add(this->repeat_password_lbl);
			this->Controls->Add(this->password_lbl);
			this->Controls->Add(this->username_lbl);
			this->Controls->Add(this->username_txt);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void register_btn_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 			 	String^ constring=L"datasource=localhost;port=3306;username=root;password=password";
				 MySqlConnection^ conDataBase=gcnew MySqlConnection(constring);
				 if(username_txt->Text=="")
					{MessageBox::Show("Enter Username!!!");}
				 else if(password_txt->Text=="")
						{
							MessageBox::Show("Enter Password!!!");
						}
				 else if(String::Compare(password_txt->Text,repeat_password_txt->Text)!=0)
						{
							MessageBox::Show("Passwords do not match!!!!");
						}
				 else {
					   
					    try{
							
							MySqlCommand^ cmdDataBase=gcnew MySqlCommand("insert into database.login values('"+this->username_txt->Text+"','"+this->password_txt->Text+"') ;",conDataBase);
						    MySqlDataReader^ myReader;
							conDataBase->Open();
							myReader=cmdDataBase->ExecuteReader();
							myReader->Close();

							cmdDataBase=gcnew MySqlCommand("insert into database.player values('"+this->username_txt->Text+"',0,0,0,-1,0,0);",conDataBase);
						    myReader=cmdDataBase->ExecuteReader();
							myReader->Close();

							cmdDataBase=gcnew MySqlCommand("insert into database.ribbons values(0,0,'"+this->username_txt->Text+"');",conDataBase);
						    myReader=cmdDataBase->ExecuteReader();
							myReader->Close();

							cmdDataBase=gcnew MySqlCommand("insert into database.medals values('"+this->username_txt->Text+"',0,0);",conDataBase);
						    myReader=cmdDataBase->ExecuteReader();
							myReader->Close();

							this->Hide();
							//this->Close();
							Application::Exit();
							}catch(Exception^ ex)
								{MessageBox::Show(ex->Message);
								}
					   }
		 }
};
}
