#include "stdafx.h"
#include "CppUnitTest.h"

#include "../complex_calculator/Rechnung.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace complex_calculator_unittest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Testcode hier eingeben
			Rechnung<int> r1;
			int a, b, c;

			a = 11;
			b = 22;

			r1.setZahl1(a);
			r1.setZahl2(b);
			r1.addieren();
			c = r1.getErgebnis();

			Assert::IsTrue((a + b) == c);
		}

	};
}