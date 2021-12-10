#include "Group.h"

 Group::Group(string nameGr, string studList, string subjList, string scoreList) : Subject(subjList), Student(studList, scoreList)
{
	this->nameGr = nameGr;
}

string Group::ReadFile(string namefile)
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

int Group::Count(string str, char sep)
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

string* Group::GetArray(string data, int numrow, char sep)

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

int Group::CharToInt(char c)
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

void Group::scoreTable()
{
	cout << "������: " + nameGr << endl;

	int sizeSubj = sizeof(subjList[0]) / sizeof(subjList);//sizeSubj ������ ������� subjList
	cout << "\t\t\t\t";
	for (int i = 0; i < sizeSubj; i++)
	{   //���� ������ ���� ������ ������ ���� ����� 8
		if (subjList[i].size() >= 8)
			//�� ������ ��������� ���������
			cout << subjList[i] << "\t";
		else
			//����� �������
			cout << subjList[i] << "\t\t";
	}
	cout << endl;
	int sizeStud = sizeof(studList[0]) / sizeof(studList);
	int sizeScore = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// ������ ������������� � 2 ���� ��� ��� ����� �������� � ������ ���� ������� � -1 ������ ��� � ���������� ������� � ������ ������ ��� ���
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

void Group::avgScoreStud()
{
	cout << "������: " + nameGr << endl;
	int sizeStud = sizeof(studList[0]) / sizeof(studList);
	int sizeScore = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// ������ ������������� � 2 ���� ��� ��� ����� �������� � ������ ���� ������� � -1 ������ ��� � ���������� ������� � ��������� ������ ��� ���
	int sizeScoreOrig = sizeof(scoreList[0]) / sizeof(scoreList);
	for (int i = 0; i < sizeStud; i++)
	{
		float avg = 0;
		if (studList[i].size() >= 22)
			cout << studList[i] << "\t";
		else
			cout << studList[i] << "\t\t";

		for (int j = 0; j < sizeScore; j++)
		{
			//���� ������ �� ��nysq �� ��� ���������, ����� ���������� �������
			if (j % 2 == 0)
				avg += CharToInt(scoreList[i][j]);
		}
		//����� ������� ������
		cout << avg / sizeScoreOrig << endl;
	}
}

void Group::avgScoreSubj()
{
	cout << "��������: " << endl;
	int sizeSubj = sizeof(subjList[0]) / sizeof(subjList);
	for (int i = 0; i < sizeSubj; i++)
	{
		if (subjList[i].size() >= 8)
			//�� ������ ��������� ���������
			cout << subjList[i] << "\t";
		else
			//����� �������
			cout << subjList[i] << "\t\t";
	}
	cout << endl;
	//������ � ��������
	int sizeScoreExtend = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// ������ ������������� � 2 ���� ��� ��� ����� �������� � ������ ���� ������� � -1 ������ ��� � ���������� ������� � ��������� ������ ��� ���
	//������ ��� ����������� (�������)
	int sizeScoreOrig = sizeof(scoreList[0]) / sizeof(scoreList);

	for (int i = 0; i < sizeScoreExtend; i++)
	{
		float avg = 0;
		for (int j = 0; j < sizeScoreOrig; j++)
		{
			//���� ������ �� ������ �� ��� ���������, ����� ���������� �������
			if (i % 2 == 0)
				//���������� ������ �� ������������� ��������
				avg += CharToInt(scoreList[j][i]);
		}

		if (i % 2 == 0)
			//����� ������� ������
			cout << avg / sizeScoreOrig << "\t\t";
	}

}

void Group::avgScoreGroup()
{
	cout << "������: " + nameGr << endl;
	//���������� ��������� ������� ���������
	int sizeStud = sizeof(studList[0]) / sizeof(studList);
	//������ � ���������
	int sizeScoreExtend = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// ������ ������������� � 2 ���� ��� ��� ����� �������� � ������ ���� ������� � -1 ������ ��� � ���������� ������� � ��������� ������ ��� ���
	//������ ��� ����������� (�������)
	int sizeScoreOrig = sizeof(scoreList[0]) / sizeof(scoreList);
	float avgGroup = 0;
	for (int i = 0; i < sizeStud; i++)
	{
		float avg = 0;

		for (int j = 0; j < sizeScoreExtend; j++)
		{
			//���� ������ �� ��nysq �� ��� ���������, ����� ���������� �������
			if (j % 2 == 0)
				avg += CharToInt(scoreList[i][j]);
		}
		////���������� ������� ������ ����������� �������� � ������������ �� ����� �������� �������� ���������
		avgGroup += avg / sizeScoreOrig;

	}
	//���������� ������� ������ ������
	avgGroup /= sizeStud;
	cout << "������� ���� ������ " + nameGr + " : " << avgGroup << endl;
}

void Group::scoreTableMinMax()
{
	cout << "������: " + nameGr << endl;

	int sizeSubj = sizeof(subjList[0]) / sizeof(subjList);//sizeSubj ������ ������� subjList
	cout << "\t\t\t\t";
	for (int i = 0; i < sizeSubj; i++)
	{   //���� ������ ���� ������ ������ ���� ����� 8
		if (subjList[i].size() >= 8)
			//�� ������ ��������� ���������
			cout << subjList[i] << "\t";
		else
			//����� �������
			cout << subjList[i] << "\t\t";
	}
	cout << endl;

	int sizeStud = sizeof(studList[0]) / sizeof(studList);
	//������ � ��������
	int sizeScoreExtend = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// ������ ������������� � 2 ���� ��� ��� ����� �������� � ������ ���� ������� � -1 ������ ��� � ���������� ������� � ��������� ������ ��� ���
	//������ ��� ����������� (�������)
	int sizeScoreOrig = sizeof(scoreList[0]) / sizeof(scoreList);

	for (int i = 0; i < sizeStud; i++)
	{
		int* max = new int[sizeScoreOrig];
		int* min = new int[sizeScoreOrig];

		if (studList[i].size() >= 22)
			cout << studList[i] << "\t";
		else
			cout << studList[i] << "\t\t";

		for (int k = 0; k < sizeScoreExtend; k++)
		{
			max[i] = CharToInt(scoreList[i][0]);
			min[i] = CharToInt(scoreList[i][0]);

			//���� ������ �� ������ �� ��� ���������, ����� ���������� �������
			if (k % 2 == 0)
			{
				if (CharToInt(scoreList[i][k]) >= max[i])
					max[i] = CharToInt(scoreList[i][k]);
				if (CharToInt(scoreList[i][k]) <= min[i])
					min[i] = CharToInt(scoreList[i][k]);
			}

			//cout << min << endl;
		}

		for (int e = 0; e < sizeScoreExtend; e++)
		{
			if (e % 2 == 0)
			{
				if (CharToInt(scoreList[i][e]) == max[i])
					cout << scoreList[i][e] << "-max" << "\t\t";
				else if (CharToInt(scoreList[i][e]) == min[i])
					cout << scoreList[i][e] << "-min" << "\t\t";
				else
					cout << scoreList[i][e] << "\t\t";
			}
		}
		cout << endl;
	}
}
