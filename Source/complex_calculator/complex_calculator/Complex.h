/**
 * @file Complex.h
 *
 * @brief Represents a Complex number
 * @author Johannes Eberle
 */
#if !defined(EA_A0FEDFFD_417C_4d48_871A_EEA55FBAD715__INCLUDED_)
#define EA_A0FEDFFD_417C_4d48_871A_EEA55FBAD715__INCLUDED_

#include <math.h>
#include <string>
#include <iostream>


#ifndef M_PI
#define M_PI (3.14159265358979323846) //PI
#endif

#ifndef M_PI_2
#define M_PI_2 M_PI/2 //PI/2
#endif

 //!  Enum for deciding betwen cartesian or polar format
enum class E_Format { CARTESIAN, POLAR };

//!  Class Complex represents a complex number. 
/*!
  Representing a complex number with real and imaginary part. Implements some basic maths operations and some print out functions.
  The number is stored as cartesian, but can be also used with polar coordinates.
*/
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
	double getMag() const;
	//! get angle of complex number
	double getPhi() const;
	//! Addition
	/*!
	z1 = a+bi
	z2 = c+di
	z1 + z2 = (a+b)+(c+d)i
	*/
	Complex operator+(const Complex& summand);
	//! Substraction
	/*!
	z1 = a+bi
	z2 = c+di
	z1 - z2 = (a-b)+(c-d)i
	*/
	Complex operator-(const Complex& minuend);
	//! Multiplication
	/*!
	z1=a+bi
	z2=c+di
	z1*z2 = (ac-bd) + (ad+bc)i
	*/
	Complex operator*(const Complex& multiplier);
	//! Division
	/*!
	z1 = a+bi
	z2 = c+di
	z1/z2 = (ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i
	*/
	Complex operator/(const Complex& divisor);

	//!  Converts the complex number to an cartesian readable string
	std::string toString() const;

	//!  Converts the complex number to an polar readable string
	std::string toPolarString() const;

	virtual ~Complex();

};
#endif // !defined(EA_A0FEDFFD_417C_4d48_871A_EEA55FBAD715__INCLUDED_)


