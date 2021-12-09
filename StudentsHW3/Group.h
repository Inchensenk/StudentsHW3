#pragma once
#include <iostream>
#include "Subject.h"
#include "Student.h"
#include <fstream>
using namespace std;


class Group : public Subject, public Student
{
	string nameGr;
	

public:
	Group(string nameGr, string studList, string subjList,  string scoreList) : Subject(subjList), Student(studList, scoreList)
	{
		this->nameGr = nameGr;
	}
	static string ReadFile(string namefile)
	{
		ifstream f;
		char buf;
		string data = "";
		f.open(namefile);
		if (f.is_open())
		{
			while (true)
			{
				f.get(buf);
				if (!f.eof())
					data += buf;
				else
					break;
			}
			f.close();
		}
		else cout << "Файл не открылся!" << endl;
		return data;
	}

	static int Count(string str, char sep)
	{
		int count = 0;
		while (true)
		{
			int index = str.find(sep);
			if (index != -1)
			{
				count++;
				str.replace(index, 1, "");
			}
			else
				return count;
		}
	}

	static string* GetArray(string data, int numrow, char sep)
	{
		string* str = new string[numrow]{};
		int beg = 0;
		int end = 0;
		for (int i = 0; i < numrow; i++)
		{
			end = data.find(sep);
			if (end == -1)
				end = data.find('\0');
			str[i] = data.substr(beg, end);
			data.replace(beg, end + 1, "");
			beg = 0;
		}

		return str;
	}

	static int CharToInt(char c)
	{
		if (c == (char)48) return 0;
		if (c == (char)49) return 1;
		if (c == (char)50) return 2;
		if (c == (char)51) return 3;
		if (c == (char)52) return 4;
		if (c == (char)53) return 5;
		if (c == (char)54) return 6;
		if (c == (char)55) return 7;
		if (c == (char)56) return 8;
		if (c == (char)57) return 9;
	}

	void scoreTable()
	{
		cout << "Группа: " + nameGr << endl;

		int sizeSubj = sizeof(subjList[0]) / sizeof(subjList);
		cout << "\t\t\t\t";
		for (int i = 0; i < sizeSubj; i++)
		{
			if (subjList[i].size() >= 8)
				cout << subjList[i]<<"\t";
			else
				cout << subjList[i] << "\t\t";
		}
		cout << endl;
		int sizeStud = sizeof(studList[0]) / sizeof(studList);
		int sizeScore = (sizeof(scoreList[0]) / sizeof(scoreList))*2 - 1;// размер увеличивается в 2 раза так как между оценками в строке есть пробелы и -1 потому что у последнего символа в каждой строке его нет
		for (int i = 0; i < sizeStud; i++)
		{
			if (studList[i].size() >= 22)
				cout << studList[i] << "\t";
			else
				cout << studList[i] << "\t\t";
			for (int j = 0; j < sizeScore; j++)
			{ 
				cout << scoreList[i][j] << "\t";
			}
			cout << endl;
		}
	}
	
	void avgScore()
	{
		cout << "Группа: " + nameGr << endl;
		int sizeStud = sizeof(studList[0]) / sizeof(studList);
		int sizeScore = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// размер увеличивается в 2 раза так как между оценками в строке есть пробелы и -1 потому что у последнего символа в последней строке его нет

		for (int i = 0; i < sizeStud; i++)
		{
			float avg = 0;
			if (studList[i].size() >= 22)
				cout << studList[i] << "\t";
			else
				cout << studList[i] << "\t\t";
			
			for (int j = 0; j < sizeScore; j++)
			{
				if (j % 2 == 0)
					avg += CharToInt(scoreList[i][j]);
			}
			cout << avg / (sizeof(scoreList[0]) / sizeof(scoreList)) << endl;
		}
	}
};

