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
	void DrawLine(std::string line_name, Pixel initial, Pixel final, int initial_color[4], int final_color[4]);
};

Line::Line()
{
	//std::cout << "Line is being created" << std::endl;
}

Line::~Line()
{
	//std::cout << "Line is being deleted" << std::endl;
}

void Line::DrawLine(std::string line_name, Pixel initial, Pixel final, int initial_color[4], int final_color[4])
{	
	/*
		Printed pixels buffer. Needed to calculate the incremental color to the color interpoloation.
	*/
	std::vector<Pixel> buffer_line;

	/*
		Reference Pixel to draw the line, it will be to puted a lot of time in different coordenates.
	*/
	Pixel reference_pixel = Pixel(0,0);


	/*
		Firsts Coordinates to PutPixel when we use the Bresenham Algorithm's.
	*/
	int x = initial.column;
	int y = initial.row;


	/*
		Respresentation of the reference and complementary axes. They are necessary to generalize the
		Bresenham Algorithm to any octante, so we need change the 'while' stop condition, and do octante
		transformations.
	*/
	int * reference_axis;
	int * complementary_axis;


	/*
		Beyond line coordenates to generalize the Bresenham Algorithm to any octante, so we need change
		the 'while' stop condition.
	*/
	int x_limit;
	int y_limit;


	/*
		Set beyond line coordenates.
	*/
	if (initial.column > final.column) //Set x limit using x0 transformation.
		x_limit = (initial.column - final.column) + initial.column;
	else
		x_limit = final.column; //Base case

	if (initial.row > final.row) //Set y limit using y0 transformation.
		y_limit = (initial.row - final.row) + initial.row;
	else
		y_limit = final.row; //Base case

	/*
		Set deltaX, deltaY. According to the Bresenham Algorithm, these depend of the beyond line coordenates.
	*/
	int deltaX = x_limit - initial.column;
	int deltaY = y_limit - initial.row;


	/*
		Variable that represents the 'while' limit to put pixels.
	*/
	int limit;


	/*
		Set and Change variables to use the Bresenham's Algorithm all octantes using y=x transformation.
	*/
	if(deltaX < deltaY) {
	    int tmp = deltaX;
	    deltaX = deltaY;
	    deltaY = tmp;

	    limit = y_limit;

	    reference_axis = &y;
	    complementary_axis = &x;
	}
	else {

		limit = x_limit;

		reference_axis = &x;
		complementary_axis = &y;
	}


	int d = (2 * deltaY) - deltaX;
	int increase_e = 2 * deltaY;
	int increase_ne = 2 * (deltaY - deltaX);

	reference_pixel.column = x;
	reference_pixel.row = y;

	buffer_line.push_back(reference_pixel);

	while(*reference_axis < limit)
	{
		if (d <= 0)
		{
			d += increase_e;
			(*reference_axis) += 1;
		}
		else
		{
			d += increase_ne;
			(*reference_axis) += 1;
			(*complementary_axis) += 1;
		}	

		reference_pixel.column = x;
		reference_pixel.row = y;


		/*
			Revert transformations.
		*/
	    if(x_limit != final.column)
	        reference_pixel.column = initial.column - (reference_pixel.column - initial.column);
	    
	    if(y_limit != final.row)
	        reference_pixel.row = initial.row - (reference_pixel.row - initial.row);


		buffer_line.push_back(reference_pixel);

	}

	for (int i = 0 ; i < buffer_line.size() ; ++i)
	{
		reference_pixel.PutPixel(buffer_line[i].column,buffer_line[i].row, initial_color);
	}

}

#endif // _LINE_H_