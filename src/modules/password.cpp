#include "modules/password.hpp"

namespace password {

	// require that a validCharacter vector passed in as well as a hash!
	// can change the min/max length other ways
	Password::Password(std::vector<char> * validCharacters, std::string hash, int minSize, int maxSize) : validCharacters(validCharacters), hash(hash), solved(false), maxSize(maxSize), minSize(minSize) {}
	
	// password crack element!
	void Password::crack() {

		// initialize guess string and set it to minimum size with the first character by default
		std::string guess(this->minSize, (*this->validCharacters)[0]);	

		// initialize the character element index
		std::vector<int> characterIndex(this->minSize, 0);

		// check whether or not this guess is correct
		auto check = [&characterIndex, &guess, this] () {

			// create string based upon the characterIndex and then check it properly
			std::string currentHash = getHexHash(guess);

			// 
			if (guess == "aaaa") std::cout << guess.length() << std::endl;

			// if the hash is not the current element then are done!
			if (this->hash != currentHash) return;

			// set the current status!
			else {

				this->solved = true;
				this->value = guess;
			}
		};

		// recursive function to iterate through all possibilities
		// this is really a lambda but doesn't use the auto syntax etc
		do {

			// move the first element each time
			for_each(this->validCharacters->begin(), this->validCharacters->end(), [&guess, check, this] (char character) {

				if (this->solved) return;

				guess[0] = character;//initialize the character
				check();//check this particular guess
				// check if solved each time
			});

			// break if solved 
			if (this->solved) break;

			// do some work with the counter etc!
			// now we know that the first element is equal to the last element of the validCharacters vector
			for (int i = 0, z = characterIndex.size() - 1; i < z; i++) {

				// if the current element is the last character in the character list then iterate the counter
				if (guess[i] == this->validCharacters->back()) {

					// set the guess element as the first element
					characterIndex[i] = 0;

					// if we need to iterate, but are at the last element then stop!
					if (guess.length() < this->maxSize - 1) {

						// push onto the back of the characterIndex vector
						characterIndex.push_back(0);
						// add an element to the guess
						guess.resize(guess.length() + 1);
					}

					// increment the character index by one!
					characterIndex[i+1]++;

					// increment the proper elements etc!
					guess[i] = (*this->validCharacters)[characterIndex[i]];
					guess[i+1] = (*this->validCharacters)[characterIndex[i+1]];
				}	
			}
		// set up the conditions --
		// can't be solved -- this won't happen because it will break first!
		// needs to be less than or equal to the maximum size
		// and the last character of hte last array can't equal the last element of the validCharacters vector
		} while(!this->solved && (guess.length() <= this->maxSize) && (guess[this->maxSize - 1] != this->validCharacters->back()));
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
