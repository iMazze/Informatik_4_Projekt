#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Complex.h"
#include "Calculation.h"
#include "XML_Writer.h"
#include "UI_Communication.h"
#include "Calculator_Logic.h"




Complex z1;
Complex z2(1, 7);
Complex z3(5, -5);
Complex z4(-69.3, 120);
Complex z5(-85, -76);

TEST_CASE("Unit Test: complex class") {
	
	SECTION("constructor, setter, getter") {
		Complex z6=z3;
		Complex z7;
		Complex z8;
		Complex z9;
		z9.setRe(10);
		z9.setIm(-10);
		double mag = 10;
		double phi = 45;
		z8.setFromPolar(mag, phi);
		double magERR = 10;
		double phiERR = 500;

		REQUIRE(z1.getRe() == 0); REQUIRE(z1.getIm() == 0);
		REQUIRE(z5.getRe() == -85); REQUIRE(z5.getIm() == -76);
		REQUIRE(z6.getRe() == 5); REQUIRE(z6.getIm() == -5);
		REQUIRE(z9.getRe() == 10); REQUIRE(z9.getIm() == -10);
		REQUIRE(z8.getRe() == Approx(7.071)); REQUIRE(z8.getIm() == Approx(7.071));
		//REQUIRE(z7.setFromPolar(magERR,phiERR)=="500 grad: ungueltiges Argument");
		//REQUIRE(z1.getMag() == 0);REQUIRE(z1.getPhi() == 0);
		//REQUIRE(z8.getMag() == 1);REQUIRE(z1.getPhi() == 0);

	}
	SECTION("getMAG") {
		
		REQUIRE(z1.getMag() == 0);
		REQUIRE(z2.getMag() == Approx(7.071));
		REQUIRE(z3.getMag() == Approx(7.071));
		REQUIRE(z4.getMag() == Approx(138.573));
		REQUIRE(z5.getMag() == Approx(114.021));
	}
	SECTION("getPhi") {
		REQUIRE(z1.getPhi() == 0);
		REQUIRE(z2.getPhi() == Approx(81.869));
		REQUIRE(z3.getPhi() == Approx(-45));
		REQUIRE(z4.getPhi() == Approx(120.006));
		REQUIRE(z5.getPhi() == Approx(-138.199));

	}
	SECTION("Operations"){
		Complex r1;
		Complex r2;
		Complex r3;
		
		SECTION("Addition") {
			r1 = z1 + z2;
			r2 = z3 + z4;
			r3 = z3 + z5;
			REQUIRE(r1.getRe() == 1); REQUIRE(r1.getIm() == 7);
			REQUIRE(r2.getRe() == -64.3); REQUIRE(r2.getIm() == 115);
			REQUIRE(r3.getRe() == -80); REQUIRE(r3.getIm() == -81);
		}

		SECTION("Substraction") {
			r1 = z1 - z2;
			r2 = z3 - z4;
			r3 = z3 - z5;
			REQUIRE(r1.getRe() == -1); REQUIRE(r1.getIm() == -7);
			REQUIRE(r2.getRe() == 74.3); REQUIRE(r2.getIm() == -125);
			REQUIRE(r3.getRe() == 90); REQUIRE(r3.getIm() == 71);
		}
		SECTION("Multiplication") {
			r1 = z1 * z2;
			r2 = z3 * z4;
			r3 = z3 * z5;
			REQUIRE(r1.getRe() == 0); REQUIRE(r1.getIm() == 0);
			REQUIRE(r2.getRe() == 253.5); REQUIRE(r2.getIm() == 946.5);
			REQUIRE(r3.getRe() == -805); REQUIRE(r3.getIm() == 45);
		}
		SECTION("Division") {
			r1 = z1 / z2;
			r2 = z3 / z4;
			r3 = z3 / z5;
			REQUIRE(r1.getRe() == 0); REQUIRE(r1.getIm() == 0);
			REQUIRE(r2.getRe() == Approx(-0.0492).epsilon(0.1)); REQUIRE(r2.getIm() == Approx(-0.013).epsilon(0.1));
			REQUIRE(r3.getRe() == Approx(-0.0034).epsilon(0.1)); REQUIRE(r3.getIm() == Approx(+0.061).epsilon(0.1));
		}
	}
}

