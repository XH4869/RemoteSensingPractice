#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;
class CPlantIdx
{
public:
	CPlantIdx();
	~CPlantIdx();
public:
	Mat TM3, TM4, NDVI;
	void ReadImg(char *filename1, char *filename2);
	void CountNDVI();
	void GetNDVI();
	void Sub(CPlantIdx plant);
};