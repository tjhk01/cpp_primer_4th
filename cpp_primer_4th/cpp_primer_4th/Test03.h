#pragma once
#ifndef __TEST03_H
#define __TEST03_H

#include <iostream>
#include <string>
#include "cpp_primer_config.h"

#ifdef USE_TEST03_H
class Test03
{
public:
	Test03(const std::string &str);
	~Test03();
private:
	std::string Str;
};

#endif
#endif
