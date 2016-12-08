#pragma once
#ifndef __TEST02_H
#define __TEST02_H

#include <iostream>
#include <string>
#include "cpp_primer_config.h"

#ifdef USE_TEST02_H

class Test02
{
public:
	void showBookInfo(void) const;
public:
	Test02(std::string Name, unsigned int ID);
	~Test02();

private:
	std::string BookName;
	unsigned int BookID;
};

#endif
#endif
