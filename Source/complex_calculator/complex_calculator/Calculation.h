#pragma once

enum class E_Operation { NONE, ADD, SUBTRACT, MULTIPLY, DIVIDE };


template <typename T>
class Calculation
{
private:
	T number1;
	T number2;
	T result;
	E_Operation lastOperation;
public:
	Calculation();
	Calculation(const T &n1, const T &n2);

	T &getNumber1(); //! Gibt die Zahl 1 zurück
	T &getNumber2(); //! Gibt die Zahl 2 zurück
	T &getResult(); //! Gibt das Ergebnis zurück
	void setNumber1(const T &number);
	void setNumber2(const T &number);

	void add();
	void subtract();
	void multiply();
	void divide();

	E_Operation getLastOperation();
};

template<typename T>
Calculation<T>::Calculation()
{
}

template<typename T>
Calculation<T>::Calculation(const T & n1, const T & n2)
	: number1(n1), number2(n2)
{
}

template<typename T>
T & Calculation<T>::getNumber1()
{
	return number1;
}

template<typename T>
T & Calculation<T>::getNumber2()
{
	return number2;
}

template<typename T>
T & Calculation<T>::getResult()
{
	return result;
}

template<typename T>
void Calculation<T>::setNumber1(const T & number)
{
	number1 = number;
}

template<typename T>
void Calculation<T>::setNumber2(const T & number)
{
	number2 = number;
}

template<typename T>
void Calculation<T>::add()
{
	lastOperation = E_Operation::ADD;
	result = number1 + number2;
}

template<typename T>
void Calculation<T>::subtract()
{
	lastOperation = E_Operation::SUBTRACT;
	result = number1 - number2;
}

template<typename T>
void Calculation<T>::multiply()
{
	lastOperation = E_Operation::MULTIPLY;
	result = number1 * number2;
}

template<typename T>
void Calculation<T>::divide()
{
	lastOperation = E_Operation::DIVIDE;
	result = number1 / number2;
}

template<typename T>
inline E_Operation Calculation<T>::getLastOperation()
{
	return lastOperation;
}

