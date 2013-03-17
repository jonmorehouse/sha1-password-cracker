#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

// include any project libraries
#include "modules/data.hpp"
#include "modules/files.hpp"

// include c libraries that are needed here
#include <iostream>
#include <string>

/*
	
	This program is responsible for controlling the application
	Should be called from the main file
	This is menu driven, so each piece is a module that will merely interact with the proper mechanisms etc

*/
namespace controller {

	
	void test();//responsible for running the test suite / sample words etc ..
	void compressFile();//compress a single file
	void compressDirectory();//responsible for compressing an entire directory	
	void decompressFile();//responsible for decompressing a file	
	void commandLine();//run the command line mode of the application

	// private module functions
	void compressFile(std::string filename);	
	void decompressFile(std::string filename);
}

#endif