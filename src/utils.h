#ifndef DEF_UTILS
#define DEF_UTILS

// INCLUDE STL
#include <string>
#include <iostream>
// INCLUDE OpenCV
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
// #include "opencv2/opencv.hpp"
// INCLUDE PROJECT
#include "HDR.h"

void showCurve(std::vector<double> curve);
void createCurvesList(HDR &imgList, std::vector<int> &indexPoints, std::vector<std::vector<double> > &curvesList);
double calcDistCurves(std::vector<double> &c1, std::vector<double> &c2, int nbPoints);
void computeCurves(HDR &imgList, std::vector<int> pointsList);

#endif
