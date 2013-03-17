#ifndef DATA_HPP
#define DATA_HPP

//project includes etc

// c++ standard libraries
#include <iostream>
#include <stdlib.h>
#include <fstream>

// this data structure is vital for easily working with data throughout the input / output
// initialize a data structure that can hold all of the pieces of the element
template <typename T>
struct Element {

	short length;//length of the element -- if its less than 0 then we know its a negative length and to look at how many elements we have!
	T * data;//this is the type of elment that is stored etc
};

// data structure is for text files etc
template <typename T>
struct Data {

	int length;//length of the element -- if its less than 0 then we know its a negative length and to look at how many elements we have!
	T * data;//this is the type of elment that is stored etc
};

template <typename T>
struct RLE{

	// initialize a place in memory to store the array of the elemnet pieces that will store the compressed elements
	Element<T> * data;//this is the data that will store the uncompressed / compressed data
	T * uncompressedData;//this is the raw data
	int size;//this is how long the data currently is

	RLE() : data(NULL) , size(0) {


	}	

	~RLE() {

		delete data;//actually remove our data and free this structure
	}

	// compress the input data and store it as teh data element in this structure
	void compress(const T* input, const int size);

	// decompress the data
	void decompress(const Element<T> * input, const int size);//takes in the data and will then return 

	// write the file 
	void writeFile(const char * filename);//throw in a filename to write the compressed data too!

	// grab the maximum run size element for this particular data type
	int maxRunSize();// declare the maximum run

	// declare a friend function that can be included in other projects to help output the data

};

// include the actual implementation of these files
#include "data.tpp"



#endif