// Include STL
#include <iostream>
#include <utility>

// Include QT
#include <QApplication>

// Projects include
#include "HDR.h"
#include "Image.h"
#include "utils.h"

int main(int argc, char* argv[])
{
	Image *I;
	HDR *processor;
	QApplication app(argc, argv);
	
	// Creating the HDR_Processor
	processor = new HDR();
	
	// Init PointsList
	std::vector<std::pair<int,int> > pointsList;
	std::pair<int, int> p1(70, 70);
	std::pair<int, int> p2(140,140);
	std::pair<int, int> p3(210,210);
	pointsList.push_back(p1);
	pointsList.push_back(p2);
	pointsList.push_back(p3);
	
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
	
	// Compute Curves
	//testCurve();
	//std::cout << I->getImg() << std::endl;

	double minVal, maxVal;
	I->getZExtremum(&minVal, &maxVal, 0);
	//computeCurves(*processor, pointsList);

	delete processor; 
}
