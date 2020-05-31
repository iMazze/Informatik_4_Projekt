#pragma once

#include "Complex.h"
#include "Calculation.h"


class UI_Communication
{
private:
	
public:
	UI_Communication();
	
	Complex stringToNumber(const std::string &str);
	E_Format stringToFormat(const std::string &str);
	E_Operation stringToOperation(const std::string & str);

	Complex readNumber();
	void writeNumber(const Complex &number, E_Format format);
	void writeText(const std::string &text);
	E_Format readFormat();
	E_Operation readOperation();
};

