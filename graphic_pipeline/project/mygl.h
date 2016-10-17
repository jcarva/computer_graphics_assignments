#ifndef _MYGL_H_
#define _MYGL_H_

#include <cstring>
#include "definitions.h"
#include "pixel.h"
#include "line.h"
#include "triangle.h"

void CleanScreen(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    unsigned int color = r;

    color = color << 8;
    color = color + g;
    color = color << 8;
    color = color + b;
    color = color << 8;
    color = color + a;

    memset(FBptr, 0, IMAGE_WIDTH * IMAGE_HEIGHT * 4);
}

#endif // _MYGL_H_

