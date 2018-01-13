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
	/// Summary for Form5
	/// </summary>
	public ref class Form5 : public System::Windows::Forms::Form
	{
	public:
		Form5(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Show_all();

		}

	void Show_all()
		{String ^username,^score,^kdr,^rank;
			String^ constring=L"datasource=localhost;port=3306;username=root;password=password";
				    MySqlConnection^ conDataBase=gcnew MySqlConnection(constring);
					MySqlCommand^ cmdDataBase=gcnew MySqlCommand("select username,score,kdr,rank from database.player order by score desc;",conDataBase);
					MySqlDataReader^ myReader;
					 try{
					 conDataBase->Open();
					 myReader=cmdDataBase->ExecuteReader();
					 while(myReader->Read()){
						 username=""+(myReader->GetString(0));
						 score=""+(myReader->GetInt32(1));
						 if(myReader->GetFloat(2)!=-1)
							kdr=""+(myReader->GetFloat(2));
						 else
							kdr="NAN";
						 rank=""+(myReader->GetInt32(3));
						 this->leaderboard_grd->Rows->Add(username,score,kdr,rank);
						 }
					 myReader->Close();

				 }catch(Exception^ ex)
				 {MessageBox::Show(ex->Message);
				 }
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form5()
		{
			if (components)
			{
				delete components;
			}
			this->Close();
		}
	public: System::Windows::Forms::DataGridView^  leaderboard_grd;
	protected: 
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  username_clm;
	public: 
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  score_clm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  kdr_clm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  rank_lbl;
	private: System::Windows::Forms::Label^  leaderboard_lbl;

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
			this->leaderboard_grd = (gcnew System::Windows::Forms::DataGridView());
			this->username_clm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->score_clm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->kdr_clm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rank_lbl = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->leaderboard_lbl = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->leaderboard_grd))->BeginInit();
			this->SuspendLayout();
			// 
			// leaderboard_grd
			// 
			this->leaderboard_grd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->leaderboard_grd->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->username_clm, 
				this->score_clm, this->kdr_clm, this->rank_lbl});
			this->leaderboard_grd->Location = System::Drawing::Point(22, 45);
			this->leaderboard_grd->Name = L"leaderboard_grd";
			this->leaderboard_grd->ReadOnly = true;
			this->leaderboard_grd->RowTemplate->Height = 24;
			this->leaderboard_grd->Size = System::Drawing::Size(444, 451);
			this->leaderboard_grd->TabIndex = 0;
			// 
			// username_clm
			// 
			this->username_clm->HeaderText = L"Username";
			this->username_clm->Name = L"username_clm";
			this->username_clm->ReadOnly = true;
			// 
			// score_clm
			// 
			this->score_clm->HeaderText = L"Score";
			this->score_clm->Name = L"score_clm";
			this->score_clm->ReadOnly = true;
			// 
			// kdr_clm
			// 
			this->kdr_clm->HeaderText = L"K/D Ratio";
			this->kdr_clm->Name = L"kdr_clm";
			this->kdr_clm->ReadOnly = true;
			// 
			// rank_lbl
			// 
			this->rank_lbl->HeaderText = L"Rank";
			this->rank_lbl->Name = L"rank_lbl";
			this->rank_lbl->ReadOnly = true;
			// 
			// leaderboard_lbl
			// 
			this->leaderboard_lbl->AutoSize = true;
			this->leaderboard_lbl->Location = System::Drawing::Point(188, 11);
			this->leaderboard_lbl->Name = L"leaderboard_lbl";
			this->leaderboard_lbl->Size = System::Drawing::Size(95, 17);
			this->leaderboard_lbl->TabIndex = 1;
			this->leaderboard_lbl->Text = L"Leader Board";
			// 
			// Form5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 508);
			this->Controls->Add(this->leaderboard_lbl);
			this->Controls->Add(this->leaderboard_grd);
			this->Name = L"Form5";
			this->Text = L"Form5";
			this->Load += gcnew System::EventHandler(this, &Form5::Form5_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->leaderboard_grd))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form5_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
