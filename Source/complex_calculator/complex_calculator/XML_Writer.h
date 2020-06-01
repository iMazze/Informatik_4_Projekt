#pragma once

#include <vector>
/**
 * @file XML_Writer.h
 *
 * @brief Saves and writes all added calculations to a xml file 
 * @author Maximilian Klug
 */
#include "Complex.h"
#include "Calculation.h"

//!  XML_Writer saves and writes all added calculations to a xml file 
class XML_Writer
{
public:
	//! Constructor of class XML Writer
	XML_Writer();

	//! Destructor of class XML Writer
	~XML_Writer();

	//! Writes all calculations to a specified XML File
	void writeCalculationsToXML(const std::string &filename);

	//! Adds a calculation reference to a list
	void addComplexCalculation(const Calculation<Complex> &calc);
private: 
	//! Internal Vector for saving the calculations
	std::vector<Calculation<Complex>> _list;
};

