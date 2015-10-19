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
	std::vector<Image> vecImg;
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

std::vector<Image> HDR::getVecImg()
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
void HDR::add(const Image Img)
{
	vecImg.push_back(Img);
}

/********** METHODS  **********/
