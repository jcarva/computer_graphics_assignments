#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "line.h"

class Triangle
{
public:
	Triangle();
	~Triangle();
	void DrawTriangle(Pixel vertex1, Pixel vertex2, Pixel vertex3, int color_vertex1[4], int color_vertex2[4], int color_vertex3[4]);
};

Triangle::Triangle()
{
	//std::cout << "Triangle is being created" << std::endl;
}

Triangle::~Triangle()
{
	//std::cout << "Line is being deleted" << std::endl;
}

void Triangle::DrawTriangle(Pixel vertex1, Pixel vertex2, Pixel vertex3, int color_vertex1[4], int color_vertex2[4], int color_vertex3[4])
{
	Line().DrawLine("", vertex1, vertex2, color_vertex1, color_vertex2);
	Line().DrawLine("", vertex2, vertex3, color_vertex2, color_vertex3);
	Line().DrawLine("", vertex3, vertex1, color_vertex3, color_vertex1);
}

#endif // _TRIANGLE_H_