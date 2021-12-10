#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Subject
{
	protected: 
		string* subjList;
public:
	Subject(string* subjList);
	
	Subject(string dataSubj);
	
	~Subject();
	
	static string ReadFile(string namefile);
	

	static int Count(string str, char sep);
	

	static string* GetArray(string data, int numrow, char sep);
	
};

