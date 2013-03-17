#include "classes/controller.hpp"

namespace application {

	Controller::Controller() {




	};


	Controller::~Controller() {




	};

	// 
	void Controller::simpleHashing() {

		std::cout << "Please input a string to hash.";
		std::string input = input::getString();	


		// allocate the correct amount of memory 
		char * output = new char[41]();

		// grab the hash from out local function
		this->getHexHash(input, output);

		std::cout << output << std::endl;

		// delete the current hash
		delete output;
	}

	// 
	void Controller::loadDictionary() {

		// first open the file
		// second create callback to pass for each element
		// each string should be a hash etc



	}

	// 
	void Controller::decrypt() {

		// for each of the hashed passwords
		// try to look up in the unordered map
		// if you can't find it then bruteforce
		// keep a stack of unmatched passwords
		// when we match them -- append to the dictionary list!
			
	}
	

	/************** PRIVATE FUNCTIONS **************/
	void Controller::getHexHash(std::string input, char * hexHash) {

		// generate a char to store the initial hash for our element
		unsigned char hash[20];

		// calculate the hash for the string input
		sha1::calc(input.c_str(), input.length(), hash);

		// actually grab the hexHash now
		sha1::toHexString(hash, hexHash);
	}


};
