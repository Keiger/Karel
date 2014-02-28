#pragma once
#include <vector>
#include "Robot.h"
#include "Wall.h"

int WORLD_Y = 1;
int WORLD_X = 1;
int SCALE = 50;
int gridWeight = 4;

vector<Robot> bots;
vector<Wall> walls;

void readFile();
void flip();

namespace Karel {

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
	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(284, 262);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(29, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResizeEnd += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Graphics ^gp1,^gp2;
		Brush ^black, ^green, ^blue, ^brown, ^control;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 readFile();
				 
				 ClientSize = System::Drawing::Size(WORLD_X*SCALE, WORLD_Y*SCALE);
				 panel1->Size = System::Drawing::Size(WORLD_X*SCALE, WORLD_Y*SCALE);
				 pictureBox1->Size = System::Drawing::Size(SCALE -4, SCALE -4);

				 pictureBox1 -> Image -> RotateFlip(RotateFlipType(bots[0].getDirection()));
	 
				 gp1 = panel1->CreateGraphics();

				 black = gcnew SolidBrush(Color::Black);
				 green = gcnew SolidBrush(Color::Green);
				 blue = gcnew SolidBrush(Color::Blue);
				 brown = gcnew SolidBrush(Color::Brown);
				 control = gcnew SolidBrush(Color::WhiteSmoke);

				 timer1->Enabled = true;
				 timer2->Enabled = true;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 for (int i = 0; i <= WORLD_X; i++)
					 gp1 -> FillRectangle(black, i*SCALE-2, -2, 4, WORLD_Y*SCALE); 
				 for (int i = 0; i <= WORLD_Y; i++)
					 gp1 -> FillRectangle(black, -2, i*SCALE-2, WORLD_X*SCALE, 4);

				 for (int i = 0; i < walls.size(); i++)
					 gp1 -> FillRectangle(brown, walls[i].getLoc_x()*SCALE+2, walls[i].getLoc_y()*SCALE+2, 46, 46);

				 timer1->Enabled = false;
			 }

	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {

				 pictureBox1 -> Location = System::Drawing::Point(bots[0].getLoc_x()*SCALE+2, bots[0].getLoc_y()*SCALE+2);

				 timer2->Enabled = false;
			 }
private: System::Void MyForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 		 
			 if (e->KeyChar == 'w')
				 bots[0].move_forward();
			 else if(e->KeyChar == 'a'){
				 bots[0].turn_left();
				 pictureBox1 -> Image -> RotateFlip(RotateFlipType(3));
				 pictureBox1 -> Refresh();}
			 else if(e->KeyChar == 's')
				 bots[0].move_back();
			 else if(e->KeyChar == 'd'){
				 bots[0].turn_right();
				 pictureBox1 -> Image -> RotateFlip(RotateFlipType(1));
				 pictureBox1 -> Refresh();}
			 else if(e->KeyChar == 'r'){
				 bots[0].turn();
				 pictureBox1 -> Image -> RotateFlip(RotateFlipType(1));
				 pictureBox1 -> Refresh();
				 }

			 timer1 -> Enabled = true;
			 timer2 -> Enabled = true;
			 
		 }

};

}
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "MyForm.h"
#include "Robot.h"
using namespace std;
using namespace System::Drawing;

void readFile()
{

	ifstream fin;
	int x, y, b, h;
	string str;

	fin.open("myfile.txt");
	if (fin.fail()){cout << "Fail"; exit(1);}

	while (!fin.eof())
	{
		fin >> str;
		transform(str.begin(), str.end(),str.begin(), ::toupper);

		if(str == "WORLD")
		{
			fin >> WORLD_X;
			fin >> WORLD_Y;
		}
		else if(str == "ROBOT")
		{
			fin >> x;
			fin >> y;
			fin >> b;
			fin >> h;
			Robot ans(x,y,b,h);
			bots.push_back(ans);
		}
		else if(str == "WALL")
		{
			fin >> x;
			fin >> y;

			Wall ans(x,y);
			walls.push_back(ans);
		}
		else if(str == "BEEPER")
		{
			//TODO
		}
		else if(str == "TURN")
		{
			bots[0].turn();
		}
	}
	
}
