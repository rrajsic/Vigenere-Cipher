#include <fstream>
#include <iostream>
#include <string.h>
#include "HeaderFileOP.h"

bool exists(const std::string& name) {				//check if file exists
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
