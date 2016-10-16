#ifndef _GRAPHIC_PIPELINE_H_
#define _GRAPHIC_PIPELINE_H_

#include <cmath>
#include "matrix.h"
using namespace std;

typedef Matrix Vector;

Matrix model(4, 4);
Matrix view(4, 4);
Matrix projection(4, 4);
Matrix viewport(4, 4);

double d;

void ViewPlaneDistance(double distance)
{
    d = distance;
    projection.SetValue(2, 3, d);
    projection.SetValue(3, 2, (-1) / d);
    projection.SetValue(3, 3, 0);

    projection.Display(); // Just to log
}

void PipelineLoader()
{
    model.LoadIdentityMatrix();
    view.LoadIdentityMatrix();
    projection.LoadIdentityMatrix();
    viewport.LoadIdentityMatrix();
    ViewPlaneDistance(1);
}

void Scale(double x_scale_factor, double y_scale_factor, double z_scale_factor)
{
    Matrix scale_matrix(4, 4);

    scale_matrix.LoadIdentityMatrix();

    scale_matrix.SetValue(0, 0, x_scale_factor);
    scale_matrix.SetValue(1, 1, y_scale_factor);
    scale_matrix.SetValue(2, 2, z_scale_factor);

    model.MatrixMultiplication(model, scale_matrix);

    model.Display(); // Just to log

}

void Translation(double x_displacement, double y_displacement, double z_displacement)
{
    Matrix translation_matrix(4, 4);

    translation_matrix.LoadIdentityMatrix();

    translation_matrix.SetValue(0, 3, x_displacement);
    translation_matrix.SetValue(1, 3, y_displacement);
    translation_matrix.SetValue(2, 3, z_displacement);

    model.MatrixMultiplication(model, translation_matrix);

    model.Display(); // Just to log

}

void Rotation(double x_axis, double y_axis, double z_axis, double angle)
{
    Matrix rotation_matrix(4, 4);

    rotation_matrix.LoadIdentityMatrix();

    if(x_axis > 0.0)
    {
        rotation_matrix.SetValue(1, 1, cos(angle));
        rotation_matrix.SetValue(1, 2, -sin(angle));
        rotation_matrix.SetValue(2, 1, sin(angle));
        rotation_matrix.SetValue(2, 2, cos(angle));
    }

    if(y_axis > 0.0)
    {
        rotation_matrix.SetValue(0, 0, cos(angle));
        rotation_matrix.SetValue(0, 2, sin(angle));
        rotation_matrix.SetValue(2, 0, -sin(angle));
        rotation_matrix.SetValue(2, 2, cos(angle));
    }

    if(z_axis > 0.0)
    {
        rotation_matrix.SetValue(0, 0, cos(angle));
        rotation_matrix.SetValue(0, 1, -sin(angle));
        rotation_matrix.SetValue(1, 0, sin(angle));
        rotation_matrix.SetValue(1, 1, cos(angle));
    }

    model.MatrixMultiplication(model, rotation_matrix);

    model.Display(); // Just to log
}

double VectorNorm(Vector * vector)
{
    return sqrt (
            (*vector).GetValue(0, 0) * (*vector).GetValue(0, 0) +
            (*vector).GetValue(1, 0) * (*vector).GetValue(1, 0) +
            (*vector).GetValue(2, 0) * (*vector).GetValue(2, 0)
    );
}

#endif // _GRAPHIC_PIPELINE_H_