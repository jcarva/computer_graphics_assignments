#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	int foo [4] = { 0, 120, 120, 255 };
	Pixel j = Pixel();

	for (int i = 0; i < 512; i++)
	{
		int foo [4] = { 0+i/2, 0, 255-i/2, 255 };
		j.PutPixel(i,i,foo);
		j.PutPixel(i,512-i,foo);
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

