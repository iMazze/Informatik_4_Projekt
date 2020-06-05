/**
 * @file Calculation.h
 *
 * @brief Represents a mathematical calculation with two numbers 
 * @author Johannes Eberle
 */
#pragma once
//!  Enum for setting a operation within a variable
enum class E_Operation { NONE, ADD, SUBTRACT, MULTIPLY, DIVIDE };


//!  Class Calculation represents a mathematical calculation with two numbers 
/*!
  The type independent calculation class saves two numbers and the result after a mathematical operation, which can be done with a function.
*/
template <typename T>
class Calculation
{
private:
	T _number1; //! Storage for the first number
	T _number2; //! Storage for the second number
	T _result;  //! Storage for the result of operation
	E_Operation _lastOperation; //! Storage for last done calculation operation.
public:
	//! Constructor for Class Calcualtion
	Calculation();
	//! Constructor for Class Calcualtion with two numbers for storing directly
	Calculation(const T &n1, const T &n2);

	//! Returns the first number
	T &getNumber1(); 
	//! Returns the second number
	T &getNumber2();
	//! Returns the result of the calcualtion
	T &getResult(); 
	//! Sets the first number
	void setNumber1(const T &number);
	//! Sets the first number
	void setNumber2(const T &number);

	//! Do the operation add
	void add();
	//! Do the operation subtract
	void subtract();
	//! Do the operation multiply
	void multiply();
	//! Do the operation divide
	void divide();

	//! Returns the last done operation
	E_Operation getLastOperation();
};

template<typename T>
Calculation<T>::Calculation()
{
}

template<typename T>
Calculation<T>::Calculation(const T & n1, const T & n2)
	: _number1(n1), _number2(n2)
{
}

template<typename T>
T & Calculation<T>::getNumber1()
{
	return _number1;
}

template<typename T>
T & Calculation<T>::getNumber2()
{
	return _number2;
}

template<typename T>
T & Calculation<T>::getResult()
{
	return _result;
}

template<typename T>
void Calculation<T>::setNumber1(const T & number)
{
	_number1 = number;
}

template<typename T>
void Calculation<T>::setNumber2(const T & number)
{
	_number2 = number;
}

template<typename T>
void Calculation<T>::add()
{
	_lastOperation = E_Operation::ADD;
	_result = _number1 + _number2;
}

template<typename T>
void Calculation<T>::subtract()
{
	_lastOperation = E_Operation::SUBTRACT;
	_result = _number1 - _number2;
}

template<typename T>
void Calculation<T>::multiply()
{
	_lastOperation = E_Operation::MULTIPLY;
	_result = _number1 * _number2;
}

template<typename T>
void Calculation<T>::divide()
{
	try
	{
		_lastOperation = E_Operation::DIVIDE;
		_result = _number1 / _number2;
	} 
	catch (const std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

template<typename T>
inline E_Operation Calculation<T>::getLastOperation()
{
	return _lastOperation;
}

