#include "modules/input.hpp"

namespace input {

	int getInteger() {

		std::string lineData;//line data that will be grabbed so we can extract our string from it	

		// int input is the integer data that we will extract from the string
		int data;

		// now actually grab the user input!
		getline(std::cin, lineData);

		// now grab the actual integer from the string stream that we created
		std::stringstream(lineData) >> data;

		return data;
	}

	std::string getString() {


		

	}


};

