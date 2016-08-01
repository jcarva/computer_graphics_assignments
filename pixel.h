#ifndef _PIXEL_H_
#define _PIXEL_H_

#include "definitions.h"

class Pixel
{
public:
	int offset; //absolute position each pixel

	Pixel();
	~Pixel();
	int Offset(int column, int row);
	void PutPixel(int x, int y, int RGBA[4]);	
};

Pixel::Pixel()
{
	//std::cout << "Pixel is being created" << std::endl;
}

Pixel::~Pixel()
{
	//std::cout << "Pixel is being deleted" << std::endl;
}

int Pixel::Offset(int column, int row)
{
	return column * 4 + row * IMAGE_WIDTH * 4;
}


void Pixel::PutPixel(int x, int y, int RGBA[4])
{
	offset = Offset(x, y);

	for (int i = 0; i < 4; i++)
	{
		FBptr[offset + i] = RGBA[i];
	}

}

#endif // _PIXEL_H_

