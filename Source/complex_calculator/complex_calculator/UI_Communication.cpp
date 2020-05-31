#include "UI_Communication.h"
#include <algorithm> // for replace string


Complex UI_Communication::stringToNumber(const std::string & str)
{
	Complex i;
	double a = 0, b = 0;
	std::string local_str(str); // make a copy of the string

	/* auto detext format */
	// its polar
	if (local_str.find("e^") != std::string::npos)
	{
		// take part until e^... as a
		a = atof(local_str.substr(0, local_str.find("e^")).c_str());

		std::string chars = "()ij ";
		for (char c : chars) {
			local_str.erase(std::remove(local_str.begin(), local_str.end(), c), local_str.end());
		}
		b = atof(local_str.substr(local_str.find("e^") + 2).c_str());

		i.setFromPolar(a, b);
	}
	// it is cartesian
	else
	{
		bool swap_ab = false;
		// search for imaginary part
		std::size_t found_i = local_str.find("i");
		if (found_i != std::string::npos)
		{
			// found i in text
		}
		else
		{
			// found no i in text
			// search for j
			found_i = local_str.find("j");
			if (found_i != std::string::npos)
			{
				// found  a j in text
			}
			else
			{
				// error
			}
		}
		
		std::size_t found = local_str.find_last_of("+-");

		// if first imaginary then real part
		if (found > found_i)
		{
			swap_ab = true;
		}

		// delete unnessesary characters
		std::string chars = "()ij ";
		for (char c : chars) {
			local_str.erase(std::remove(local_str.begin(), local_str.end(), c), local_str.end());
		}

		// get last +- second time
		found = local_str.find_last_of("+-");

		// convert string to a and b
		a = atof(local_str.substr(0, found).c_str());
		b = atof(local_str.substr(found).c_str());

		// write a and b to complex
		if (swap_ab)
		{
			i.setRe(b);
			i.setIm(a);
		}
		else
		{
			i.setRe(a);
			i.setIm(b);
		}
		
	}

	return i;
}

E_Format UI_Communication::stringToFormat(const std::string & str)
{
	E_Format format;

	if (str.find("cartesian") != std::string::npos)
	{
		format = E_Format::CARTESIAN;
	}
	else if (str.find("polar") != std::string::npos)
	{
		format = E_Format::POLAR;
	}
	else
	{
		// error;
	}

	return format;
}

E_Operation UI_Communication::stringToOperation(const std::string & str)
{
	E_Operation op;

	if (str.find("add") != std::string::npos ||
		str.find("+") != std::string::npos)
	{
		op = E_Operation::ADD;
	}
	else if (str.find("subtract") != std::string::npos ||
		str.find("-") != std::string::npos)
	{
		op = E_Operation::SUBTRACT;
	}
	else if (str.find("mult") != std::string::npos ||
		str.find("*") != std::string::npos)
	{
		op = E_Operation::MULTIPLY;
	}
	else if (str.find("divi") != std::string::npos ||
		str.find("/") != std::string::npos)
	{
		op = E_Operation::DIVIDE;
	}
	else
	{
		// error;
	}

	return op;
}

UI_Communication::UI_Communication()
{
}

Complex UI_Communication::readNumber()
{
	std::string input;
	writeText("Please input the number. Either format cartesian(1+7i) or polar (7.1e^(i81.8))!");

	std::cin >> input;

	return stringToNumber(input);
}

void UI_Communication::writeNumber(const Complex & number, E_Format format)
{
	if (format == E_Format::CARTESIAN)
	{
		std::cout <<number.ComplexToString();
	}
	else
	{
		std::cout << number.ComplexToPolarString();
	}
	
	std::cout << std::endl;
}

void UI_Communication::writeText(const std::string & text)
{
	std::cout << text;
	std::cout << std::endl;
}

E_Format UI_Communication::readFormat()
{
	std::string input;
	writeText("Please input the format. Either cartesian or polar!");

	std::cin >> input;
	
	return stringToFormat(input);
}

E_Operation UI_Communication::readOperation()
{
	std::string input;
	writeText("Please input the operation. Either + - * /!");

	std::cin >> input;

	return stringToOperation(input);
}


