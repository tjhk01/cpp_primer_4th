#include <iostream>
#include <string>
#include <cstddef>
#include <Windows.h>
#include <vector>
#include "cpp_primer_config.h"

#include "Test01.h"

#ifdef USE_TEST01_C

using namespace std;

void Test01::showMsg(const std::string Str)
{
	cout <<"["<< this->ShowMsgCounter++ <<"] - "<< Str << endl;
}

unsigned int Test01::getMsgCounter(void)
{
	return this->ShowMsgCounter;
}

Test01::Test01()
{
	cout << "Object instance done !" << endl;
}


Test01::~Test01()
{
	cout << "Odject destoryed !" << endl;
}

int main(void)
{
	Test01 Obj1;

	Sleep(1000);

	for (int i = 0; i < 5; i++)
	{
		Obj1.showMsg("Hello");
	}

	Sleep(1000);
	cout << "Process Done, Count : " << Obj1.getMsgCounter() << endl;
}

#endif