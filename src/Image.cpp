#include "Image.h"

/********** CONSTRUCTOR **********/

/*
 * Image()
 *
 * Initializing Image
 *
 * Input: char* file (filepath)
 * Output: None
 */
Image::Image(const char* file)
{
	LibRaw rawProcessor;
	libraw_processed_image_t *tmpImg;

	if(rawProcessor.open_file(file) != LIBRAW_SUCCESS)
	{
		// !!! Exception to handle !!!
	}
	else
	{
				
		rawProcessor.unpack();
		// !!! Exception concerning unpack return to handle !!!	

		rawProcessor.imgdata.params.output_bps = 16;
		
		//rawProcessor.raw2image();

		int check = rawProcessor.dcraw_process();
		tmpImg = rawProcessor.dcraw_make_mem_image(&check);
			
		// Init image
		Img = cv::Mat(tmpImg->height, tmpImg->width, CV_16UC3, tmpImg->data);
		
		for(int i = 0; i < tmpImg->height; i++)
		{
			for(int j = 0; j < tmpImg->width; j++)
			{
				if(Img.at<cv::Vec3w>(i,j)[0] < 0)
				{
					std::cout << Img.at<cv::Vec3w>(i,j)[0] << " Point : [" << j << "," << i << "]" << std::endl;
				}
			}
		}

		// Converting RGB to BGR (for OpenCV)
		cv::cvtColor(Img, this->getImg(), CV_RGB2BGR);

		// Init datas
		nameImage = file;
		cameraModel = (std::string) rawProcessor.imgdata.idata.make + " - " + rawProcessor.imgdata.idata.model;
		shutterSpeed = rawProcessor.imgdata.other.shutter;
	}

	// Free rawProcessor
	rawProcessor.recycle();
}

/********** DESTRUCTOR **********/

/*
 * ~Image()
 *
 * Free space used by the Image
 *
 * Input: None
 * Output: None
 */
Image::~Image()
{

}

/********** GETTERS AND SETTERS **********/

/*
 * getImg()
 *
 * Getter Img
 *
 * Input: None
 * Output: cv::Mat Img
 */
cv::Mat Image::getImg() const
{
	return Img;
}

/*
 * getNameImage()
 *
 * Getter nameImage
 *
 * Input: None
 * Output: std::string nameImage
 */
std::string Image::getNameImage() const
{
	return nameImage;
}

/*
 * getCameraModel()
 *
 * Getter cameraModel
 *
 * Input: None
 * Output: std::string cameraModel
 */
std::string Image::getCameraModel() const
{
	return cameraModel;
}

/*
 * getShutterSpeed()
 *
 * Getter shutterSpeed
 *
 * Input: None
 * Output: float shutterSpeed
 */
float Image::getShutterSpeed() const
{
	return shutterSpeed;
}

/********** METHODS **********/

/*
 * displayImage()
 *
 * Method displaying the image
 *
 * Input: None
 * Output: None
 */
void Image::displayImage() const
{
	cv::namedWindow(this->getNameImage(), cv::WINDOW_NORMAL);
	cv::imshow(this->getNameImage(), this->getImg());
	cv::waitKey(0);
}

/*
 * getZExtremum()
 *
 * Method returning image Zmin and Zmax
 *
 * Input: double* minVal, double* maxVal
 * Output: None
 */
void Image::getZExtremum(double *minVal, double *maxVal, int channel) 
{
	cv::Size s = this->getImg().size();
	cv::Mat imgChannel(s.height, s.width, CV_16UC1);
	cv::Point p1, p2;	
	int fromTo[] = {channel, 0};
	cv::mixChannels(&Img, 1, &imgChannel, 1, fromTo, 1);
	cv::minMaxLoc(imgChannel, minVal, maxVal, &p1, &p2);
	std::cout << "Point 1 " << p1 << std::endl;
	std::cout << "Point 2 " << p2 << std::endl;
	std::cout << "Zmin : " << *minVal << " - Zmax : " << *maxVal << std::endl; 
}
