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
		Image(const char* file);
		cv::Mat getImg() const;
		void displayImage() const;
		~Image();	
	
	private:
		cv::Mat Img;
		std::string cameraModel;
		int shutterTime;
};

#endif