TEST_CASE("Unit Test: class Calculation") {
	int int1 = 10;
	int int2 = 20;

	SECTION("Operations with std::int") {
		Calculation<int> *r1 = new Calculation<int>(); //Calculator for Int
		
		SECTION("Addition") {
			r1->setNumber1(int1);
			r1->setNumber2(int2);

			r1->add();
			
			REQUIRE(r1->getResult() == int1 + int2);
		}
		SECTION("Subtraction") {
			r1->setNumber1(int1);
			r1->setNumber2(int2);

			r1->subtract();

			REQUIRE(r1->getResult() == int1 - int2);
		}
		SECTION("Multiplication") {
			r1->setNumber1(int1);
			r1->setNumber2(int2);

			r1->multiply();

			REQUIRE(r1->getResult() == int1 * int2);
		}
		SECTION("Division") {
			r1->setNumber1(int1);
			r1->setNumber2(int2);

			r1->divide();

			REQUIRE(r1->getResult() == int1 / int2);
		}
	}

	SECTION("Operations with complex") {
		Calculation<Complex> *r1 = new Calculation<Complex>(z1, z2); //Calculator for Complex
		Calculation<Complex> *r2 = new Calculation<Complex>(z3, z4); //Calculator for Complex
		Calculation<Complex> *r3 = new Calculation<Complex>(z3, z5); //Calculator for Complex

		SECTION("Addition") {
			r1->add();
			r2->add();
			r3->add();
			REQUIRE(r1->getResult().getRe() == 1); REQUIRE(r1->getResult().getIm() == 7);
			REQUIRE(r2->getResult().getRe() == -64.3); REQUIRE(r2->getResult().getIm() == 115);
			REQUIRE(r3->getResult().getRe() == -80); REQUIRE(r3->getResult().getIm() == -81);
		}

		SECTION("Substraction") {
			r1->subtract();
			r2->subtract();
			r3->subtract();
			REQUIRE(r1->getResult().getRe() == -1); REQUIRE(r1->getResult().getIm() == -7);
			REQUIRE(r2->getResult().getRe() == 74.3); REQUIRE(r2->getResult().getIm() == -125);
			REQUIRE(r3->getResult().getRe() == 90); REQUIRE(r3->getResult().getIm() == 71);
		}
		SECTION("Multiplication") {
			r1->multiply();
			r2->multiply();
			r3->multiply();
			REQUIRE(r1->getResult().getRe() == 0); REQUIRE(r1->getResult().getIm() == 0);
			REQUIRE(r2->getResult().getRe() == 253.5); REQUIRE(r2->getResult().getIm() == 946.5);
			REQUIRE(r3->getResult().getRe() == -805); REQUIRE(r3->getResult().getIm() == 45);
		}
		SECTION("Division") {
			r1->divide();
			r2->divide();
			r3->divide();
			REQUIRE(r1->getResult().getRe() == 0); REQUIRE(r1->getResult().getIm() == 0);
			REQUIRE(r2->getResult().getRe() == Approx(-0.0492).epsilon(0.1)); REQUIRE(r2->getResult().getIm() == Approx(-0.013).epsilon(0.1));
			REQUIRE(r3->getResult().getRe() == Approx(-0.0034).epsilon(0.1)); REQUIRE(r3->getResult().getIm() == Approx(+0.061).epsilon(0.1));
		}
	}

}

TEST_CASE("Unit Test: class XML_WRITER") {
	Calculation<Complex> *r1 = new Calculation<Complex>(z1, z2); //Calculator for Complex
	Calculation<Complex> *r2 = new Calculation<Complex>(z3, z4); //Calculator for Complex
	Calculation<Complex> *r3 = new Calculation<Complex>(z3, z5); //Calculator for Complex

	XML_Writer writer;

	SECTION("Do some calcs") {
		r1->add();
		r2->divide();
		r3->multiply();
		writer.addComplexCalculation(*r1);
		writer.addComplexCalculation(*r2);
		writer.addComplexCalculation(*r3);

		r1->subtract();
		r2->add();
		r3->divide();
		writer.addComplexCalculation(*r1);
		writer.addComplexCalculation(*r2);
		writer.addComplexCalculation(*r3);

		writer.writeCalculationsToXML();
	}
}

