#include "modules/password.hpp"

namespace password {

	// require that a validCharacter vector passed in as well as a hash!
	// can change the min/max length other ways
	Password::Password(std::vector<char> * validCharacters, std::string hash) : validCharacters(validCharacters), hash(hash), solved(false), maxSize(8), minSize(4) {}
	
	// password crack element!
	void Password::crack() {

		// initialize guess string and set it to minimum size with the first character by default
		std::string guess(this->minSize, (*this->validCharacters)[0]);	

		// initialize the character element index
		std::vector<int> characterIndex(this->minSize, 0);

		// check whether or not this guess is correct
		auto check = [&characterIndex, &guess] () {

			// create string based upon the characterIndex and then check it properly
			// for (int i = 0; i < characterIndex.size(); i++)
				// guess[i] = characterIndex[i];

			std::cout << guess << std::endl;
		};

		// recursive function to iterate through all possibilities
		// this is really a lambda but doesn't use the auto syntax etc
		do {

			// move the first element each time
			for_each(this->validCharacters->begin(), this->validCharacters->end(), [&guess, check] (char character) {

				guess[0] = character;//initialize the character
				check();//check this particular guess
			});

			// do some work with the counter etc!
			// now we know that the first element is equal to the last element of the validCharacters vector
			for (int i = 0, z = characterIndex.size() - 1; i < z; i++) {

				// if the current element is the last character in the character list then iterate the counter
				if (guess[i] == this->validCharacters->back()) {

					// set the guess element as the first element
					characterIndex[i] = 0;

					// make sure that we are not the last element already
					if (i + 1 >= this->maxSize)

					// insert resize logic here!
					// resize if we are the second to last element
					// resize if we are under the maxsize etc
					if (i+1 >= guess.length() && guess.length() < this->maxSize) {



					}

					// 
					characterIndex[i+1]++;
				}	

			}

		// set up the 
		} while(!this->solved && (guess.length() <= this->maxSize) && (guess[this->maxSize - 1] == this->validCharacters->back()));
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
