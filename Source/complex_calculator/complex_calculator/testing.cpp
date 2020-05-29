
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Complex.h"

TEST_CASE("check constructor") {
	Complex z(1,2);
	REQUIRE(z.getRe() == 1);

}


