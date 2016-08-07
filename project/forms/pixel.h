#ifndef _PIXEL_H_
#define _PIXEL_H_

#include "definitions.h"

class Pixel
{
public:
	int column;
	int row;
	int offset; //absolute position each pixel when it will be renderized. 

	Pixel(int x, int y);
	~Pixel();
	int Offset(int column, int row);
	void PutPixel(int x, int y, double RGBA[4]);	
};

Pixel::Pixel(int x, int y)
{
	column = x;
	row = y;
	//std::cout << "Pixel is being created" << std::endl;
}

Pixel::~Pixel()
{
	//std::cout << "Pixel is being deleted" << std::endl;
}

int Pixel::Offset(int column, int row)
{
	return (column  + row * IMAGE_WIDTH) * 4;
}


void Pixel::PutPixel(int x, int y, double RGBA[4])
{
	if ((x >= 0 && x < IMAGE_WIDTH) && (y >= 0 && y < IMAGE_HEIGHT))
	{
		offset = Offset(x, y);

		for (int i = 0; i < 4; i++)
		{
			FBptr[offset + i] = (int)RGBA[i];
		}
	}
	else
	{
		std::clog << "Invalid PutPixel Position : [ x:" << x << " , y:" << y << " ]" << std::endl;
	}
}

#endif // _PIXEL_H_

