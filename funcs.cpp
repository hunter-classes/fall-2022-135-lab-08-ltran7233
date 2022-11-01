#include <iostream>
#include <cmath>
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

void box()
{
	std::string input = "inImage.pgm";
	int img[MAX_H][MAX_W];
	int h, w;
	readImage(input, img, h, w);
	
	int out[MAX_H][MAX_W];
	
	int start_h = h/4;
	int end_h = (h*3)/4;
	int start_w = w/4;
	int end_w = (w*3)/4;
	for(int row = 0; row < h; row++)
	{
		for(int col = 0; col < w; col++)
		{
			if (((row >= start_h) && (row <= end_h)) && ((col >= start_w) && (col <= end_w)))
			{
				out[row][col] = 255;
			}
			else
			{
				out[row][col] = img[row][col];
			}
		}
	}
	
	writeImage("taskC.pgm",out, h, w);
}

void frame()
{
	std::string input = "inImage.pgm";
	int img[MAX_H][MAX_W];
	int h, w;
	readImage(input, img, h, w);
	
	int out[MAX_H][MAX_W];
	
	int start_h = h/4;
	int end_h = (h*3)/4;
	int start_w = w/4;
	int end_w = (w*3)/4;
	for(int row = 0; row < h; row++)
	{
		for(int col = 0; col < w; col++)
		{
			if ((((row == start_h) && ((col >= start_w) && (col <= end_w))) || ((row == end_h) && ((col >= start_w) && (col <= end_w)))) || (((col == start_w) && ((row >= start_h) && (row <= end_h))) || ((col == end_w) && ((row >= start_h) && (row <= end_h)))))
			{
				out[row][col] = 255;
			}
			else
			{
				out[row][col] = img[row][col];
			}
		}
	}
	
	writeImage("taskD.pgm",out, h, w);
}

void scale()
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
			out[row*2][col*2] = img[row][col];
			out[row*2][col*2+1] = img[row][col];
			out[row*2+1][col*2] = img[row][col];
			out[row*2+1][col*2+1] = img[row][col];
		}
	}
	
	writeImage("taskE.pgm",out, h*2, w*2);
}

void pixelate()
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
			double avg = 0.0;
			
			avg += img[row*2][col*2];
			avg += img[row*2][col*2+1];
			avg += img[row*2+1][col*2];
			avg += img[row*2+1][col*2+1];
			avg = (avg/4.0);
			
			out[row*2][col*2] = round(avg);
			out[row*2][col*2+1] = round(avg);
			out[row*2+1][col*2] = round(avg);
			out[row*2+1][col*2+1] = round(avg);
		}
	}
	
	writeImage("taskF.pgm",out, h, w);
}
