/**
 * @file UI_Communication.h
 *
 * @brief Is the Interface between Human and the PC
 * @author Maximilian Klug
 */
#pragma once

#include "Complex.h"
#include "Calculation.h"

//!  Class UI_Communication is the Interface between Human and the PC
/*!
  Can parse a console input with Number or Format to objects in c++
*/
class UI_Communication
{	
public:
	//! Constructor for Class UI_Communication
	UI_Communication();
	
	//! Converts a strig to a complex - number object
	Complex stringToNumber(const std::string &str);
	//! Converts a strig to a format object
	E_Format stringToFormat(const std::string &str);
	//! Converts a strig to a operation object
	E_Operation stringToOperation(const std::string & str);

	//! Writes a number in the specific format to the console
	void writeNumber(const Complex &number, E_Format format);
	//! Wirtes a string as a normal text to the console
	void writeText(const std::string &text);
	//! Reads from the Console a number and converts that to a complex
	Complex readNumber();
	//! Reads from the Console a format and converts that
	E_Format readFormat();
	//! Reads from the Console a operation and converts that
	E_Operation readOperation();
};

