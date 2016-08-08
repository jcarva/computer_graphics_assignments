#include "main.h"
bool flag = true;
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	if (flag)
	{

		int red[4] = { 255, 0, 0, 255 };
		int green[4] = { 0, 255, 0, 255 };
		int blue[4] = { 0, 0, 255, 255 };
		int yellow[4] = { 255, 255, 0, 255 };

		Triangle().FilledTriangle(Pixel(456,50), Pixel((IMAGE_WIDTH/4)*0.2,300), Pixel((IMAGE_WIDTH/4)*2.7,470), red, green, blue);
	flag = false;
	}
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

