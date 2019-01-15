#pragma once
class Test06
{
public:
	Test06();
	~Test06();
private:
	int TestCnt;
	char *TestStr;
public:
	bool setTestCounter(int cnt);
	virtual int setTestString(char *pStr);
};

class Test06_sub : public Test06
{
public:
	Test06_sub();
	~Test06_sub();
	virtual int setTestString(char *pStr);
private:
	int TestCnt;
	char *TestStr;
};