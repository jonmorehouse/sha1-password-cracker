#include "modules/password.hpp"

namespace password {

	// require that a validCharacter vector passed in as well as a hash!
	// can change the min/max length other ways
	Password::Password(std::vector<char> * validCharacters, std::string hash) : validCharacters(validCharacters), hash(hash), size(4), minSize(1) {}
	
	void Password::crack() {

		// std::string guess(this->size, (*this->validCharacters)[0]);//this is the current guess
		std::string guess;
		
		auto check = [] () {

			// check the guess element here!

		};		

		// loop through all indexes of the value
		for (int i = 0; i < this->size; i++) {

			// loop through all of the characters 
			for_each(this->validCharacters->begin(), this->validCharacters->end(), [&guess, i] (char character) {

				std::cout << character << std::endl;

				// guess[i] = character;
				// check();//check the value -- if it is true it will kill the entire function!
			});
		}//end of for loop
		

	}


	// grab the hex hash from basic hashing function implemented
	std::string getHexHash(std::string input) {

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

};
