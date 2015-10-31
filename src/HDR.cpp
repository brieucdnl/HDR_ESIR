#include "HDR.h"

/********** CONSTRUCTOR **********/

/*
 * HDR()
 *
 * Initializing HDR
 *
 * Input: None
 * Output: None
 */
HDR::HDR()
{
	std::vector<Image *> vecImg;
}

/********** DESTRUCTOR **********/

/*
 * ~HDR()
 *
 * Free space used by the HDR
 *
 * Input: None
 * Output: None
 */
HDR::~HDR()
{
	for(int i = 0; i < vecImg.size(); i++)
	{
		delete vecImg[i];
	}
}

/********** GETTERS AND SETTERS **********/

/*
 * getVecImg()
 *
 * Getter vecImg
 *
 * Input: 
 * Output: 
 */

std::vector<Image *> HDR::getVecImg()
{
	return vecImg;
}

/*
 * add()
 *
 * Method adding an image to vecImg
 *
 * Input: Image *Img
 * Output: None
 */
void HDR::add(Image *Img)
{
	vecImg.push_back(Img);
}

/********** METHODS  **********/

/*
 * getSize()
 *
 * Method returning the number of images in HDR
 *
 * Input: None
 * Output: int
 */
int HDR::getSize()
{
	vecImg.size();
}
