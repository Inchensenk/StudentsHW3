#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Subject
{
	protected: 
		string* subjList;
public:
	Subject(string* subjList)
	{
		this->subjList = subjList;
	}
	Subject(string dataSubj)
	{
		int size = 0;
		size = Count(dataSubj, '\n') + 1; //�.�. � ����� ����� ����� '\0', � �� '\n', �� ������� 1, ����� ��� ���������.
		this->subjList = GetArray(dataSubj, size, '\n');
	}
	~Subject()
	{
		delete[] subjList;
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
		else cout << "���� �� ��������!" << endl;
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
};

