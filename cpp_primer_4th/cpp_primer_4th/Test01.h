#pragma once
#ifndef __TEST01_H
#define __TEST01_H

#include <iostream>
#include <string>
#include "cpp_primer_config.h"

#ifdef USE_TEST01_H

class Test01
{
public:
	void showMsg(const std::string Str);
	unsigned int getMsgCounter(void);
public:
	Test01();
	~Test01();

private:
	unsigned int ShowMsgCounter = 0;
};

#endif
#endif