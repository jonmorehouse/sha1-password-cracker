#ifndef FILES_HPP
#define FILES_HPP

// project includes
// include data so that we can properly conrol the data that we will return
#include "modules/data.hpp"

// standard includes
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdlib.h>

// include mac specific headers to get files
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>


/*
	This namespace will be responsible for reading / writing files
	Will be responsible for pulling in proper file data
	Can later be a templated function namespace etc
*/
namespace files {

	// check existence etc
	bool fileExists(const char * filename);//will determine whether or not the file exists in the current scope etc

	// grab the contents
	Data<char> * getTextContents(const char * filename);//grab the contents of the file and place them into a square array and return a pointer to this element

	// grab the binary contents?
	Data<char> * getBinaryContents(const char * filename);//grab the contents of the file from binary data	
			
	// save contents to a file 
	void writeFile(const char ** content);//write the compressed contents to a file

	// grab a list of directory files -- will need to re-implement with windows / mac etc
	void directoryFiles(const char * directoryFile, std::vector<const char *> * files);//iterate through a directory and return files that exist

}

#endif