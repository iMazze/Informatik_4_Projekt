// complex_calculator.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "xml_io.h"
#include "Complex.h"

int main()
{
	Complex z(1, 2);

    std::cout << "Hello World!\n"; 
	xml_io::doxml();

	xml_io xml;
	xml.writexml();
}