#pragma once
#ifndef __TEST04_H
#define __TEST04_H

#include <iostream>
#include <string>
#include "cpp_primer_config.h"

#ifdef USE_TEST04_H
class Test04
{
public:
	Test04(void);
	Test04(int);
	Test04(char);
	Test04(const std::string &);
	~Test04();
};

#endif
#endif