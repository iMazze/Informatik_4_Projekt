// complex_calculator.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "xml_io.h"
#include "Complex.h"

int main()
{
	double mag = 3;
	double phi = 45;

	Complex z(1, 2);
	z.setFromPolar(mag, phi);

    std::cout << z.getRe() <<","<< z.getIm(); 
	xml_io::doxml();

	xml_io xml;
	xml.writexml();
}