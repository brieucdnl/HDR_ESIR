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
		
		//rawProcessor.imgdata.params.no_interpolation = 1;
		//rawProcessor.imgdata.params.no_auto_scale = 1;
		//rawProcessor.imgdata.params.no_auto_bright = 1;
		rawProcessor.imgdata.params.output_bps = 16;
		
		//rawProcessor.raw2image();

		int check = rawProcessor.dcraw_process();
		tmpImg = rawProcessor.dcraw_make_mem_image(&check);
	
		// Init image
		Img = cv::Mat(rawProcessor.imgdata.sizes.width, rawProcessor.imgdata.sizes.height, CV_16UC3, tmpImg->data);

		// Init datas
		cameraModel = (std::string) rawProcessor.imgdata.idata.make + "-" + rawProcessor.imgdata.idata.model;
		shutterTime = rawProcessor.imgdata.other.shutter;
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
	cv::Mat tmpImg;
	cv::cvtColor(Img, tmpImg, CV_RGB2BGR);

	cv::namedWindow("Image", cv::WINDOW_NORMAL);
	cv::imshow("Image", tmpImg);
	cv::waitKey(0);
}
