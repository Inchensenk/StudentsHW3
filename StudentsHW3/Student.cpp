#include "Student.h"

Student::Student(string* studList, string* scoreList)
{
	this->studList = studList;
	this->scoreList = scoreList;
}

Student::Student(string dataStud, string dataScore)
{
	int size = 0;
	size = Count(dataStud, '\n') + 1; //�.�. � ����� ����� ����� '\0', � �� '\n', �� ������� 1, ����� ��� ���������.
	this->studList = GetArray(dataStud, size, '\n');
	size = Count(dataScore, '\n') + 1; //�.�. � ����� ����� ����� '\0', � �� '\n', �� ������� 1, ����� ��� ���������.
	this->scoreList = GetArray(dataScore, size, '\n');
}

Student::~Student()
{
	delete[] studList;
	delete[] scoreList;
}

string Student::ReadFile(string namefile)
{
	ifstream f;
	char buf;
	string data = "";
	f.open(namefile);
	if (f.is_open())//���� ���� ��������
	{
		while (true)
		{
			f.get(buf);//������������ ���������� �� ����� � ���������� buf
			if (!f.eof())//���� ���� �� ���������� ��������� ������ � �����
				data += buf;
			else
				break;
		}
		f.close();//�������� ������ ������
	}
	else cout << "���� �� ��������!" << endl;
	return data;
}

int Student::Count(string str, char sep)
{
	int count = 0;
	while (true)
	{
		int index = str.find(sep);//find() ���� ������ ��������� ������� � ������ � ������ ������
		if (index != -1)
		{
			count++;
			str.replace(index, 1, "");////replace() �������� ���� ������� �� ������ �������, ��������� �������� �� ������ ������
		}
		else
			return count;
	}
}

string* Student::GetArray(string data, int numrow, char sep)
{
	string* str = new string[numrow]{};
	int beg = 0;
	int end = 0;
	for (int i = 0; i < numrow; i++)
	{
		end = data.find(sep);
		if (end == -1)
			end = data.find('\0');//find() ���� ������ ��������� ������� � ������ � ������ ������
		str[i] = data.substr(beg, end);//substr() ���������� ��������� �� ������ �� ������� ������ beg � ������� ����� end
		data.replace(beg, end + 1, "");//replace() �������� ���� ������� �� ������ �������, ��������� �������� �� ������ ������
		beg = 0;
	}

	return str;
}
