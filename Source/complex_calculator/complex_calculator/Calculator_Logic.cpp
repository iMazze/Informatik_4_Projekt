#include "Calculator_Logic.h"
#include "Messages.h"

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string

#define XML_FILE_NAME "Berechnungen_Complex"

std::string return_current_time_and_date()
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d_%H-%M");
	return ss.str();
}

Calculator_Logic::Calculator_Logic()
{
}

void Calculator_Logic::doCalculation()
{
	Calculation<Complex> *r1 = new Calculation<Complex>();
	
	try
	{
		// Read number 1
		r1->setNumber1(_ui.readNumber());
		// Read number 2
		r1->setNumber2(_ui.readNumber());
	}
	catch (const std::exception& e)
	{
		std::cout << MSG_ERROR_INPUT << MSG_ERROR_NUMBERS << std::endl;
		return; // Abort
	}
	

	try
	{
		// Make the Operation
		switch (_ui.readOperation())
		{
		case E_Operation::ADD:
			r1->add();
			break;
		case E_Operation::SUBTRACT:
			r1->subtract();
			break;
		case E_Operation::MULTIPLY:
			r1->multiply();
			break;
		case E_Operation::DIVIDE:
			r1->divide();
			break;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << MSG_ERROR_INPUT << MSG_ERROR_OPERATION << std::endl;
		return; // Abort
	}

	try
	{
		// Write number with specific format to console
		_ui.writeNumber(r1->getResult(), _ui.readFormat());

		// Add calculation to the xml list
		_writer.addComplexCalculation(*r1);
	}
	catch (const std::exception& e)
	{
		std::cout << MSG_ERROR_INPUT << MSG_ERROR_OUTPUT << std::endl;
		return; // Abort
	}
	
}

void Calculator_Logic::makeXML()
{
	try
	{
		_writer.writeCalculationsToXML(XML_FILE_NAME + std::string("_") + return_current_time_and_date() + std::string(".xml"));
	}
	catch (const std::exception& e)
	{
		std::cout << MSG_ERROR_INPUT << MSG_ERROR_XML << std::endl;
		return; // Abort
	}
}


