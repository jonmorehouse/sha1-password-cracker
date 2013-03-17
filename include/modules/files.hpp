#pragma once

#include <iostream>
#include <fstream>

namespace files {

	// load file is useful for passing in a filename and then giving a callback to be called with the contents of each line!
	void loadFile(const char * filename, std::function<void(int i)> callback);
	

}

