#pragma once
#include "UI_Communication.h"
#include "XML_Writer.h"

class Calculator_Logic
{
private:
	UI_Communication ui;
	XML_Writer writer;
public:
	Calculator_Logic();

	void doCalculation();
	void makeXML();
};

