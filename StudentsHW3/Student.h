#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Student
{
protected:
	string* studList;//������ ���������
	string* scoreList;//������ ������
public:
	//����������� ��� ������� �����
	Student(string* studList, string* scoreList);
	
	//����������� ���������� ������ �� �����
	Student(string dataStud, string dataScore);
	
	//����������
	~Student();
	
	//������� ����������� ����� �� ����� � ���������� ��� � ��������� ����������
	static string ReadFile(string namefile);
	
	//������� ������� ������� ����������� ��������� ������� � ������
	static int Count(string str, char sep);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="data">�������� ������ ������� ����� ������ �� ���������</param>
	/// <param name="numrow">����������� �����</param>
	/// <param name="sep">�������������� ������</param>
	/// <returns></returns>
	static string* GetArray(string data, int numrow, char sep);
	
};

