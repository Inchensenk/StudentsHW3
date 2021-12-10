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
	//конструктор
	Group(string nameGr, string studList, string subjList, string scoreList);
	//функция для чтения из файла
	static string ReadFile(string namefile);
	
	//функция которая считает колличество вхождений символа в строке
	static int Count(string str, char sep);
	
	//делит исходную строку на подстроки и формирует массив подстрок по заданному разделителю
	static string* GetArray(string data, int numrow, char sep);

	//перевод из char в int 
	static int CharToInt(char c);
	
	//таблица оценок студентов по предметам
	void scoreTable();
	
	//функция для вывода таблицы средних оценок 
	void avgScoreStud();
	

	//функция для вывода средней оценки по предметам
	void avgScoreSubj();
	

	//функция для вывода средней оценки по группе
	void avgScoreGroup();
	
	//функция макс мин оценок по предметам с указанием студентов (что-то пошло не так зашел в тупик, не работает так как должна)
	void scoreTableMinMax();
	

};

