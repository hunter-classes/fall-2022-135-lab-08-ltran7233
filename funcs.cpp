#include <iostream>
#include "imageio.h"
#include "funcs.h"

void invert()
{
	std::string input = "inImage.pgm";
	int img[MAX_H][MAX_W];
	int h, w;
	readImage(input, img, h, w);
	
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++)
	{
		for(int col = 0; col < w; col++)
		{
			out[row][col] = 255 - img[row][col];
		}
	}
	
	writeImage("taskA.pgm",out, h, w);
}

void invert_half()
{
	std::string input = "inImage.pgm";
	int img[MAX_H][MAX_W];
	int h, w;
	readImage(input, img, h, w);
	
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++)
	{
		for(int col = 0; col < w; col++)
		{
			if (col >= w/2)
			{
				out[row][col] = 255 - img[row][col];
			}
			else
			{
				out[row][col] = img[row][col];
			}
		}
	}
	
	writeImage("taskB.pgm",out, h, w);
}
