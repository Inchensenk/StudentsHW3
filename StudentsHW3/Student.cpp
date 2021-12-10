#include "Student.h"

Student::Student(string* studList, string* scoreList)
{
	this->studList = studList;
	this->scoreList = scoreList;
}

Student::Student(string dataStud, string dataScore)
{
	int size = 0;
	size = Count(dataStud, '\n') + 1; //т.к. В конце файла стоит '\0', а не '\n', то добавим 1, чтобы его учитывать.
	this->studList = GetArray(dataStud, size, '\n');
	size = Count(dataScore, '\n') + 1; //т.к. В конце файла стоит '\0', а не '\n', то добавим 1, чтобы его учитывать.
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
	if (f.is_open())//если файл открылся
	{
		while (true)
		{
			f.get(buf);//посимвольное считывание из файла в переменную buf
			if (!f.eof())//пока файл не закончился считываем данные с файла
				data += buf;
			else
				break;
		}
		f.close();//закрытие потока чтения
	}
	else cout << "Файл не открылся!" << endl;
	return data;
}

int Student::Count(string str, char sep)
{
	int count = 0;
	while (true)
	{
		int index = str.find(sep);//find() ищет первое вхождение символа в строку с начала строки
		if (index != -1)
		{
			count++;
			str.replace(index, 1, "");////replace() заменяет одни символы на другие символы, затирание символов на пустую строку
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
			end = data.find('\0');//find() ищет первое вхождение символа в строку с начала строки
		str[i] = data.substr(beg, end);//substr() возвращает подстроку из строки по индексу начала beg и индексу конца end
		data.replace(beg, end + 1, "");//replace() заменяет одни символы на другие символы, затирание символов на пустую строку
		beg = 0;
	}

	return str;
}
