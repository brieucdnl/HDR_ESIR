#include "utils.h"

/*
 * showCurve()
 *
 * Display a graphic image of the curve
 *
 * Input: std::vector<double> curve
 * Output: None
 */
void showCurve(std::vector<double> curve)
{
	cv::Mat graph(500, 500, CV_8UC3);
	std::vector<cv::Point> listPoint;
	for(int i = 0; i < curve.size(); i++)
	{
		cv::Point p(i, curve[i]);
		listPoint.push_back(p);
	}
	for(int i = 1; i < listPoint.size(); i++)
	{
		std::cout << listPoint.size() << std::endl;
		cv::line(graph, listPoint[i-1], listPoint[i], CV_RGB(255, 0, 0));
		cv::imshow("Non linear function from original Exposure", graph);
		cv::waitKey(0);
	}
}

/*
 * createCurvesList()
 *
 * Create a list of curves to process
 *
 * Intput: - HDR &imgList
 *         - std::vector<std::pair<int,int> > &indexPoints
 *         - std::vector<std::vector<double> > &curvesList
 * Output: None
 */
void createCurvesList(HDR &imgList, std::vector<std::pair<int,int> > &indexPoints, std::vector<std::vector<double> > &curvesList)
{
	int nbPoints = indexPoints.size();
	double z;
	
	for(int i = 0; i < imgList.getSize(); i++)
	{
		std::vector<double> v;
		curvesList.push_back(v);
		for(int k = 0; k < nbPoints; k++)
		{
			z = imgList.getVecImg()[i]->getImg().at<int>(indexPoints[k].first, indexPoints[k+1].second);
			curvesList[i].push_back(z);
		}
	}
}

/*
 * calcDistCurves()
 *
 * Calculate distance between curves
 *
 * Intput: - std::vector<double> &c1
 *         - std::vector<double> &c2
 *				 - int nbPoints
 * Output: double
 */

double calcDistCurves(std::vector<double> &c1, std::vector<double> &c2, int nbPoints)
{
	double h = 0;

	if(nbPoints == 0)
	{
		std::cout << "There's no points to be study" << std::endl;
		return 0;
	}
	else
	{
		for(int k = 0; k < nbPoints; k++)
		{
			if(c1[k] >= c2[0])
			{
				for(int i1 = k; i1 < nbPoints; i1++)
				{
					for(int i2 = 0; i2 < nbPoints-k; i2++)
					{
						std::cout << "i1: " << i1 << " - I2: " << i2 << std::endl;
						h += abs(i2-i1-1);
					}
				}
			}
			else if(k == nbPoints - 1)
			{
				std::cout << "Curves are not similar enough" << std::endl;
			}
		}
		h /= nbPoints;
		std::cout << "Distance h: " << std::endl;
	}
}

/*
 * computeCurves()
 *
 * Compute the different curves in a single-one
 *
 * Input: - HDR &imgList
 *        - std::vector<std::pair<int, int>> pointsList
 *
 * Output: none
 */
void computeCurves(HDR &imgList, std::vector<std::pair<int,int> > &pointsList)
{
	int nbPoints = pointsList.size();	

	std::vector<std::vector<double> > curvesList;
	//std::vector<double> v0(imgList.getSize());

	createCurvesList(imgList, pointsList, curvesList);
	for(int i = 0; i < imgList.getSize(); i++)
	{
		showCurve(curvesList[i]);
	}
	
	std::vector<std::pair<double,int> > g;
	
	for(int ci=1; ci < curvesList.size(); ci++)
	{
		double h = calcDistCurves(curvesList[0], curvesList[ci], nbPoints);
		for(int pt = 0; pt < nbPoints; pt++)
		{
			std::pair<int,double> x_fx(pt+h, curvesList[ci][pt]);
			g.push_back(x_fx);
		}
	}
}
