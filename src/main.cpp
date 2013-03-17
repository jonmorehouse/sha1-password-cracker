// include all project libraries	
#include "modules/input.hpp"
#include "modules/controller.hpp"

// include project dependencies
#include <iostream>

// 
void menuOptions() {

	// print out all valid menu options as given in the assignment syllabus
	std::cout << "1.) -- Simple Hashing.\n";// hash basic user input
	std::cout << "2.) -- Load Dictionary.\n"; //hash all of the words in the dictionary file
	std::cout << "3.) -- Decrypt.\n";//
	std::cout << "4.) -- Exit.\n";

}

void menuController() {

	// cache our menu selection locally with input
	int selection;//this is the selection from our user

	do {

		// print out the menu options
		menuOptions();//actually display the various menu options etc for this program

		// grab the integer from our input module
		selection = input::getInteger();//get an integer using our secure method for grabbing integers

		// switch will go here to load in the proper controller functions to operate 
		switch (selection) {

			case 1://tests 

				break;

			case 2://compress single file
			
				break;

			case 3://compress directory

				break;	

			case 4: //decompress file

				break;
		}			

	// break statement responsible for exiting the program etc
	} while (selection != 5);
}


int main(int argc, char ** argv) {

		

}
