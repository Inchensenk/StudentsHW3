#include <iostream>
#include <fstream>
#include "Group.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

	//string path1;
	//cin>>path1;
	// ...
	//Group gr("<БВ-111>", Group::ReadFile(path1), Group::ReadFile(path2), Group::ReadFile(path3));

	Group gr("<ОД-11>", Group::ReadFile("Student.txt"), Group::ReadFile("Subject.txt"), Group::ReadFile("score table.txt"));
	gr.scoreTable();
	cout << endl << endl;
	gr.avgScoreStud();
	cout << endl << endl;
	gr.avgScoreSubj();
	cout << endl << endl;
	gr.avgScoreGroup();
	cout << endl<<endl;
	gr.scoreTableMinMax();
}

