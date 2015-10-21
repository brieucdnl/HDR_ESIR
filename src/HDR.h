#ifndef DEF_HDR
#define DEF_HDR

// Include STL
#include <string>
#include <iostream>
#include <vector>
// Include OpenCV
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
// Include other class
#include "Image.h"

class HDR
{
	public:
		// Constructor
		HDR();
		// Destructor
		~HDR();
		// Getters
		std::vector<Image *> getVecImg();
		// Setters
		void add(Image *Img);
		// Functions

	private:
		std::vector<Image *> vecImg;
};

#endif
