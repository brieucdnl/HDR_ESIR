#include <iostream>

#include "opencv2/highgui/highgui.hpp"

#include "libraw/libraw.h"

int main(int argc, char* argv[])
{
	LibRaw rawProcessor;

	// If there is no parameter during the programm launch
	if(argv[1] == NULL)
	{
		std::string file;
		std::cout << "Please, you may enter a file" << std::endl;
		std::cin >> file;
		if(rawProcessor.open_file(file.c_str()) != LIBRAW_SUCCESS)
		{
			std::cout << "Sorry there is an error while trying to open the file !" << std::endl;
		}
		else
		{
			std::cout << "Image size: " << rawProcessor.imgdata.sizes.width << " x " << rawProcessor.imgdata.sizes.height << std::endl;
		}
	}
	// If there is file parametered during the programm launch
	else
	{
		if(rawProcessor.open_file(argv[1]) != LIBRAW_SUCCESS)
		{
			std::cout << "Sorry there is an error, while trying to open the file !" << std::endl;
		}
		else
		{
			std::cout << "Image size: " << rawProcessor.imgdata.sizes.width << " x " << rawProcessor.imgdata.sizes.height << std::endl;
		}	
	}

	std::cout << (std::string)rawProcessor.imgdata.idata.make << " - ";
	std::cout << (std::string)rawProcessor.imgdata.idata.model << std::endl;

	rawProcessor.recycle();
}
