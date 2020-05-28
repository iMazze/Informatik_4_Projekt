#include "Rechnung.h"


template<typename T>
Rechnung<T>::Rechnung()
{
}

template<typename T>
Rechnung<T>::~Rechnung()
{
}

template<typename T>
T & Rechnung<T>::getZahl1()
{
	// TODO: hier Rückgabeanweisung eingeben
}

template<typename T>
T & Rechnung<T>::getZahl2()
{
	// TODO: hier Rückgabeanweisung eingeben
	return nullptr;
}

template<typename T>
T & Rechnung<T>::getErgebnis()
{
	// TODO: hier Rückgabeanweisung eingeben
	return ergebnis;
}

template<typename T>
void Rechnung<T>::setZahl1(const T & Zahl)
{
	zahl1 = Zahl;
}

template<typename T>
void Rechnung<T>::setZahl2(const T & Zahl)
{
	zahl2 = Zahl;
}

template<typename T>
void Rechnung<T>::addieren()
{
	ergebnis = zahl1 + zahl2;
}

template<typename T>
void Rechnung<T>::subtrahieren()
{
	ergebnis = zahl1 - zahl2;
}

template<typename T>
void Rechnung<T>::multiplizieren()
{
	ergebnis = zahl1 * zahl2;
}

template<typename T>
void Rechnung<T>::dividieren()
{
	//todo check divide durch null
	ergebnis = zahl1 / zahl2;
}
