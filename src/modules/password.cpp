#include "modules/password.hpp"

namespace password {

	Password::Password() {




	}
	
	Password::Password(std::vector<char> * validCharacters, std::string hash, int size) : validCharacters(validCharacters), hash(hash), size(size)  {




	}

	void Password::crack() {

		std::cout << "HELLO WORLD FROM PASSWORD CRACK!" << std::endl;

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