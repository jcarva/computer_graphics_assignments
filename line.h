#ifndef _LINE_H_
#define _LINE_H_

#include "pixel.h"

class Line
{
public:
	Line();
	~Line();
	void DrawLine(Pixel initial, Pixel final, int color[4]);
};

Line::Line()
{
	//std::cout << "Line is being created" << std::endl;
}

Line::~Line()
{
	//std::cout << "Line is being deleted" << std::endl;
}

void Line::DrawLine(Pixel initial, Pixel final, int color[4])
{	
	Pixel reference_pixel = Pixel(0,0);

	int deltaX = final.column - initial.column;
	int deltaY = final.row - initial.row;
	int d = (2 * deltaY) - deltaX;
	int increase_e = 2 * deltaY;
	int increase_ne = 2 * (deltaY - deltaX);
	int x = initial.column;
	int y = initial.row;

	reference_pixel.PutPixel(x,y,color);

	while(x < final.column) {
		if (d <= 0)
		{
			d += increase_e;
			x++;
		}
		else
		{
			d += increase_ne;
			x++;
			y++;
		}
		reference_pixel.PutPixel(x,y,color);
	}

}

#endif // _LINE_H_