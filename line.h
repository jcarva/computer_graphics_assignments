#ifndef _LINE_H_
#define _LINE_H_

#include <iostream>
#include <string>
#include "pixel.h"
#include <vector>

class Line
{
public:
	Line();
	~Line();
	void DrawLine(std::string line_name, Pixel initial, Pixel final, int color[4]);
};

Line::Line()
{
	//std::cout << "Line is being created" << std::endl;
}

Line::~Line()
{
	//std::cout << "Line is being deleted" << std::endl;
}

void Line::DrawLine(std::string line_name, Pixel initial, Pixel final, int color[4])
{	

	/*
		Pixels vector backup to do octante transformations.
	*/
	std::vector<Pixel> buffer_line;


	/*
		Reference Pixel to draw the line, it will be
		to puted a lot of time in different coordenates.
	*/
	Pixel line_reference_pixel = Pixel(0,0);


	/*
		Respresentation of the reference and
		complementary axes. They are necessary to
		generalize the	Bresenham Algorithm to any
		octante, so we need	change the 'while' stop
		condition, and do octante transformations.
	*/
	int reference_axis;
	int complementary_axis;

	/*
		Firsts Coordinates to PutPixel if we use
		the Bresenham Algorithm's base case.
	*/
	int x = initial.column;
	int y = initial.row;


	/*
		Beyonds line coordenates to generalize the
		Bresenham Algorithm to any octante, so we need
		change the 'while' stop condition.
	*/
	int x_limit;
	int y_limit;

	int deltaX = final.column - initial.column;
	int deltaY = final.row - initial.row;
	int d = (2 * deltaY) - deltaX;
	int increase_e = 2 * deltaY;
	int increase_ne = 2 * (deltaY - deltaX);

	std::clog << "###################" ;
	std::clog << std::endl << "LINE: "<< line_name << std::endl;
	std::clog << "dx: " << deltaX << std::endl << "dy: " << deltaY << std::endl;
	std::clog << "increase_e: " << increase_e << std::endl << "increase_ne: " << increase_ne << std::endl << std::endl;

	std::clog << "d: " << d << ", x: " << x  << ", y: " << y << std::endl;
	line_reference_pixel.PutPixel(x,y,color);

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
		std::clog << "d: " << d << ", x: " << x  << ", y: " << y << std::endl;
		line_reference_pixel.PutPixel(x,y,color);
	}

}

#endif // _LINE_H_