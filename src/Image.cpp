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
 * ~IMAGE()
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
 * GETIMG()
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
 * GETNAMEIMAGE()
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
 * GETCAMERAMODEL()
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
 * GETSHUTTERSPEED()
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
 * DISPLAYIMAGE()
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
