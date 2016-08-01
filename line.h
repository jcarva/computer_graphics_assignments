#ifndef _LINE_H_
#define _LINE_H_

#include "definitions.h"
#include "pixel.h"

class Line
{
public:
	Line();
	~Line();
	void DrawLine(Pixel initial, Pixel final);
};

Line::Line()
{
	//std::cout << "Line is being created" << std::endl;
}

Line::~Line()
{
	//std::cout << "Line is being deleted" << std::endl;
}

void Line::DrawLine(Pixel initial, Pixel final)
{
	
}

#endif // _LINE_H_

