#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include "main.h"
#include "objLoader.h"
#include "graphic_pipeline.h"

using namespace std;

objLoader* objData;
double angle = 0.0f;

void MyGlDraw(void)
{

	PipelineLoader();

	vector<double> cam_position{0.0f, 0.0f, 4.0f}; //camera position
	vector<double> look_at{0.0f, 0.0f, 0.0f}; //point looked by the camera
	vector<double> up{0.0f, 1.0f, 0.0f}; //up vector

	LookAt(cam_position, look_at, up);

	ViewPort(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT);

	ViewPlaneDistance(1.9);

	Rotation(0.0f, 1.0f, 0.0f, angle);

	//angle += 0.009f;
    angle += 0.000f;

	CleanScreen(0, 0, 0, 255);

	vector<Pixel> pixel;
	pixel.resize(3);

	for(int f = 0; f < objData->faceCount; f++)
	{
		obj_face* obj = objData->faceList[f];

		for(int i = 0; i < 3; i++)
		{
			Pixel p = Pipeline(
					objData->vertexList[obj->vertex_index[i]]->e[0],
					objData->vertexList[obj->vertex_index[i]]->e[1],
					objData->vertexList[obj->vertex_index[i]]->e[2]
			);

			pixel[i].column = p.column;
			pixel[i].row = p.row;
		}


//		int red[4] = { 0 + (rand() % (int)(255 - 0 + 1)), 0 + (rand() % (int)(255 - 0 + 1)), 0 + (rand() % (int)(255 - 0 + 1)), 255 };
//		int green[4] = { 0 + (rand() % (int)(255 - 0 + 1)), 0 + (rand() % (int)(255 - 0 + 1)), 0 + (rand() % (int)(255 - 0 + 1)), 255 };
//		int blue[4] = { 0 + (rand() % (int)(255 - 0 + 1)), 0 + (rand() % (int)(255 - 0 + 1)), 0 + (rand() % (int)(255 - 0 + 1)), 255 };

		int red[4] = { 255, 0, 0, 255 };
		int green[4] = { 0, 255, 0, 255 };
		int blue[4] = { 0, 0, 255, 255 };
        int white[4] = { 255, 255, 255, 255 };

//		int red[4] = { 255, 255, 255, 255 };
//		int green[4] = { 255, 255, 255, 255 };
//		int blue[4] = { 255, 255, 255, 255 };

		//Triangle().DrawTriangle(pixel[0], pixel[1], pixel[2], white, white, white);
        Triangle().DrawTriangle(pixel[0], pixel[1], pixel[2], red, green, blue);
	}
}

//********************************************************************************

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		clog << "\nType the OBJ file's name.\nExiting...\n" << endl;
		return 1;
	}

	objData = new objLoader();
	objData->load(argv[1]);

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