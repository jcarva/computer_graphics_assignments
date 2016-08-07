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
		Line().DrawLine("Green", Pixel(0,0),Pixel((IMAGE_WIDTH/4)*3,(IMAGE_HEIGHT/4)*1), green);
		Line().DrawLine("Blue", Pixel(0,0),Pixel(255, 255), blue);
		Line().DrawLine("Red", Pixel(0,0),Pixel((IMAGE_WIDTH/4)*1,(IMAGE_HEIGHT/4)*3), red);

		Line().DrawLine("Blue", Pixel(511,511),Pixel((IMAGE_WIDTH/4)*3,(IMAGE_HEIGHT/4)*1), blue);
		Line().DrawLine("Red", Pixel(511,511),Pixel(256,256), red);
		Line().DrawLine("Gree", Pixel(511,511),Pixel((IMAGE_WIDTH/4)*1,(IMAGE_HEIGHT/4)*3), green);

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

