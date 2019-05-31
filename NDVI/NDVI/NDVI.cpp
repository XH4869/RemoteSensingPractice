// NDVI.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include "PlantIdx.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

int main()
{
	CPlantIdx plant, _plant;
	plant.ReadImg("tm3.bmp", "tm4.bmp");
	plant.CountNDVI();
	_plant.ReadImg("09tm.bmp", "tm4.bmp");
	_plant.GetNDVI();
	plant.Sub(_plant);
    return 0;
}