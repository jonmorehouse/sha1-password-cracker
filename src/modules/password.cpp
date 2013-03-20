#include "modules/password.hpp"

namespace password {

	// require that a validCharacter vector passed in as well as a hash!
	// can change the min/max length other ways
	Password::Password(std::vector<char> * validCharacters, std::string hash) : validCharacters(validCharacters), hash(hash), solved(false), size(4), minSize(1) {}
	
	// password crack element!
	void Password::crack() {

		// guess element
		std::string guess;	

		// initialize the character element index
		std::vector<int> characterIndex(this->size, 0);

		// check whether or not this guess is correct
		auto check = [&characterIndex, &guess] () {

			// create string based upon the characterIndex and then check it properly
			for (int i = 0; i < characterIndex.size(); i++)
				guess[i] = characterIndex[i];

			std::cout << guess << std::endl;

		};

		// recursive function to iterate through all possibilities
		// this is really a lambda but doesn't use the auto syntax etc
		std::function<void()> worker = [&] () {


			for_each(this->validCharacters->begin(), this->validCharacters->end(), [&guess] (char character) {

				guess[0] = character;//initialize the character
				// check();//check this particular guess
			});

			// iterate the next element by 1
			characterIndex[0] = 0;
			// increment the next element by 1
			characterIndex[1] += 1;

			// now check which carryovers need to occur
			for (int i = 1, z = this->size - 1; i < z; i++) {

				// look and see if hte current index is equal to the size of the characters list
				// if so, then lets carry over a 1 to the next element
				if (characterIndex[i] == this->validCharacters->size() - 1) {

					// carry over to the next element
					characterIndex[i+1] += 1;
					// reset the current element
					characterIndex[i] = 0;
				}
			}

			// set up condition for next iteration etc!
			if (!this->solved && (characterIndex[this->size - 1] < this->validCharacters->size() - 1))
				return worker();
		};


		// resize guess so that it plays nice for output
		guess.resize(this->size);
		// start the worker call
		worker();

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
