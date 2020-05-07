///////////////////////////////////////////////////////////
//  Complex.h
//  Implementation of the Class Complex
//  Created on:      07-Mai-2020 12:06:36
//  Original author: Maximilian Klug
///////////////////////////////////////////////////////////

#if !defined(EA_A0FEDFFD_417C_4d48_871A_EEA55FBAD715__INCLUDED_)
#define EA_A0FEDFFD_417C_4d48_871A_EEA55FBAD715__INCLUDED_

class Complex
{

public:
	Complex();
	virtual ~Complex();
	float getImaginary();
	float getReal();
	void setImaginary(float value);
	void setReal(float value);
	unsigned char toString();

private:
	float imaginarypart;
	float realpart;
	float testpart;
	int number;

};
#endif // !defined(EA_A0FEDFFD_417C_4d48_871A_EEA55FBAD715__INCLUDED_)
