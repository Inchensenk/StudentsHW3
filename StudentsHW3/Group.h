#pragma once
#include <iostream>
#include "Subject.h"
#include "Student.h"
#include <fstream>
using namespace std;


class Group : public Subject, public Student
{
private:
	string nameGr;
	
public:
	//�����������
	Group(string nameGr, string studList, string subjList, string scoreList);
	//������� ��� ������ �� �����
	static string ReadFile(string namefile);
	
	//������� ������� ������� ����������� ��������� ������� � ������
	static int Count(string str, char sep);
	
	//����� �������� ������ �� ��������� � ��������� ������ �������� �� ��������� �����������
	static string* GetArray(string data, int numrow, char sep);

	//������� �� char � int 
	static int CharToInt(char c);
	
	//������� ������ ��������� �� ���������
	void scoreTable();
	
	//������� ��� ������ ������� ������� ������ 
	void avgScoreStud();
	

	//������� ��� ������ ������� ������ �� ���������
	void avgScoreSubj();
	

	//������� ��� ������ ������� ������ �� ������
	void avgScoreGroup();
	
	//������� ���� ��� ������ �� ��������� � ��������� ��������� (���-�� ����� �� ��� ����� � �����, �� �������� ��� ��� ������)
	void scoreTableMinMax();
	

};

