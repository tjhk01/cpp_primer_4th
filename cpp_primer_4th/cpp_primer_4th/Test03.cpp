#include <iostream>
#include <string>
#include <cstddef>
#include <Windows.h>
#include <vector>
#include "cpp_primer_config.h"

#include "Test03.h"

#ifdef USE_TEST03_C
using namespace std;

Test03::Test03(const std::string & str)
{
	this->Str = str;
}

Test03::~Test03()
{
	cout << "["<< this << "] Object Destoryed !" << endl;
}

int main(void)
{
	vector<Test03> TestStr;

	{
		Test03 a = Test03("Hello");
		TestStr.push_back(a);
		a = Test03("World");
		TestStr.push_back(a);
	}

	while (1)
	{
		cout << "Finish !" << endl;
		Sleep(10000);
	}

	return 0;
}
#endif