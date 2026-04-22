#pragma once
const int n = 5, m = 5;
double a[n][m];

namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(67, 367);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 50);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ввести";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(299, 370);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 46);
			this->button2->TabIndex = 1;
			this->button2->Text = L"обчислити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(514, 367);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(141, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"очистити";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(84, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(614, 270);
			this->dataGridView1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(775, 249);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Середнє додатних елементів";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(781, 365);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(171, 22);
			this->textBox1->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1090, 541);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->ColumnCount = m;
		dataGridView1->Rows->Add(n);

		for (int j = 0; j < m; j++)
			dataGridView1->Columns[j]->Width = 50;
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Random^ rnd = gcnew Random();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dataGridView1[j, i]->Value = Convert::ToString(rnd->Next(-20, 21));
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	double sum = 0;
	int k = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = Convert::ToDouble(dataGridView1[j, i]->Value);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] > 0) {
				sum += a[i][j];
				k++;
			}

	if (k > 0)
		textBox1->Text = Convert::ToString(sum / k);
	else
		textBox1->Text = L"Додатних елементів немає";
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dataGridView1[j, i]->Value = "";

	textBox1->Clear();
}
};
}
