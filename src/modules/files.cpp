#include "modules/files.hpp"

namespace files {

	// can pass in either a lambda or a normal pointer to a function etc
	void loadFile(const char * filename, std::function<void(std::string input)> callback) {

		// create a file buffer for the input file
		std::ifstream file(filename);//initialize with the file passed in
		std::string current;//current line of the file


		// make sure that we are actually working with a valid file
		if (!file.is_open()) {

			// print some sort of message if we have problems and then just exit for now
			std::cout << "INVALID FILE" << std::endl;
			exit(1);
		}

		// loop through our file while we are getting the information that we need
		while (file.good()) {

			// grab current line
			getline(file, current);
			// since our callback assumes that we are passing a string to the callback function go ahead and pass this line to the callback
			callback(current);//make the lambda call / function call etc
		}

		// close the file when we are done
		file.close();
	}
}
