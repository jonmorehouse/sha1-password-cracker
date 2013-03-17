#include "classes/controller.hpp"

namespace application {

	Controller::Controller() {




	};


	Controller::~Controller() {




	};

	// 
	void Controller::simpleHashing() {

		// std::cout << "Please input a string to hash.";
		// std::string input = input::getString();	

			
		// allocate the correct amount of memory 
		char * output = (char *)malloc(41 * sizeof(char));

		this->getHexHash(input, output);

		std::cout << output << std::endl;

		free output;
	}

	// 
	void Controller::loadDictionary() {



	}

	// 
	void Controller::decrypt() {




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
