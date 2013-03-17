#pragma once

// load the modules file
#include "modules/input.hpp"
#include "modules/files.hpp"
#include "modules/sha1.hpp"

namespace application {

	class Controller {

		public:

			Controller();
			~Controller();

		public://public controller functions

			void simpleHashing();//run the simple hashing functionality!
			void loadDictionary();//load the dictionary element
			void decrypt();//decrypt the dictionary from hashes	


		private:

			void getHexHash(std::string, char * hexHash);//get the hash for a string
	};
};