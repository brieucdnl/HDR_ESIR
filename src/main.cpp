#include <iostream>

#include "Image.h"

int main(int argc, char* argv[])
{
	Image *I;

	// Handle parameters
	if(argv[1] == NULL)
	{
		std::string file;
		std::cout << "Please, you may enter a file" << std::endl;
		std::cin >> file;
		I = new Image(file.c_str());
	}
	else
	{
		I = new Image(argv[1]);
	}

	// Display Image
	I->displayImage();

	delete I;
}
