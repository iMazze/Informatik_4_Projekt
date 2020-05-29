
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Complex.h"

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


