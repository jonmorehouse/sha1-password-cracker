#include "modules/password.hpp"

namespace password {

	// require that a validCharacter vector passed in as well as a hash!
	// can change the min/max length other ways
	Password::Password(std::vector<char> * validCharacters, std::string hash) : validCharacters(validCharacters), hash(hash), size(4), minSize(1) {}
	
	void Password::crack() {

		// guess element
		std::string guess;	

		// initialize the character element index
		std::vector<int> characterIndex(this->size, -1);



		auto check = [&characterIndex, &guess] () {

			// create string based upon the characterIndex and then check it properly
			for (int i = 0; i < characterIndex.size(); i++)
				guess[i] = characterIndex[i];

			std::cout << guess << std::endl;


		};

		// loop through all possible elements -- counting through our element each tim
		do {
			// loop through all of the validCharacters indices etc
			for (int i = 0; i < this->validCharacters->size(); i++) {
				characterIndex[0] = i;//
				check();//check with each combination
			}

			// loop through the size of the characters and then ensure that we need to they are the correct elements
			// go through and apply our counters for the different spots of the element accordingly
			for (int j = 0; j < characterIndex.size(); j) {

				if (characterIndex[j] == this->validCharacters->size() - 1)
					characterIndex[j+1] += 1;//increment the next element by 1
			}

		} while(characterIndex[this->size - 1] < this->validCharacters->size());


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
