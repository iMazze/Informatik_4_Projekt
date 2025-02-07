#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "Calculator_Logic.h"
#include "Messages.h"


Calculator_Logic c;

int main(int argc, char* argv[]) {
	std::string input;
	int result = 0;

	// Print welcome message
	std::cout << MSG_WELCOME << std::endl << MSG_HELP << std::endl;

	while (1)
	{
		// get the user input
		std::cin >> input;

		try
		{
			switch (stoi(input))
			{
			case 0:
				return result;
				break;
			case 1:
				c.doCalculation();
				break;
			case 2:
				c.makeXML();
				break;
			case 3:
				result = Catch::Session().run(argc, argv);
			}
		}
		catch (const std::exception& e)
		{
			break;
		}
		std::cout << MSG_SEPERATOR << std::endl;
		std::cout << MSG_HELP << std::endl;
	}

	return result;
}
