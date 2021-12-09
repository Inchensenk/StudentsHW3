#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Student
{
protected:
	string* studList;//список студентов
	string* scoreList;//список оценок
public:
	//конструктор
	Student(string* studList, string* scoreList)
	{
		this->studList = studList;
		this->scoreList = scoreList;
	}

	Student(string dataStud, string dataScore)
	{
		int size = 0;
		size = Count(dataStud, '\n') + 1; //т.к. В конце файла стоит '\0', а не '\n', то добавим 1, чтобы его учитывать.
		this->studList = GetArray(dataStud, size, '\n');
		size = Count(dataScore, '\n') + 1; //т.к. В конце файла стоит '\0', а не '\n', то добавим 1, чтобы его учитывать.
		this->scoreList = GetArray(dataScore, size, '\n');
	}
	//деструктор
	~Student()
	{
		delete[] studList;
		delete[] scoreList;
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
	/// <summary>
	/// 
	/// </summary>
	/// <param name="data"></param>
	/// <param name="numrow">колличество строк</param>
	/// <param name="sep"></param>
	/// <returns></returns>
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

