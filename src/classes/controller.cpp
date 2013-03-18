#include "classes/controller.hpp"

namespace application {

	Controller::Controller() {

		// initialize our dictionary
		this->dictionary = new std::unordered_map<std::string, std::string>();

		// initialize the dictionary
		this->undefinedHashes = new std::queue<std::string>();//create a new queue to handle all of the hashes not currently found in our element!
	};


	Controller::~Controller() {

		delete this->dictionary;
		delete this->undefinedHashes;


	};

	// simply hashes a single value
	void Controller::simpleHashing() {

		std::cout << "Please input a string to hash: ";
		std::string input = input::getString();	

		// grab the hash from out local function
		std::cout << this->getHexHash(input) << std::endl;

	}

	// 
	void Controller::loadDictionary() {

		// first open the file
		// second create callback to pass for each element
		// each string should be a hash etc
		auto helper = [this] (std::string input) {

			// hash the element
			std::string hash = this->getHexHash(input);

			// now insert a pair into the dictionary store!
			this->dictionary->insert(std::pair<std::string, std::string>(hash, input));
		};

		// initialize the filename
		std::string filename = "data/dictionary.txt";

		// load the file and for each line, have the helper function append to the list
		files::loadFile(filename.c_str(), helper);
	}

	// decrypt a single value as given 
	void Controller::decrypt() {

		std::string hash,//hash that the user inputs
			value;//result

		// initialize the find element for this decryption
		std::unordered_map<std::string, std::string>::const_iterator result;

		// decrypt a single word
		// ask user to put in a hash!
		std::cout << "Please input an sha1 hex hash: ";
		// hash from user 
		hash = input::getString();//get the string with our modul 

		// actually find the hash in the dictionary
		result = this->dictionary->find(hash);

		// check and find the results
		if (result == this->dictionary->end())
			value = "NOT FOUND";

		else value = result->second;//save the value of the second piece of the pair

	}

	// decrypt all of the values of given file
	void Controller::decryptFile() {

		// grab the filename from our pieces
		std::string filename;
		// create a find element
		std::unordered_map<std::string, std::string>::const_iterator result;//result of the find piece

		// create a queue
		std::vector<std::string> hashes;//these are all of the hashes we are currently working with
		// put each queue in the password list
		// if its not found in the hash, then we need to bruteforce!
		// once we have brute-forced, print them all out! 
		// decrypt a file of elements
		auto helper = [this, &result, &hashes] (std::string hash) {

			// now check if the element is not found etc
			result = this->dictionary->find(hash);

			// now if not found need to queue it up to be brute-forced
			if (result == this->dictionary->end())
				this->undefinedHashes->push(hash);

			// now push the hash back into the vector of hashes for this current file
			hashes.push_back(hash);
		};

		// start functionality here
		// std::cout << "Please input the name of your hash file: ";
		// filename = input::getString();//grab the string filename

		filename = "data/hashes.txt";//cache the hashes element

		// now load the file and call our helper function each time to save the elements
		files::loadFile(filename.c_str(), helper);

		// now bruteforce any elements that need to be brute-forced
		this->bruteForce();

		// loop through all of the hashes and print them out -- everything should be solved -- if it was unable to be brute forced then it will be printed out poorly
		for_each(hashes.begin(), hashes.end(), [] (std::string input) {

			std::cout << input << std::endl;
		});

		// end of function ... 

	}	

	/************** PRIVATE FUNCTIONS **************/
	std::string Controller::getHexHash(std::string input) {

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

	void Controller::bruteForce() {

		// responsible for brute forcing all of the passwords and appending them to a list etc
		// have a lambda to pass the element to our dictionary
		// responsible for calling the brute forcing the proper modules

		// will be responsible for handling the hash etc
		auto helper = [this] (std::string hash, std::string value) {

			// push into the dictionary the new pair!
			this->dictionary->insert(std::pair<std::string, std::string>(hash, value));

		};			

		// now we just want to loop through each of the members 
		
	}

};
