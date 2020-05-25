#include "CppUnitTest.h"

#include "../complex_calculator/xml_io.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace complex_calculator_test
{		
	//!  A test class. 
	/*!
	  A more elaborate class description.
	*/
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		//! A test method.
		/*!
			A more elaborate description of the method.
		*/
		TEST_METHOD(TestMethod1)
		{
			xml_io io;
			io.doxml();

			int i = 0;
			Assert::IsTrue(!0); //! test test test.
		}

	};
}