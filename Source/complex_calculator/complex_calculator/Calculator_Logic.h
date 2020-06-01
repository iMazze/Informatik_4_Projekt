/**
 * @file Calculator_Logic.h
 *
 * @brief Contains all logic for doing a calculation with two numbers
 * @author Maximilian Klug
 */
#pragma once
#include "UI_Communication.h"
#include "XML_Writer.h"

//!  Class Calculator_Logic contains all logic for doing a calculation with two numbers
/*!
  Implements all features from the job to do. Reading in two numbers (with the right format) and doing some calculation. It also triggers the XML generation.
*/
class Calculator_Logic
{
private:
	UI_Communication _ui; //! Instance for the UI_Communication object 
	XML_Writer _writer; //! Instance for the XML_Writer object 
public:
	//! Constructor for Class Calculator_Logic
	Calculator_Logic();

	//! Does a calculation with read in of two numbers and puts them out on the console
	void doCalculation();
	//! Generates a XML file for all  done calculations
	void makeXML();
};

