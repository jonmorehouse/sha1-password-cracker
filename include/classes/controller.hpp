#pragma once

// load the modules file
#include "modules/input.hpp"
#include "modules/files.hpp"
#include "modules/password.hpp"

// include some c++ standard libraries
#include <unordered_map>
#include <queue>
#include <string>


// application 
namespace application {

	class Controller {

		public:

			Controller();
			~Controller();

		public://public controller functions

			void simpleHashing();//run the simple hashing functionality!
			void loadDictionary();//load the dictionary element

			// decryption helpers
			void decrypt();//decrypt a single element -- will append to the dictionary
			void decryptFile();//decrypt the dictionary from hashes	

			// print helpers
			const void printDictionary();

		private://

			// brute force and load into the dictionary
			void bruteForce();//will brute force all of the undefined hashes etc

		private://unfound elements 

			// unordered map to store all dictionary elements
			std::unordered_map<std::string, std::string> * dictionary;//use the standard string to help with the automated hashing function etc ...

			// each of the undefinedHashes will 
			std::queue<std::string> * undefinedHashes;//this is the container that will hold all of our undefined hashes for this class

			// store all valid characters for the brute-forcing!
			std::vector<char> * validCharacters;//

			struct {

				std::string hashesFile;
				std::string dictionaryFile;
				std::string validCharactersFile;

			} data;

	};
};