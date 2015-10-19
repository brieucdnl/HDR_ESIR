#ifndef DEF_IMAGE
#define DEF_IMAGE

// Include STL
#include <string>
#include <iostream>
// Include OpenCV
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
// Include LibRaw
#include "libraw/libraw.h"

class Image
{
	public:
		// Constructor
		Image(const char* file);
		// Destructor
		~Image();	
		// Getters
		cv::Mat getImg() const;		
		std::string getNameImage() const;
		std::string getCameraModel() const;
		float getShutterSpeed() const;
		// Functions
		void displayImage() const;
	
	private:
		cv::Mat Img;
		std::string nameImage;
		std::string cameraModel;
		float shutterSpeed;
};

#endif
