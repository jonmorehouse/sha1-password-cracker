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

		//pass in valid chars and a hash!	
		Password(std::vector<char> * validCharacters, std::string hash);

		// functions for the element
		void crack();//

		//data member elements
		std::vector<char> * validCharacters;//valid characters etc 
		std::string hash;//hash length
		std::string value;//current hash

		int size;//length of the password
		int minSize;//minimum length of password
		bool status;//status of the element

	};	
		
	// grab the password hash!
	std::string getHexHash(std::string input);//get the hash for a string
	
};

