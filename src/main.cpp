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
	std::cout << "Image name: " << I->getNameImage() << std::endl;
	std::cout << "Shutter speed: " << I->getShutterSpeed() << " sec" << std::endl;
	std::cout << "Camera model: " << I->getCameraModel() << std::endl;
	I->displayImage();

	delete I;
}
