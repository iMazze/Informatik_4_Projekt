#pragma once

#include <vector>
#include "Complex.h"
#include "Calculation.h"

//!  A test class. 
/*!
  A more elaborate class description.
*/
class XML_Writer
{
public:
	//! A constructor.
	/*!
	  A more elaborate description of the constructor.
	*/
	XML_Writer();
	~XML_Writer();

	//! A normal member taking two arguments and returning an integer value.
	/*!

	*/
	static void doxml();
	void writexml();

	void writeCalculationsToXML();
	void addComplexCalculation(const Calculation<Complex> &calc);
private: 
	//! A function variable.
	/*!
	  Details.
	*/
	std::vector<Calculation<Complex>> list;
};

