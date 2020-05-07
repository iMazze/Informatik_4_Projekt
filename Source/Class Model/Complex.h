///////////////////////////////////////////////////////////
//  Complex.h
//  Implementation of the Class Complex
//  Created on:      07-Mai-2020 11:53:58
//  Original author: Maximilian Klug
///////////////////////////////////////////////////////////

#if !defined(EA_4BFC2272_94E6_43d8_A283_D8D8F5CC08E5__INCLUDED_)
#define EA_4BFC2272_94E6_43d8_A283_D8D8F5CC08E5__INCLUDED_

class Complex
{

public:
	Complex();
	virtual ~Complex();

	float getImaginary();
	float getReal();
	setImaginary(float value);
	setReal(float value);
	unsigned char toString();

private:
	float imaginarypart;
	float realpart;
	float testpart;

};
#endif // !defined(EA_4BFC2272_94E6_43d8_A283_D8D8F5CC08E5__INCLUDED_)
