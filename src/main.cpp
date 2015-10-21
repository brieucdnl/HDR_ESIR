#include <iostream>

#include "Image.h"
#include "HDR.h"

int main(int argc, char* argv[])
{
	Image *I;
	HDR *processor;
	
	// Creating the HDR_Processor
	processor = new HDR();
	
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
		for(int i = 1; i < argc; i++)
		{
			I = new Image(argv[i]);
			processor->add(I);
		}
	}

	// Display Image
	for(int i = 0; i < processor->getVecImg().size(); i++)
	{
		std::cout << "Image name: " << processor->getVecImg()[i]->getNameImage() << std::endl;
		std::cout << "Shutter speed: " << processor->getVecImg()[i]->getShutterSpeed() << " sec" << std::endl;
		std::cout << "Camera model: " << processor->getVecImg()[i]->getCameraModel() << std::endl;
		processor->getVecImg()[i]->displayImage();
	}

	delete processor; 
}
