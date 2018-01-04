#include <iostream>
#include <string>
#include <cstddef>
#include <Windows.h>
#include <vector>
#include "cpp_primer_config.h"

#include "Test04.h"

#ifdef USE_TEST04_C
using namespace std;

Test04::Test04(void)
{
	cout << "[" << this <<"] void Constructor" << endl;
}

Test04::Test04(int a)
{
	cout << "[" << this << "] int Constructor : " << a << endl;
}

Test04::Test04(char s)
{
	cout << "[" << this << "] char Constructor : " << s << endl;
}

Test04::Test04(const std::string &s)
{
	cout << "[" << this << "] string Constructor : " << s << endl;
}

Test04::~Test04()
{
	cout << "Object ["<< this <<"] was destoryed" << endl;
}

int main()
{
	Test04 a1;
	Test04 a2(1);
	Test04 a3('s');
	Test04 a4("Hello");

	return 0;
}
#endif