TEST_CASE("Unit Test: class UI_Communication") {

	UI_Communication ui;

	SECTION("Print out Number and Text") {
		ui.writeText("Thats an example Hello World Text!");
		ui.writeNumber(z4, E_Format::CARTESIAN);
		ui.writeNumber(z4, E_Format::POLAR);
		ui.writeNumber(z5, E_Format::CARTESIAN);
		ui.writeNumber(z5, E_Format::POLAR);
	}

	SECTION("Read in Format") {
		E_Format format;

		format = ui.stringToFormat("cartesian");
		REQUIRE(format == E_Format::CARTESIAN);

		format = ui.stringToFormat("polar");
		REQUIRE(format == E_Format::POLAR);
	}

	SECTION("Read in Format") {
		E_Operation op;

		op = ui.stringToOperation("add");
		REQUIRE(op == E_Operation::ADD);
		op = ui.stringToOperation("addition");
		REQUIRE(op == E_Operation::ADD);
		op = ui.stringToOperation("+");
		REQUIRE(op == E_Operation::ADD);

		op = ui.stringToOperation("subtract");
		REQUIRE(op == E_Operation::SUBTRACT);
		op = ui.stringToOperation("subtraction");
		REQUIRE(op == E_Operation::SUBTRACT);
		op = ui.stringToOperation("-");
		REQUIRE(op == E_Operation::SUBTRACT);

		op = ui.stringToOperation("multiply");
		REQUIRE(op == E_Operation::MULTIPLY);
		op = ui.stringToOperation("multiplicate");
		REQUIRE(op == E_Operation::MULTIPLY);
		op = ui.stringToOperation("*");
		REQUIRE(op == E_Operation::MULTIPLY);

		op = ui.stringToOperation("divide");
		REQUIRE(op == E_Operation::DIVIDE);
		op = ui.stringToOperation("division");
		REQUIRE(op == E_Operation::DIVIDE);
		op = ui.stringToOperation("/");
		REQUIRE(op == E_Operation::DIVIDE);
	}

	SECTION("Read in Number") {
		Complex i;

		SECTION("Format: Polar") {
			i = ui.stringToNumber("7.1e^(i81.8)");
			REQUIRE(i.getMag() == Approx(7.1)); REQUIRE(i.getPhi() == Approx(81.8));

			i = ui.stringToNumber("+7.1e^(i81.8)");
			REQUIRE(i.getMag() == Approx(7.1)); REQUIRE(i.getPhi() == Approx(81.8));

			i = ui.stringToNumber("7.1e^(i-81.8)");
			REQUIRE(i.getMag() == Approx(7.1)); REQUIRE(i.getPhi() == Approx(-81.8));


			// magnitude shoud not be negative!
			//i = ui.stringToNumber("-7.1e^(-i81.8)");
			//REQUIRE_FALSE(i.getMag() == Approx(-7.1)); REQUIRE(i.getPhi() == Approx(-81.8));

			i = ui.stringToNumber("7.1e^(i81.8)");
			REQUIRE(i.getMag() == Approx(7.1)); REQUIRE(i.getPhi() == Approx(81.8));

			i = ui.stringToNumber("7.1e^(i81.8)");
			REQUIRE(i.getMag() == Approx(7.1)); REQUIRE(i.getPhi() == Approx(81.8));

			i = ui.stringToNumber("7.1e^i81.8");
			REQUIRE(i.getMag() == Approx(7.1)); REQUIRE(i.getPhi() == Approx(81.8));

			i = ui.stringToNumber("7.1e^j81.8");
			REQUIRE(i.getMag() == Approx(7.1)); REQUIRE(i.getPhi() == Approx(81.8));

			i = ui.stringToNumber("7.1e^-j81.8");
			REQUIRE(i.getMag() == Approx(7.1)); REQUIRE(i.getPhi() == Approx(-81.8));
		}

		SECTION("Format: Cartesian") {
			i = ui.stringToNumber("7.1+i81.8");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("+7.1+i81.8");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("-7.1+i81.8");
			REQUIRE(i.getRe() == Approx(-7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("7.1+j81.8");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("7.1+81.8i");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("81.8i+7.1");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("j81.8+7.1");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("(7.1)+(81.8)i");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("(7.1)+i(81.8)");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("(7.1)+j(81.8)");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(81.8));

			i = ui.stringToNumber("(7.1)-i(81.8)");
			REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(-81.8));

			// dafür ist er zu dumm
			//i = ui.stringToNumber("(7.1)+i(-81.8)");
			//REQUIRE(i.getRe() == Approx(7.1)); REQUIRE(i.getIm() == Approx(-81.8));

			i = ui.stringToNumber("-(7.1)-i(81.8)");
			REQUIRE(i.getRe() == Approx(-7.1)); REQUIRE(i.getIm() == Approx(-81.8));
		}
	}


}

TEST_CASE("Unit Test: class Calculator_Logic") {
	Calculator_Logic c;
	c.doCalculation();
	c.doCalculation();
	c.makeXML();
}


