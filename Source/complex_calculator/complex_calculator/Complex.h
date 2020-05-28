///////////////////////////////////////////////////////////
//  Complex.h
//  Implementation of the Class Complex
//  Created on:      07-Mai-2020 12:06:36
//  Original author: Maximilian Klug
///////////////////////////////////////////////////////////

#if !defined(EA_A0FEDFFD_417C_4d48_871A_EEA55FBAD715__INCLUDED_)
#define EA_A0FEDFFD_417C_4d48_871A_EEA55FBAD715__INCLUDED_

#include <math.h>
#include <string>
#include <iostream>


#ifndef M_PI
#define M_PI (3.14159265358979323846) //PI
#endif

#ifndef M_PI_2
#define M_PI_2 (3.14159265358979323846)/2 //PI/2
#endif




class Complex
{
private:
	double re;
	double im;
public:
	//! constructor to initialize z=0+0i
	Complex();
	//! constructor to initialize z = a+bi
	Complex(double re, double im);
	//! Copy constructor
	Complex(const Complex &Complex2);
	//! get Real Part
	double getRe();
	//! get immaginary Part
	double getIm();
	//! set real Part
	void setRe(double value);
	//! set immaginary Part
	void setIm(double value);
	//! set complex number given a complex Number in polar Form
	void setFromPolar(double mag, double phi);
	//! get magnitude of complex number 
	double getMag();
	//! get angle of complex number
	double getPhi();
	//! Addition
	/*!
	z1 = a+bi
	z2 = c+di
	z1 + z2 = (a+b)+(c+d)i
	*/
	Complex operator+(Complex summand);
	//! Substraction
	/*!
	z1 = a+bi
	z2 = c+di
	z1 - z2 = (a-b)+(c-d)i
	*/
	Complex operator-(Complex minuend);
	//! Multiplication
	/*!
	z1=a+bi
	z2=c+di
	z1*z2 = (ac-bd) + (ad+bc)i
	*/
	Complex operator*(Complex multiplier);
	//! Division
	/*!
	z1 = a+bi
	z2 = c+di
	z1/z2 = (ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i
	*/
	Complex operator/(Complex divisor);
	//std::string ComplexToString();
	virtual ~Complex();

};
#endif // !defined(EA_A0FEDFFD_417C_4d48_871A_EEA55FBAD715__INCLUDED_)


