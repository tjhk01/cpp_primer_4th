#include<iostream>
#include<string>
#include "Test06.h"

using namespace std;


Test06::Test06()
{
	cout << "Test06 constructor" << endl;
	TestCnt = 0;
	TestStr = NULL;
}


Test06::~Test06()
{
	cout << "Test06 destructor" << endl;
	if (NULL != TestStr)
	{
		cout << "Test06_sub TestStr memory free" << endl;
		free(TestStr);
		TestStr = NULL;
	}
}

bool Test06::setTestCounter(int cnt)
{
	cout << "Test06 Test Counter : " << cnt << endl;
	this->TestCnt = cnt;
	return true;
}


int Test06::setTestString(char *pStr)
{
	if (NULL == this->TestStr)
	{
		cout << "Test String : " << pStr << endl;
		this->TestStr = _strdup((const char *)pStr);
		return strlen(pStr);
	}
	else
	{
		cout << "Test String [" << TestStr << "] already been set, [" << pStr << "] can't be set" << endl;
		return 0;
	}
}

Test06_sub::Test06_sub()
{
	cout << "Test06 Sub constructor" << endl;
	TestStr = NULL;
}

Test06_sub::~Test06_sub()
{
	cout << "Test06_sub destructor" << endl;
	if (NULL != TestStr)
	{
		cout << "Test06_sub TestStr memory free" << endl;
		free(TestStr);
		TestStr = NULL;
	}
}

int Test06_sub::setTestString(char * pStr)
{
	if (NULL == this->TestStr)
	{
		cout << "Test06_sub Test String : " << pStr << endl;
		this->TestStr = _strdup((const char *)pStr);
		return strlen(pStr);
	}
	else
	{
		cout << "Test06_sub Test String [" << TestStr << "] already been set, [" << pStr << "] can't be set" << endl;
		return 0;
	}
}

int main(void)
{
	Test06 Test06_instant;
	Test06_instant.setTestCounter(15);
	Test06_instant.setTestString("Hello");
	Test06_sub Test06_sub_instant;
	Test06_sub_instant.setTestString("World");
	Test06 *pTest06;
	pTest06 = &Test06_instant;
	pTest06->setTestString("New");
	pTest06 = &Test06_sub_instant;
	pTest06->setTestString("Old");
	
	while (1);
}
