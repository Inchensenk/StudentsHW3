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
	//конструктор для массива строк
	Student(string* studList, string* scoreList);
	
	//конструктор пинимающий строки из файла
	Student(string dataStud, string dataScore);
	
	//деструктор
	~Student();
	
	//функция считывающая текст из файла и возвращает его в строковую переменную
	static string ReadFile(string namefile);
	
	//функция которая считает колличество вхождений символа в строке
	static int Count(string str, char sep);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="data">исходная строка которую будем делить на подстроки</param>
	/// <param name="numrow">колличество строк</param>
	/// <param name="sep">разделительный символ</param>
	/// <returns></returns>
	static string* GetArray(string data, int numrow, char sep);
	
};

