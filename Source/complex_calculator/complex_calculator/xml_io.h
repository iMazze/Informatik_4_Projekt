#pragma once

#include <vector>

//!  A test class. 
/*!
  A more elaborate class description.
*/
class xml_io
{
public:
	//! A constructor.
	/*!
	  A more elaborate description of the constructor.
	*/
	xml_io();
	~xml_io();

	//! A normal member taking two arguments and returning an integer value.
	/*!
	*/
	static void doxml();
	void writexml();
private: 
	//! A function variable.
	/*!
	  Details.
	*/
	std::vector<int> list;
};

