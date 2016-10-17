#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "line.h"

class Triangle
{
public:
	Triangle();
	~Triangle();
	void DrawTriangle(Pixel vertex1, Pixel vertex2, Pixel vertex3, int color_vertex1[4], int color_vertex2[4], int color_vertex3[4]);
	void DrawFilledTriangle(Pixel vertex1, Pixel vertex2, Pixel vertex3, int color_vertex1[4], int color_vertex2[4], int color_vertex3[4]);
	void FilledTriangle(Pixel vertex1, Pixel vertex2, Pixel vertex3, int color_vertex1[4], int color_vertex2[4], int color_vertex3[4]);
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

void Triangle::DrawFilledTriangle(Pixel vertex1, Pixel vertex2, Pixel vertex3, int color_vertex1[4], int color_vertex2[4], int color_vertex3[4])
{
	Line().DrawLine("", vertex1, vertex2, color_vertex1, color_vertex2);

	Line reference_line = Line();
	reference_line.DrawLine("", vertex2, vertex3, color_vertex2, color_vertex3);

	double dColor[4] = {
		(double) (color_vertex3[0] - color_vertex2[0])/(reference_line.buffer_line.size()),
		(double) (color_vertex3[1] - color_vertex2[1])/(reference_line.buffer_line.size()),
		(double) (color_vertex3[2] - color_vertex2[2])/(reference_line.buffer_line.size()),
		(double) (color_vertex3[3] - color_vertex2[3])/(reference_line.buffer_line.size())
	};

	//std::clog << "Incremental color: " << "R[" << dColor[0] << "], G[" << dColor[1] << "], B[" << dColor[2] <<"]." << std::endl;

	//std::clog << "reference_line size: " << reference_line.buffer_line.size() << std::endl;

	double reference_color[4] = {
		(double) color_vertex2[0],
		(double) color_vertex2[1],
		(double) color_vertex2[2],
		(double) color_vertex2[3]
	};

	int final_color[4] = {
		(int) color_vertex2[0],
		(int) color_vertex2[1],
		(int) color_vertex2[2],
		(int) color_vertex2[3]
	};

	//std::clog << "Resulting color: " << "R[" << reference_color[0] << "], G[" << reference_color[1] << "], B[" << reference_color[2] <<"]." << std::endl;

	for (int i = 0; i < reference_line.buffer_line.size() ; ++i)
	{
		Line().DrawLine("", vertex1, reference_line.buffer_line[i], color_vertex1, final_color);

		reference_color[0] += dColor[0];
		reference_color[1] += dColor[1];
		reference_color[2] += dColor[2];
		reference_color[3] += dColor[3];

		final_color[0] = (int) reference_color[0];
		final_color[1] = (int) reference_color[1];
		final_color[2] = (int) reference_color[2];
		final_color[3] = (int) reference_color[3];

		//std::clog << "Resulting color: " << "R[" << reference_color[0] << "], G[" << reference_color[1] << "], B[" << reference_color[2] <<"]." << std::endl;
		//std::clog << "Final color: " << "R[" << final_color[0] << "], G[" << final_color[1] << "], B[" << final_color[2] <<"]." << std::endl;

	}
}

void Triangle::FilledTriangle(Pixel vertex1, Pixel vertex2, Pixel vertex3, int color_vertex1[4], int color_vertex2[4], int color_vertex3[4])
{
	DrawFilledTriangle(vertex1, vertex2, vertex3, color_vertex1, color_vertex2, color_vertex3);
	DrawFilledTriangle(vertex3, vertex1, vertex2, color_vertex3, color_vertex1, color_vertex2);
	DrawFilledTriangle(vertex2, vertex3, vertex1, color_vertex2, color_vertex3, color_vertex1);
}

#endif // _TRIANGLE_H_