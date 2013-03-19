#pragma once

// project libraries
#include "modules/sha1.hpp"

// c++ standard libraries
#include <iostream>
#include <string>
#include <vector>

//  
namespace application {

	struct Password {

		std::vector<char> * validCharacters;//valid characters etc 
		std::string hash;//hash length
		std::string value;//current hash

		int length;//length of the character
		bool status;//status of the element

		// functions for the element
		void crack();//
	};	
	
};

