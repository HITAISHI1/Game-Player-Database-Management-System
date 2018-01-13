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
	/// Summary for Form4
	/// </summary>
	public ref class Form4 : public System::Windows::Forms::Form
	{
	public:

		void Show_all()
		{String^ constring=L"datasource=localhost;port=3306;username=root;password=password";
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
				LoadNewPict(int::Parse(rank_txt->Text));
				myReader->Close();
				if(String::Compare(rank_txt->Text,"0")==0)
					{this->unlocks_grd->Rows->Add("NAN");
					 this->title_lbl->Text="NAN";
					}
				else
				{cmdDataBase=gcnew MySqlCommand("select unlocks,title from database.rank where rank<="+this->rank_txt->Text+";",conDataBase);
				 myReader=cmdDataBase->ExecuteReader();
				 while(myReader->Read()){
					  this->unlocks_grd->Rows->Add(myReader->GetString(0));
					  this->title_lbl->Text=""+(myReader->GetString(1));
					  }
				 }
				 }catch(Exception^ ex)
				 {MessageBox::Show(ex->Message);
				 }
		}

		Form4(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Form4(String^ str)
		{InitializeComponent();
		 this->username_txt->Text=str;
		 Show_all();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form4()
		{
			if (components)
			{
				delete components;
			}
			this->Close();
		}
	private: System::Windows::Forms::TextBox^  username_txt;
	private: System::Windows::Forms::TextBox^  kills_txt;


	private: System::Windows::Forms::TextBox^  deaths_txt;
	private: System::Windows::Forms::TextBox^  headshots_txt;
	private: System::Windows::Forms::TextBox^  score_txt;
	private: System::Windows::Forms::TextBox^  kdr_txt;
	private: System::Windows::Forms::TextBox^  rank_txt;
	protected: 

	protected: 






	private: System::Windows::Forms::Label^  username_lbl;
	private: System::Windows::Forms::Label^  kills_lbl;
	private: System::Windows::Forms::Label^  deaths_lbl;
	private: System::Windows::Forms::Label^  headshots_lbl;
	private: System::Windows::Forms::Label^  score_lbl;
	private: System::Windows::Forms::Label^  kdr_lbl;
	private: System::Windows::Forms::Label^  rank_lbl;
	private: System::Windows::Forms::TextBox^  kill_ribbons_txt;
	private: System::Windows::Forms::TextBox^  headshot_ribbons_txt;
	private: System::Windows::Forms::TextBox^  kill_medals_txt;
	private: System::Windows::Forms::TextBox^  headshot_medals_txt;
	private: System::Windows::Forms::Label^  kill_ribbons_lbl;
	private: System::Windows::Forms::Label^  headshot_ribbons_lbl;
	private: System::Windows::Forms::Label^  kill_medals_lbl;
	private: System::Windows::Forms::Label^  headshot_medals_lbl;
	private: System::Windows::Forms::Label^  performance_lbl;
private: System::Windows::Forms::GroupBox^  rank_grp;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::DataGridView^  unlocks_grd;

private: System::Windows::Forms::Label^  title_lbl;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  unlocks_clm;












	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	void LoadNewPict(int rank)  
   {  
      // You should replace the bold image   
      // in the sample below with an icon of your own choosing.
      pictureBox1->Image = Image::FromFile(String::Concat(System::Environment::GetFolderPath(System::Environment::SpecialFolder::Personal),"\\ranks\\P0"+rank+".png"));  
   }  

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->username_txt = (gcnew System::Windows::Forms::TextBox());
			this->kills_txt = (gcnew System::Windows::Forms::TextBox());
			this->deaths_txt = (gcnew System::Windows::Forms::TextBox());
			this->headshots_txt = (gcnew System::Windows::Forms::TextBox());
			this->score_txt = (gcnew System::Windows::Forms::TextBox());
			this->kdr_txt = (gcnew System::Windows::Forms::TextBox());
			this->rank_txt = (gcnew System::Windows::Forms::TextBox());
			this->username_lbl = (gcnew System::Windows::Forms::Label());
			this->kills_lbl = (gcnew System::Windows::Forms::Label());
			this->deaths_lbl = (gcnew System::Windows::Forms::Label());
			this->headshots_lbl = (gcnew System::Windows::Forms::Label());
			this->score_lbl = (gcnew System::Windows::Forms::Label());
			this->kdr_lbl = (gcnew System::Windows::Forms::Label());
			this->rank_lbl = (gcnew System::Windows::Forms::Label());
			this->kill_ribbons_txt = (gcnew System::Windows::Forms::TextBox());
			this->headshot_ribbons_txt = (gcnew System::Windows::Forms::TextBox());
			this->kill_medals_txt = (gcnew System::Windows::Forms::TextBox());
			this->headshot_medals_txt = (gcnew System::Windows::Forms::TextBox());
			this->kill_ribbons_lbl = (gcnew System::Windows::Forms::Label());
			this->headshot_ribbons_lbl = (gcnew System::Windows::Forms::Label());
			this->kill_medals_lbl = (gcnew System::Windows::Forms::Label());
			this->headshot_medals_lbl = (gcnew System::Windows::Forms::Label());
			this->performance_lbl = (gcnew System::Windows::Forms::Label());
			this->rank_grp = (gcnew System::Windows::Forms::GroupBox());
			this->title_lbl = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->unlocks_grd = (gcnew System::Windows::Forms::DataGridView());
			this->unlocks_clm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rank_grp->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->unlocks_grd))->BeginInit();
			this->SuspendLayout();
			// 
			// username_txt
			// 
			this->username_txt->Location = System::Drawing::Point(112, 68);
			this->username_txt->Name = L"username_txt";
			this->username_txt->ReadOnly = true;
			this->username_txt->Size = System::Drawing::Size(219, 22);
			this->username_txt->TabIndex = 0;
			// 
			// kills_txt
			// 
			this->kills_txt->Location = System::Drawing::Point(12, 139);
			this->kills_txt->Name = L"kills_txt";
			this->kills_txt->ReadOnly = true;
			this->kills_txt->Size = System::Drawing::Size(100, 22);
			this->kills_txt->TabIndex = 1;
			// 
			// deaths_txt
			// 
			this->deaths_txt->Location = System::Drawing::Point(154, 139);
			this->deaths_txt->Name = L"deaths_txt";
			this->deaths_txt->ReadOnly = true;
			this->deaths_txt->Size = System::Drawing::Size(100, 22);
			this->deaths_txt->TabIndex = 2;
			// 
			// headshots_txt
			// 
			this->headshots_txt->Location = System::Drawing::Point(305, 139);
			this->headshots_txt->Name = L"headshots_txt";
			this->headshots_txt->ReadOnly = true;
			this->headshots_txt->Size = System::Drawing::Size(100, 22);
			this->headshots_txt->TabIndex = 3;
			// 
			// score_txt
			// 
			this->score_txt->Location = System::Drawing::Point(476, 139);
			this->score_txt->Name = L"score_txt";
			this->score_txt->ReadOnly = true;
			this->score_txt->Size = System::Drawing::Size(100, 22);
			this->score_txt->TabIndex = 4;
			// 
			// kdr_txt
			// 
			this->kdr_txt->Location = System::Drawing::Point(12, 237);
			this->kdr_txt->Name = L"kdr_txt";
			this->kdr_txt->ReadOnly = true;
			this->kdr_txt->Size = System::Drawing::Size(100, 22);
			this->kdr_txt->TabIndex = 5;
			// 
			// rank_txt
			// 
			this->rank_txt->Location = System::Drawing::Point(132, 237);
			this->rank_txt->Name = L"rank_txt";
			this->rank_txt->ReadOnly = true;
			this->rank_txt->Size = System::Drawing::Size(100, 22);
			this->rank_txt->TabIndex = 6;
			// 
			// username_lbl
			// 
			this->username_lbl->AutoSize = true;
			this->username_lbl->Location = System::Drawing::Point(12, 68);
			this->username_lbl->Name = L"username_lbl";
			this->username_lbl->Size = System::Drawing::Size(73, 17);
			this->username_lbl->TabIndex = 7;
			this->username_lbl->Text = L"Username";
			// 
			// kills_lbl
			// 
			this->kills_lbl->AutoSize = true;
			this->kills_lbl->Location = System::Drawing::Point(12, 108);
			this->kills_lbl->Name = L"kills_lbl";
			this->kills_lbl->Size = System::Drawing::Size(33, 17);
			this->kills_lbl->TabIndex = 8;
			this->kills_lbl->Text = L"Kills";
			// 
			// deaths_lbl
			// 
			this->deaths_lbl->AutoSize = true;
			this->deaths_lbl->Location = System::Drawing::Point(151, 108);
			this->deaths_lbl->Name = L"deaths_lbl";
			this->deaths_lbl->Size = System::Drawing::Size(53, 17);
			this->deaths_lbl->TabIndex = 9;
			this->deaths_lbl->Text = L"Deaths";
			// 
			// headshots_lbl
			// 
			this->headshots_lbl->AutoSize = true;
			this->headshots_lbl->Location = System::Drawing::Point(302, 108);
			this->headshots_lbl->Name = L"headshots_lbl";
			this->headshots_lbl->Size = System::Drawing::Size(76, 17);
			this->headshots_lbl->TabIndex = 10;
			this->headshots_lbl->Text = L"Headshots";
			// 
			// score_lbl
			// 
			this->score_lbl->AutoSize = true;
			this->score_lbl->Location = System::Drawing::Point(473, 108);
			this->score_lbl->Name = L"score_lbl";
			this->score_lbl->Size = System::Drawing::Size(45, 17);
			this->score_lbl->TabIndex = 11;
			this->score_lbl->Text = L"Score";
			// 
			// kdr_lbl
			// 
			this->kdr_lbl->AutoSize = true;
			this->kdr_lbl->Location = System::Drawing::Point(9, 200);
			this->kdr_lbl->Name = L"kdr_lbl";
			this->kdr_lbl->Size = System::Drawing::Size(68, 17);
			this->kdr_lbl->TabIndex = 12;
			this->kdr_lbl->Text = L"K/D Ratio";
			// 
			// rank_lbl
			// 
			this->rank_lbl->AutoSize = true;
			this->rank_lbl->Location = System::Drawing::Point(129, 200);
			this->rank_lbl->Name = L"rank_lbl";
			this->rank_lbl->Size = System::Drawing::Size(41, 17);
			this->rank_lbl->TabIndex = 13;
			this->rank_lbl->Text = L"Rank";
			// 
			// kill_ribbons_txt
			// 
			this->kill_ribbons_txt->Location = System::Drawing::Point(12, 339);
			this->kill_ribbons_txt->Name = L"kill_ribbons_txt";
			this->kill_ribbons_txt->ReadOnly = true;
			this->kill_ribbons_txt->Size = System::Drawing::Size(100, 22);
			this->kill_ribbons_txt->TabIndex = 14;
			// 
			// headshot_ribbons_txt
			// 
			this->headshot_ribbons_txt->Location = System::Drawing::Point(132, 339);
			this->headshot_ribbons_txt->Name = L"headshot_ribbons_txt";
			this->headshot_ribbons_txt->ReadOnly = true;
			this->headshot_ribbons_txt->Size = System::Drawing::Size(100, 22);
			this->headshot_ribbons_txt->TabIndex = 15;
			// 
			// kill_medals_txt
			// 
			this->kill_medals_txt->Location = System::Drawing::Point(12, 456);
			this->kill_medals_txt->Name = L"kill_medals_txt";
			this->kill_medals_txt->ReadOnly = true;
			this->kill_medals_txt->Size = System::Drawing::Size(100, 22);
			this->kill_medals_txt->TabIndex = 16;
			// 
			// headshot_medals_txt
			// 
			this->headshot_medals_txt->Location = System::Drawing::Point(132, 456);
			this->headshot_medals_txt->Name = L"headshot_medals_txt";
			this->headshot_medals_txt->ReadOnly = true;
			this->headshot_medals_txt->Size = System::Drawing::Size(100, 22);
			this->headshot_medals_txt->TabIndex = 17;
			// 
			// kill_ribbons_lbl
			// 
			this->kill_ribbons_lbl->AutoSize = true;
			this->kill_ribbons_lbl->Location = System::Drawing::Point(9, 298);
			this->kill_ribbons_lbl->Name = L"kill_ribbons_lbl";
			this->kill_ribbons_lbl->Size = System::Drawing::Size(82, 17);
			this->kill_ribbons_lbl->TabIndex = 18;
			this->kill_ribbons_lbl->Text = L"Kill Ribbons";
			// 
			// headshot_ribbons_lbl
			// 
			this->headshot_ribbons_lbl->AutoSize = true;
			this->headshot_ribbons_lbl->Location = System::Drawing::Point(129, 298);
			this->headshot_ribbons_lbl->Name = L"headshot_ribbons_lbl";
			this->headshot_ribbons_lbl->Size = System::Drawing::Size(125, 17);
			this->headshot_ribbons_lbl->TabIndex = 19;
			this->headshot_ribbons_lbl->Text = L"Headshot Ribbons";
			// 
			// kill_medals_lbl
			// 
			this->kill_medals_lbl->AutoSize = true;
			this->kill_medals_lbl->Location = System::Drawing::Point(9, 409);
			this->kill_medals_lbl->Name = L"kill_medals_lbl";
			this->kill_medals_lbl->Size = System::Drawing::Size(75, 17);
			this->kill_medals_lbl->TabIndex = 20;
			this->kill_medals_lbl->Text = L"Kill Medals";
			// 
			// headshot_medals_lbl
			// 
			this->headshot_medals_lbl->AutoSize = true;
			this->headshot_medals_lbl->Location = System::Drawing::Point(129, 409);
			this->headshot_medals_lbl->Name = L"headshot_medals_lbl";
			this->headshot_medals_lbl->Size = System::Drawing::Size(118, 17);
			this->headshot_medals_lbl->TabIndex = 21;
			this->headshot_medals_lbl->Text = L"Headshot Medals";
			// 
			// performance_lbl
			// 
			this->performance_lbl->AutoSize = true;
			this->performance_lbl->Location = System::Drawing::Point(302, 9);
			this->performance_lbl->Name = L"performance_lbl";
			this->performance_lbl->Size = System::Drawing::Size(113, 17);
			this->performance_lbl->TabIndex = 22;
			this->performance_lbl->Text = L"PERFORMANCE";
			// 
			// rank_grp
			// 
			this->rank_grp->Controls->Add(this->title_lbl);
			this->rank_grp->Controls->Add(this->pictureBox1);
			this->rank_grp->Location = System::Drawing::Point(620, 13);
			this->rank_grp->Name = L"rank_grp";
			this->rank_grp->Padding = System::Windows::Forms::Padding(3, 3, 3, 10);
			this->rank_grp->Size = System::Drawing::Size(321, 465);
			this->rank_grp->TabIndex = 23;
			this->rank_grp->TabStop = false;
			this->rank_grp->Text = L"Rank";
			// 
			// title_lbl
			// 
			this->title_lbl->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->title_lbl->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->title_lbl->Location = System::Drawing::Point(3, 438);
			this->title_lbl->Name = L"title_lbl";
			this->title_lbl->Size = System::Drawing::Size(315, 17);
			this->title_lbl->TabIndex = 1;
			this->title_lbl->Text = L"Title";
			this->title_lbl->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(10, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(305, 387);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// unlocks_grd
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->unlocks_grd->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->unlocks_grd->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->unlocks_clm});
			this->unlocks_grd->Location = System::Drawing::Point(260, 190);
			this->unlocks_grd->Name = L"unlocks_grd";
			this->unlocks_grd->RowTemplate->Height = 24;
			this->unlocks_grd->Size = System::Drawing::Size(343, 288);
			this->unlocks_grd->TabIndex = 24;
			// 
			// unlocks_clm
			// 
			this->unlocks_clm->HeaderText = L"Unlocks";
			this->unlocks_clm->Name = L"unlocks_clm";
			this->unlocks_clm->ReadOnly = true;
			this->unlocks_clm->Width = 200;
			// 
			// Form4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(951, 490);
			this->Controls->Add(this->unlocks_grd);
			this->Controls->Add(this->rank_grp);
			this->Controls->Add(this->performance_lbl);
			this->Controls->Add(this->headshot_medals_lbl);
			this->Controls->Add(this->kill_medals_lbl);
			this->Controls->Add(this->headshot_ribbons_lbl);
			this->Controls->Add(this->kill_ribbons_lbl);
			this->Controls->Add(this->headshot_medals_txt);
			this->Controls->Add(this->kill_medals_txt);
			this->Controls->Add(this->headshot_ribbons_txt);
			this->Controls->Add(this->kill_ribbons_txt);
			this->Controls->Add(this->rank_lbl);
			this->Controls->Add(this->kdr_lbl);
			this->Controls->Add(this->score_lbl);
			this->Controls->Add(this->headshots_lbl);
			this->Controls->Add(this->deaths_lbl);
			this->Controls->Add(this->kills_lbl);
			this->Controls->Add(this->username_lbl);
			this->Controls->Add(this->rank_txt);
			this->Controls->Add(this->kdr_txt);
			this->Controls->Add(this->score_txt);
			this->Controls->Add(this->headshots_txt);
			this->Controls->Add(this->deaths_txt);
			this->Controls->Add(this->kills_txt);
			this->Controls->Add(this->username_txt);
			this->Name = L"Form4";
			this->Text = L"Form4";
			this->rank_grp->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->unlocks_grd))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	};
}
