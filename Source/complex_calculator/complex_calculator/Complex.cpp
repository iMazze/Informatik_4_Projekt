#include "Complex.h"
#include <sstream>



Complex::Complex() : re(0), im(0) {

}

Complex::Complex(double re, double im) : re(re), im(im) {
}

Complex::Complex(const Complex & Complex2)
{
	re = Complex2.re;
	im = Complex2.im;
}

double Complex::getRe()
{
	return re;
}

double Complex::getIm()
{
	return im;
}

void Complex::setRe(double value)
{
	re = value;
}

void Complex::setIm(double value)
{
	im = value;
}

void Complex::setFromPolar(double mag, double phi)
{

	double help = phi * (M_PI / 180);
	double twoPi = 2 * M_PI;
	if (-twoPi <= help && help <= twoPi) {

		re = sqrt(mag*mag) * cos(help);
		im = sqrt (mag*mag) * sin(help);
	}
	else {
		std::cout << phi << " grad: ungueltiges Argument \n";
	}
}

double Complex::getMag() const
{
	return sqrt((re*re + im * im));
}

double Complex::getPhi() const
{
	double help = (im / re);
	//return help;

	if (re > 0.0) {
		return atan(help) * 180 / M_PI;
	}
	else if (re < 0 && im >= 0) {
		double help2 = atan(help) + M_PI;
		return help2 * 180 / M_PI;
	}
	else if (re < 0 && im < 0) {
		double help2 = atan(help) - M_PI;
		return help2 * (180 / M_PI);
	}
	else if (re == 0 && im > 0) {
		return M_PI_2 * (180 / M_PI);
	}
	else if (re == 0 && im < 0) {
		return -M_PI_2 * (180 / M_PI);
	}
	else if (re == 0 && im == 0) {
		return 0;
	}
	

}

Complex Complex::operator+(const Complex& summand)
{
	Complex result;

	result.re = re + summand.re;
	result.im = im + summand.im;

	return result;
}

Complex Complex::operator-(const Complex& minuend)
{
	Complex result;
	result.re = re - minuend.re;
	result.im = im - minuend.im;

	return result;
}

Complex Complex::operator*(const Complex& multiplier)
{
	Complex result;
	result.re = (re*multiplier.re - im * multiplier.im);
	result.im = (re*multiplier.im + im * multiplier.re);
	return result;
}

Complex Complex::operator/(const Complex& divisor)
{
	Complex result;
	result.re = (re*divisor.re + im * divisor.im) / (divisor.re*divisor.re + divisor.im*divisor.im);
	result.im = (im* divisor.re - re * divisor.im) / (divisor.re*divisor.re + divisor.im*divisor.im);
	return result;
}


std::string Complex::toString() const
{
	std::stringstream fmt;
	if (im == 0) {
		fmt << re;
	}
	else if (re == 0) {
		fmt << im << "i";
	}
	else {
		fmt << re;
		if (im < 0) {
			fmt << " - " << -im;
		}
		else {
			fmt << " + " << im;
		}
		fmt << "i";
	}
	return fmt.str();
}

std::string Complex::toPolarString() const
{
	double help = sqrt(getMag()*getMag());

	std::stringstream fmt;

	fmt << help << "e^(i" << getPhi() << ")";


	return fmt.str();
}


Complex::~Complex() {

}

