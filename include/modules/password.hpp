#pragma once

// project libraries
#include "modules/sha1.hpp"

// c++ standard libraries
#include <iostream>
#include <string>
#include <vector>

//  
namespace password {

	struct Password {

		// 
		Password();
		// password over-loaded constructor
		Password(std::vector<char> * validCharacters, std::string hash, int size);

		// functions for the element
		void crack();//

		//data member elements
		std::vector<char> * validCharacters;//valid characters etc 
		std::string hash;//hash length
		std::string value;//current hash

		int size;//length of the character
		bool status;//status of the element

	};	
		
	// grab the password hash!
	std::string getHexHash(std::string input);//get the hash for a string
	
};

