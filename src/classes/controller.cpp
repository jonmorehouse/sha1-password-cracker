#include "classes/controller.hpp"

namespace application {

	Controller::Controller() {

		// initialize our dictionary
		this->dictionary = new std::unordered_map<std::string, std::string>();

	};


	Controller::~Controller() {




	};

	// simply hashes a single value
	void Controller::simpleHashing() {

		std::cout << "Please input a string to hash: ";
		std::string input = input::getString();	

		// grab the hash from out local function
		std::cout << this->getHexHash(input) << std::endl;

	}

	// 
	void Controller::loadDictionary() {

		// first open the file
		// second create callback to pass for each element
		// each string should be a hash etc
		auto helper = [this] (std::string input) {

			// hash the element
			std::string hash = this->getHexHash(input);

			// now insert a pair into the dictionary store!
			this->dictionary->insert(std::pair<std::string, std::string>(hash, input));
		};

		// initialize the filename
		std::string filename = "data/dictionary.txt";

		// load the file and for each line, have the helper function append to the list
		files::loadFile(filename.c_str(), helper);
	}

	// decrypt a single value as given 
	void Controller::decrypt() {

		// decrypt a single word




	}

	void Controller::decryptFile() {

		// decrypt a file of elements


	}	
	

	/************** PRIVATE FUNCTIONS **************/
	std::string Controller::getHexHash(std::string input) {

		//initialize a hexHash string holder
		char temp[41];

		// initialize string
		std::string hexHash;

		// generate a char to store the initial hash for our element
		unsigned char hash[20];

		// calculate the hash for the string input
		sha1::calc(input.c_str(), input.length(), hash);

		// actually grab the hexHash now
		sha1::toHexString(hash, temp);

		// copy the temp value over to the string
		hexHash = temp;//copy the temp over to the string

		// return the std::string 
		return hexHash;
	}

	void Controller::bruteForce() {

		// responsible for brute forcing all of the passwords and appending them to a list etc
		// have a lambda to pass the element to our dictionary


	}

};
