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
	/// Summary for Form3
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(void)
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
		~Form3()
		{
			if (components)
			{
				delete components;
			}
			this->Close();
		}
	private: System::Windows::Forms::Label^  usernmae_lbl;
	protected: 
	private: System::Windows::Forms::TextBox^  username_txt;
	private: System::Windows::Forms::Button^  find_btn;

	private: System::Windows::Forms::Label^  kills_lbl;

	private: System::Windows::Forms::Label^  death_lbl;
	private: System::Windows::Forms::Label^  headshots_lbl;
	private: System::Windows::Forms::Label^  kdr_lbl;
	private: System::Windows::Forms::Label^  score_lbl;
	private: System::Windows::Forms::Label^  rank_lbl;
	private: System::Windows::Forms::TextBox^  kills_txt;
	private: System::Windows::Forms::TextBox^  deaths_txt;
	private: System::Windows::Forms::TextBox^  headshots_txt;
	private: System::Windows::Forms::TextBox^  kdr_txt;
	private: System::Windows::Forms::TextBox^  score_txt;
	private: System::Windows::Forms::TextBox^  rank_txt;
	private: System::Windows::Forms::Label^  kill_ribbons_lbl;
	private: System::Windows::Forms::Label^  headshot_ribbons_lbl;
	private: System::Windows::Forms::Label^  kill_medals_lbl;
	private: System::Windows::Forms::Label^  headshot_medals_lbl;
	private: System::Windows::Forms::TextBox^  kill_ribbons_txt;
	private: System::Windows::Forms::TextBox^  headshot_ribbons_txt;

	private: System::Windows::Forms::TextBox^  kill_medals_txt;
	private: System::Windows::Forms::TextBox^  headshot_medals_txt;

	private: System::Windows::Forms::Button^  update_btn;
	




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
			this->usernmae_lbl = (gcnew System::Windows::Forms::Label());
			this->username_txt = (gcnew System::Windows::Forms::TextBox());
			this->kills_lbl = (gcnew System::Windows::Forms::Label());
			this->death_lbl = (gcnew System::Windows::Forms::Label());
			this->headshots_lbl = (gcnew System::Windows::Forms::Label());
			this->kdr_lbl = (gcnew System::Windows::Forms::Label());
			this->score_lbl = (gcnew System::Windows::Forms::Label());
			this->rank_lbl = (gcnew System::Windows::Forms::Label());
			this->kills_txt = (gcnew System::Windows::Forms::TextBox());
			this->deaths_txt = (gcnew System::Windows::Forms::TextBox());
			this->headshots_txt = (gcnew System::Windows::Forms::TextBox());
			this->kdr_txt = (gcnew System::Windows::Forms::TextBox());
			this->score_txt = (gcnew System::Windows::Forms::TextBox());
			this->rank_txt = (gcnew System::Windows::Forms::TextBox());
			this->kill_ribbons_lbl = (gcnew System::Windows::Forms::Label());
			this->headshot_ribbons_lbl = (gcnew System::Windows::Forms::Label());
			this->kill_medals_lbl = (gcnew System::Windows::Forms::Label());
			this->headshot_medals_lbl = (gcnew System::Windows::Forms::Label());
			this->kill_ribbons_txt = (gcnew System::Windows::Forms::TextBox());
			this->headshot_ribbons_txt = (gcnew System::Windows::Forms::TextBox());
			this->kill_medals_txt = (gcnew System::Windows::Forms::TextBox());
			this->headshot_medals_txt = (gcnew System::Windows::Forms::TextBox());
			this->update_btn = (gcnew System::Windows::Forms::Button());
			this->find_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// usernmae_lbl
			// 
			this->usernmae_lbl->AutoSize = true;
			this->usernmae_lbl->Location = System::Drawing::Point(22, 16);
			this->usernmae_lbl->Name = L"usernmae_lbl";
			this->usernmae_lbl->Size = System::Drawing::Size(111, 17);
			this->usernmae_lbl->TabIndex = 0;
			this->usernmae_lbl->Text = L"Enter Username";
			// 
			// username_txt
			// 
			this->username_txt->Location = System::Drawing::Point(150, 16);
			this->username_txt->Name = L"username_txt";
			this->username_txt->Size = System::Drawing::Size(129, 22);
			this->username_txt->TabIndex = 1;
			// 
			// kills_lbl
			// 
			this->kills_lbl->AutoSize = true;
			this->kills_lbl->Location = System::Drawing::Point(15, 86);
			this->kills_lbl->Name = L"kills_lbl";
			this->kills_lbl->Size = System::Drawing::Size(33, 17);
			this->kills_lbl->TabIndex = 3;
			this->kills_lbl->Text = L"Kills";
			// 
			// death_lbl
			// 
			this->death_lbl->AutoSize = true;
			this->death_lbl->Location = System::Drawing::Point(138, 86);
			this->death_lbl->Name = L"death_lbl";
			this->death_lbl->Size = System::Drawing::Size(53, 17);
			this->death_lbl->TabIndex = 4;
			this->death_lbl->Text = L"Deaths";
			// 
			// headshots_lbl
			// 
			this->headshots_lbl->AutoSize = true;
			this->headshots_lbl->Location = System::Drawing::Point(270, 86);
			this->headshots_lbl->Name = L"headshots_lbl";
			this->headshots_lbl->Size = System::Drawing::Size(76, 17);
			this->headshots_lbl->TabIndex = 5;
			this->headshots_lbl->Text = L"Headshots";
			// 
			// kdr_lbl
			// 
			this->kdr_lbl->AutoSize = true;
			this->kdr_lbl->Location = System::Drawing::Point(88, 173);
			this->kdr_lbl->Name = L"kdr_lbl";
			this->kdr_lbl->Size = System::Drawing::Size(68, 17);
			this->kdr_lbl->TabIndex = 6;
			this->kdr_lbl->Text = L"K/D Ratio";
			// 
			// score_lbl
			// 
			this->score_lbl->AutoSize = true;
			this->score_lbl->Location = System::Drawing::Point(402, 86);
			this->score_lbl->Name = L"score_lbl";
			this->score_lbl->Size = System::Drawing::Size(45, 17);
			this->score_lbl->TabIndex = 7;
			this->score_lbl->Text = L"Score";
			// 
			// rank_lbl
			// 
			this->rank_lbl->AutoSize = true;
			this->rank_lbl->Location = System::Drawing::Point(305, 173);
			this->rank_lbl->Name = L"rank_lbl";
			this->rank_lbl->Size = System::Drawing::Size(41, 17);
			this->rank_lbl->TabIndex = 8;
			this->rank_lbl->Text = L"Rank";
			// 
			// kills_txt
			// 
			this->kills_txt->Location = System::Drawing::Point(18, 125);
			this->kills_txt->Name = L"kills_txt";
			this->kills_txt->Size = System::Drawing::Size(100, 22);
			this->kills_txt->TabIndex = 9;
			// 
			// deaths_txt
			// 
			this->deaths_txt->Location = System::Drawing::Point(141, 125);
			this->deaths_txt->Name = L"deaths_txt";
			this->deaths_txt->Size = System::Drawing::Size(100, 22);
			this->deaths_txt->TabIndex = 10;
			// 
			// headshots_txt
			// 
			this->headshots_txt->Location = System::Drawing::Point(273, 125);
			this->headshots_txt->Name = L"headshots_txt";
			this->headshots_txt->Size = System::Drawing::Size(100, 22);
			this->headshots_txt->TabIndex = 11;
			// 
			// kdr_txt
			// 
			this->kdr_txt->Location = System::Drawing::Point(91, 206);
			this->kdr_txt->Name = L"kdr_txt";
			this->kdr_txt->ReadOnly = true;
			this->kdr_txt->Size = System::Drawing::Size(100, 22);
			this->kdr_txt->TabIndex = 12;
			// 
			// score_txt
			// 
			this->score_txt->Location = System::Drawing::Point(405, 125);
			this->score_txt->Name = L"score_txt";
			this->score_txt->Size = System::Drawing::Size(100, 22);
			this->score_txt->TabIndex = 13;
			// 
			// rank_txt
			// 
			this->rank_txt->Location = System::Drawing::Point(308, 206);
			this->rank_txt->Name = L"rank_txt";
			this->rank_txt->ReadOnly = true;
			this->rank_txt->Size = System::Drawing::Size(100, 22);
			this->rank_txt->TabIndex = 14;
			// 
			// kill_ribbons_lbl
			// 
			this->kill_ribbons_lbl->AutoSize = true;
			this->kill_ribbons_lbl->Location = System::Drawing::Point(88, 240);
			this->kill_ribbons_lbl->Name = L"kill_ribbons_lbl";
			this->kill_ribbons_lbl->Size = System::Drawing::Size(82, 17);
			this->kill_ribbons_lbl->TabIndex = 15;
			this->kill_ribbons_lbl->Text = L"Kill Ribbons";
			// 
			// headshot_ribbons_lbl
			// 
			this->headshot_ribbons_lbl->AutoSize = true;
			this->headshot_ribbons_lbl->Location = System::Drawing::Point(305, 240);
			this->headshot_ribbons_lbl->Name = L"headshot_ribbons_lbl";
			this->headshot_ribbons_lbl->Size = System::Drawing::Size(125, 17);
			this->headshot_ribbons_lbl->TabIndex = 16;
			this->headshot_ribbons_lbl->Text = L"Headshot Ribbons";
			// 
			// kill_medals_lbl
			// 
			this->kill_medals_lbl->AutoSize = true;
			this->kill_medals_lbl->Location = System::Drawing::Point(92, 310);
			this->kill_medals_lbl->Name = L"kill_medals_lbl";
			this->kill_medals_lbl->Size = System::Drawing::Size(75, 17);
			this->kill_medals_lbl->TabIndex = 17;
			this->kill_medals_lbl->Text = L"Kill Medals";
			// 
			// headshot_medals_lbl
			// 
			this->headshot_medals_lbl->AutoSize = true;
			this->headshot_medals_lbl->Location = System::Drawing::Point(305, 310);
			this->headshot_medals_lbl->Name = L"headshot_medals_lbl";
			this->headshot_medals_lbl->Size = System::Drawing::Size(118, 17);
			this->headshot_medals_lbl->TabIndex = 18;
			this->headshot_medals_lbl->Text = L"Headshot Medals";
			// 
			// kill_ribbons_txt
			// 
			this->kill_ribbons_txt->Location = System::Drawing::Point(91, 275);
			this->kill_ribbons_txt->Name = L"kill_ribbons_txt";
			this->kill_ribbons_txt->ReadOnly = true;
			this->kill_ribbons_txt->Size = System::Drawing::Size(100, 22);
			this->kill_ribbons_txt->TabIndex = 19;
			// 
			// headshot_ribbons_txt
			// 
			this->headshot_ribbons_txt->Location = System::Drawing::Point(308, 275);
			this->headshot_ribbons_txt->Name = L"headshot_ribbons_txt";
			this->headshot_ribbons_txt->ReadOnly = true;
			this->headshot_ribbons_txt->Size = System::Drawing::Size(100, 22);
			this->headshot_ribbons_txt->TabIndex = 20;
			// 
			// kill_medals_txt
			// 
			this->kill_medals_txt->Location = System::Drawing::Point(91, 340);
			this->kill_medals_txt->Name = L"kill_medals_txt";
			this->kill_medals_txt->ReadOnly = true;
			this->kill_medals_txt->Size = System::Drawing::Size(100, 22);
			this->kill_medals_txt->TabIndex = 21;
			// 
			// headshot_medals_txt
			// 
			this->headshot_medals_txt->Location = System::Drawing::Point(308, 340);
			this->headshot_medals_txt->Name = L"headshot_medals_txt";
			this->headshot_medals_txt->ReadOnly = true;
			this->headshot_medals_txt->Size = System::Drawing::Size(100, 22);
			this->headshot_medals_txt->TabIndex = 22;
			// 
			// update_btn
			// 
			this->update_btn->Location = System::Drawing::Point(58, 392);
			this->update_btn->Name = L"update_btn";
			this->update_btn->Size = System::Drawing::Size(406, 52);
			this->update_btn->TabIndex = 23;
			this->update_btn->Text = L"Update";
			this->update_btn->UseVisualStyleBackColor = true;
			this->update_btn->Click += gcnew System::EventHandler(this, &Form3::update_btn_Click);
			// 
			// find_btn
			// 
			this->find_btn->Location = System::Drawing::Point(308, 16);
			this->find_btn->Name = L"find_btn";
			this->find_btn->Size = System::Drawing::Size(75, 23);
			this->find_btn->TabIndex = 24;
			this->find_btn->Text = L"Find";
			this->find_btn->UseVisualStyleBackColor = true;
			this->find_btn->Click += gcnew System::EventHandler(this, &Form3::find_btn_Click);
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(539, 476);
			this->Controls->Add(this->find_btn);
			this->Controls->Add(this->update_btn);
			this->Controls->Add(this->headshot_medals_txt);
			this->Controls->Add(this->kill_medals_txt);
			this->Controls->Add(this->headshot_ribbons_txt);
			this->Controls->Add(this->kill_ribbons_txt);
			this->Controls->Add(this->headshot_medals_lbl);
			this->Controls->Add(this->kill_medals_lbl);
			this->Controls->Add(this->headshot_ribbons_lbl);
			this->Controls->Add(this->kill_ribbons_lbl);
			this->Controls->Add(this->rank_txt);
			this->Controls->Add(this->score_txt);
			this->Controls->Add(this->kdr_txt);
			this->Controls->Add(this->headshots_txt);
			this->Controls->Add(this->deaths_txt);
			this->Controls->Add(this->kills_txt);
			this->Controls->Add(this->rank_lbl);
			this->Controls->Add(this->score_lbl);
			this->Controls->Add(this->kdr_lbl);
			this->Controls->Add(this->headshots_lbl);
			this->Controls->Add(this->death_lbl);
			this->Controls->Add(this->kills_lbl);
			this->Controls->Add(this->username_txt);
			this->Controls->Add(this->usernmae_lbl);
			this->Name = L"Form3";
			this->Text = L"Form3";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void find_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			 		String^ constring=L"datasource=localhost;port=3306;username=root;password=password";
				    MySqlConnection^ conDataBase=gcnew MySqlConnection(constring);
					MySqlCommand^ cmdDataBase=gcnew MySqlCommand("select * from database.player where username='"+this->username_txt->Text+"';",conDataBase);
					MySqlDataReader^ myReader;
					 try{
					 conDataBase->Open();
					 myReader=cmdDataBase->ExecuteReader();
					 while(myReader->Read()){
						 kills_txt->Text=""+(myReader->GetInt32(1));
						 deaths_txt->Text=""+(myReader->GetInt32(2));
						 headshots_txt->Text=""+(myReader->GetInt32(3));

						 if(myReader->GetFloat(4)!=-1)
							kdr_txt->Text=""+(myReader->GetFloat(4));
						 else
							kdr_txt->Text="NAN";

						 score_txt->Text=""+(myReader->GetInt32(5));
						 rank_txt->Text=""+(myReader->GetInt32(6));						  
						 }
					 myReader->Close();
					 cmdDataBase=gcnew MySqlCommand("select * from database.ribbons where username='"+this->username_txt->Text+"';",conDataBase);
					 myReader=cmdDataBase->ExecuteReader();
					 while(myReader->Read()){
						 headshot_ribbons_txt->Text=""+(myReader->GetInt32(0));						 
						 kill_ribbons_txt->Text=""+(myReader->GetInt32(1));  
						 }
				myReader->Close();
				cmdDataBase=gcnew MySqlCommand("select * from database.medals where username='"+this->username_txt->Text+"';",conDataBase);
				myReader=cmdDataBase->ExecuteReader();
				while(myReader->Read()){
					headshot_medals_txt->Text=""+(myReader->GetInt32(1));						 
					kill_medals_txt->Text=""+(myReader->GetInt32(2));  
					}

				 }catch(Exception^ ex)
				 {MessageBox::Show(ex->Message);
				 }
		 }
