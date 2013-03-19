// include project libraries that are needed for testing
#include "modules/input.hpp"
#include "modules/files.hpp"
#include "modules/sha1.hpp"
#include "modules/password.hpp"
#include "classes/controller.hpp"

// include c++ libraries that are not included previously
#include <iostream>
#include <string>

// test input module for various user input elements
void testInput() {

	std::cout << "Test integer input" << std::endl;
	std::cout << input::getInteger() << std::endl;

	std::cout << "Test string input" << std::endl;
	std::cout << input::getString() << std::endl;

};

// test the files module
void testFiles() {

	// testInt 
	int testInt = 0;

	// basic small callback for the element
	auto callback = [&testInt] (std::string line) {

		testInt++;
	};

	// run the laod file module
	files::loadFile("./data/test.txt", callback);

	std::cout << "Lines: " << testInt << std::endl;
}

void testHash() {

	// sha1 hash for algorithm
	unsigned char hash[20];	

	// abcd calc output
	sha1::calc("abcd", 4, hash);

	// output what the hash looks like
	std::cout << hash << std::endl;

	// hex string output
	char hex_str[41];
	// call the sha1 library hashing function
	sha1::toHexString(hash, hex_str);

	// output the hex string variable
	std::cout << hex_str << std::endl;

}

void testController() {

	// 
	application::Controller controller;//

	// works verified online
	// controller.simpleHashing();//run the simple hash test
	controller.loadDictionary(); // test the basic dictionary functionality
	controller.decryptFile();//load the file 
	// controller.printDictionary();

}

void testPassword() {

	password::Password password;//password element
	

}


int main() {

	// testInput();//test the input module

	// testFiles();//test the file input module

	// testInput();//test the input module

	// testController();

	testPassword();//


}
