#include "Calculator_Logic.h"



Calculator_Logic::Calculator_Logic()
{
}

void Calculator_Logic::doCalculation()
{
	Calculation<Complex> *r1 = new Calculation<Complex>();
	
	r1->setNumber1(ui.readNumber());
	r1->setNumber2(ui.readNumber());

	switch (ui.readOperation())
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
	ui.writeNumber(r1->getResult(), ui.readFormat());

	writer.addComplexCalculation(*r1);
}

void Calculator_Logic::makeXML()
{
	writer.writeCalculationsToXML();
}