private: System::Void update_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ constring=L"datasource=localhost;port=3306;username=root;password=password";
			 MySqlConnection^ conDataBase=gcnew MySqlConnection(constring);
			 String^ text;
			 if(int::Parse(deaths_txt->Text)!=0)
				{text=""+float(int::Parse(kills_txt->Text))/ int::Parse(deaths_txt->Text);}
			 else
				 text="-1";

			 MySqlCommand^ cmdDataBase=gcnew MySqlCommand("update database.player set kills="+kills_txt->Text+", deaths="+deaths_txt->Text+" ,headshots="+headshots_txt->Text+" ,kdr="+text+" ,score="+score_txt->Text+" , rank="+int::Parse(score_txt->Text)/100+" where username='"+this->username_txt->Text+"';",conDataBase);
			 MySqlDataReader^ myReader;
			 try{
					 conDataBase->Open();
					 myReader=cmdDataBase->ExecuteReader();
					 myReader->Close();

					 cmdDataBase=gcnew MySqlCommand("update database.ribbons set headshot="+int::Parse(headshots_txt->Text)/50+", kills="+int::Parse(kills_txt->Text)/50+" where username='"+this->username_txt->Text+"';",conDataBase);
					 myReader=cmdDataBase->ExecuteReader();
					 myReader->Close();

					 cmdDataBase=gcnew MySqlCommand("update database.medals m,database.ribbons r set m.headshot=r.headshot/10, m.kills=r.kills/10 where m.username=r.username and m.username='"+this->username_txt->Text+"';",conDataBase);
					 myReader=cmdDataBase->ExecuteReader();
					 

				 }catch(Exception^ ex)
				 {MessageBox::Show(ex->Message);
				 }


		 }
};
}
