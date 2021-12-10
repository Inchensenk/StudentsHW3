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
	else cout << "Файл не открылся!" << endl;
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
	cout << "Группа: " + nameGr << endl;

	int sizeSubj = sizeof(subjList[0]) / sizeof(subjList);//sizeSubj длинна массива subjList
	cout << "\t\t\t\t";
	for (int i = 0; i < sizeSubj; i++)
	{   //если размер итой строки меньше либо равен 8
		if (subjList[i].size() >= 8)
			//то ставим одинарную табуляцию
			cout << subjList[i] << "\t";
		else
			//иначе двойную
			cout << subjList[i] << "\t\t";
	}
	cout << endl;
	int sizeStud = sizeof(studList[0]) / sizeof(studList);
	int sizeScore = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// размер увеличивается в 2 раза так как между оценками в строке есть пробелы и -1 потому что у последнего символа в каждой строке его нет
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
	cout << "Группа: " + nameGr << endl;
	int sizeStud = sizeof(studList[0]) / sizeof(studList);
	int sizeScore = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// размер увеличивается в 2 раза так как между оценками в строке есть пробелы и -1 потому что у последнего символа в последней строке его нет
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
			//если символ не чеnysq мы его считываем, чтобы пропускать пробелы
			if (j % 2 == 0)
				avg += CharToInt(scoreList[i][j]);
		}
		//вывод средней оценки
		cout << avg / sizeScoreOrig << endl;
	}
}

void Group::avgScoreSubj()
{
	cout << "Предметы: " << endl;
	int sizeSubj = sizeof(subjList[0]) / sizeof(subjList);
	for (int i = 0; i < sizeSubj; i++)
	{
		if (subjList[i].size() >= 8)
			//то ставим одинарную табуляцию
			cout << subjList[i] << "\t";
		else
			//иначе двойную
			cout << subjList[i] << "\t\t";
	}
	cout << endl;
	//размер с пробелом
	int sizeScoreExtend = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// размер увеличивается в 2 раза так как между оценками в строке есть пробелы и -1 потому что у последнего символа в последней строке его нет
	//размер без разделителя (пробела)
	int sizeScoreOrig = sizeof(scoreList[0]) / sizeof(scoreList);

	for (int i = 0; i < sizeScoreExtend; i++)
	{
		float avg = 0;
		for (int j = 0; j < sizeScoreOrig; j++)
		{
			//если символ не четный мы его считываем, чтобы пропускать пробелы
			if (i % 2 == 0)
				//складываем оценки по определенному предмету
				avg += CharToInt(scoreList[j][i]);
		}

		if (i % 2 == 0)
			//вывод средней оценки
			cout << avg / sizeScoreOrig << "\t\t";
	}

}

void Group::avgScoreGroup()
{
	cout << "Группа: " + nameGr << endl;
	//колличесво элементов массива студентов
	int sizeStud = sizeof(studList[0]) / sizeof(studList);
	//размер с пробелами
	int sizeScoreExtend = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// размер увеличивается в 2 раза так как между оценками в строке есть пробелы и -1 потому что у последнего символа в последней строке его нет
	//размер без разделителя (пробела)
	int sizeScoreOrig = sizeof(scoreList[0]) / sizeof(scoreList);
	float avgGroup = 0;
	for (int i = 0; i < sizeStud; i++)
	{
		float avg = 0;

		for (int j = 0; j < sizeScoreExtend; j++)
		{
			//если символ не чеnysq мы его считываем, чтобы пропускать пробелы
			if (j % 2 == 0)
				avg += CharToInt(scoreList[i][j]);
		}
		////вычесление средней оценки конкретного студента и суммирование со всеми средними оценками студентом
		avgGroup += avg / sizeScoreOrig;

	}
	//вычесление средней оценки группы
	avgGroup /= sizeStud;
	cout << "Средний балл группы " + nameGr + " : " << avgGroup << endl;
}

void Group::scoreTableMinMax()
{
	cout << "Группа: " + nameGr << endl;

	int sizeSubj = sizeof(subjList[0]) / sizeof(subjList);//sizeSubj длинна массива subjList
	cout << "\t\t\t\t";
	for (int i = 0; i < sizeSubj; i++)
	{   //если размер итой строки меньше либо равен 8
		if (subjList[i].size() >= 8)
			//то ставим одинарную табуляцию
			cout << subjList[i] << "\t";
		else
			//иначе двойную
			cout << subjList[i] << "\t\t";
	}
	cout << endl;

	int sizeStud = sizeof(studList[0]) / sizeof(studList);
	//размер с пробелом
	int sizeScoreExtend = (sizeof(scoreList[0]) / sizeof(scoreList)) * 2 - 1;// размер увеличивается в 2 раза так как между оценками в строке есть пробелы и -1 потому что у последнего символа в последней строке его нет
	//размер без разделителя (пробела)
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

			//если символ не четный мы его считываем, чтобы пропускать пробелы
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
