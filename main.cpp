#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	int red[4] = { 255, 0, 0, 255 };
	int blue[4] = { 0, 0, 255, 255 };
	Line().DrawLine(Pixel(100,100),Pixel(411,411), red);
	Line().DrawLine(Pixel(100,300),Pixel(411,411), blue);
	
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

