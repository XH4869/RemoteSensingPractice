#include "stdafx.h"
#include "PlantIdx.h"
typedef unsigned char uchar;
CPlantIdx::CPlantIdx()
{
}


CPlantIdx::~CPlantIdx()
{
}


void CPlantIdx::ReadImg(char *filename1, char* filename2)
{
	TM3 = imread(filename1, 0);
	TM4 = imread(filename2, 0);
	NDVI.create(TM3.rows, TM3.cols, CV_8UC1);
}


void CPlantIdx::CountNDVI()
{
	int den, num;
	for (int i = 0; i < TM3.rows; i++)
	{
		for (int j = 0; j < TM3.cols; j++)
		{
			num = (int)(TM4.at<uchar>(i, j)) - (int)(TM3.at<uchar>(i, j));
			num = (num > 0 ? num : 0);
			den = (int)(TM4.at<uchar>(i, j)) + (int)(TM3.at<uchar>(i, j));
			NDVI.at<uchar>(i, j) = (int)(((float)(num) / (float)(den + 0.001)) * 255);
		}
	}
	imwrite("NDVI.bmp", NDVI);
}


void CPlantIdx::Sub(CPlantIdx plant)
{
	Mat sub;
	sub.create(NDVI.rows, NDVI.cols, CV_8UC1);
	int diff;
	for (int i = 0; i < NDVI.rows; i++)
	{
		for (int j = 0; j < NDVI.cols; j++)
		{
			diff = plant.NDVI.at<uchar>(i, j) - NDVI.at<uchar>(i, j);
			if (diff < 0)
				sub.at<uchar>(i, j) = 0;
			else if (diff == 0)
				sub.at<uchar>(i, j) = 128;
			else
				sub.at<uchar>(i, j) = 255;
		}
	}
	imwrite("sub.bmp", sub);
}


void CPlantIdx::GetNDVI()
{
	int den, num;
	for (int i = 0; i < TM3.rows; i++)
	{
		for (int j = 0; j < TM3.cols; j++)
		{
			num = (int)(TM4.at<uchar>(i, j)) - (int)(TM3.at<uchar>(i, j));
			num = (num > 0 ? num : 0);
			den = (int)(TM4.at<uchar>(i, j)) + (int)(TM3.at<uchar>(i, j));
			NDVI.at<uchar>(i, j) = (int)(((float)(num) / (float)(den + 0.001)) * 255);
		}
	}
}