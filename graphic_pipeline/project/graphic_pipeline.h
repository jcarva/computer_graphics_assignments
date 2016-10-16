#ifndef _GRAPHIC_PIPELINE_H_
#define _GRAPHIC_PIPELINE_H_

#include <cmath>
#include "matrix.h"

typedef Matrix Vector;

Matrix model(4, 4);
Matrix view(4, 4);
Matrix projection(4, 4);
Matrix viewport(4, 4);

double d;

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

double CrossProduct(Vector * v1, Vector * v2, Vector * product)
{
    (*product).SetValue(0, 0, (*v1).GetValue(1,0) * (*v2).GetValue(2, 0) - (*v2).GetValue(1, 0) * (*v1).GetValue(2,0));
    (*product).SetValue(1, 0, (*v1).GetValue(2,0) * (*v2).GetValue(0, 0) - (*v2).GetValue(2, 0) * (*v1).GetValue(0,0));
    (*product).SetValue(2, 0, (*v1).GetValue(0,0) * (*v2).GetValue(1, 0) - (*v2).GetValue(0, 0) * (*v1).GetValue(1,0));
}

double VectorNorm(Vector * vector)
{
    return sqrt (
            (*vector).GetValue(0, 0) * (*vector).GetValue(0, 0) +
            (*vector).GetValue(1, 0) * (*vector).GetValue(1, 0) +
            (*vector).GetValue(2, 0) * (*vector).GetValue(2, 0)
    );
}

void LookAt(vector<double> cam_position, vector<double> look_at, vector<double> up)
{
    Vector x_cam(3, 1);
    Vector y_cam(3, 1);
    Vector z_cam(3, 1);

    Matrix Bt(4, 4);
    Matrix T(4, 4);

    Vector Looked(3, 1);
    Vector Up(3, 1);

    Looked.SetMatrix({cam_position[0] - look_at[0], cam_position[1] - look_at[1], cam_position[2] - look_at[2]});
    Up.SetMatrix(up);

    z_cam.DivisionByScalar(Looked, VectorNorm(&Looked));

    CrossProduct(&Up, &z_cam, &Looked);

    x_cam.DivisionByScalar(Looked, VectorNorm(&Looked));

    CrossProduct(&z_cam, &x_cam, &Looked);

    y_cam.DivisionByScalar(Looked, VectorNorm(&Looked));

    vector<double> Bt_values {
            x_cam.GetValue(0, 0), x_cam.GetValue(1, 0), x_cam.GetValue(2, 0), 0,
            y_cam.GetValue(0, 0), y_cam.GetValue(1, 0), y_cam.GetValue(2, 0), 0,
            z_cam.GetValue(0, 0), z_cam.GetValue(1, 0), z_cam.GetValue(2, 0), 0,
            0,                    0,                    0,            1
    };

    Bt.SetMatrix(Bt_values);

    T.LoadIdentityMatrix();
    T.SetValue(0, 3, -cam_position[0]);
    T.SetValue(1, 3, -cam_position[1]);
    T.SetValue(2, 3, -cam_position[2]);

    view.LoadIdentityMatrix();

    view.MatrixMultiplication(Bt, T);

    view.Display(); // Just to log
}

void ViewPlaneDistance(double distance)
{
    d = distance;
    projection.SetValue(2, 3, d);
    projection.SetValue(3, 2, (-1) / d);
    projection.SetValue(3, 3, 0);

    projection.Display(); // Just to log
}

void ViewPort(int initial_x, int initial_y, int width, int height)
{
    Matrix S1(4, 4);
    Matrix S2(4, 4);
    Matrix T(4, 4);

    S1.LoadIdentityMatrix();
    S2.LoadIdentityMatrix();
    T.LoadIdentityMatrix();

    S1.SetValue(1, 1, -1);

    S2.SetValue(0, 0, (width - 1) / 2.0f);
    S2.SetValue(1, 1, (height - 1) / 2.0f);

    T.SetValue(0, 3, 1);
    T.SetValue(1, 3, 1);

    viewport.LoadIdentityMatrix();

    viewport.MatrixMultiplication(T, S1);
    viewport.MatrixMultiplication(S2, viewport);

    viewport.Display(); // Just to log
}

void PipelineLoader()
{
    model.LoadIdentityMatrix();
    view.LoadIdentityMatrix();
    projection.LoadIdentityMatrix();
    viewport.LoadIdentityMatrix();
    ViewPlaneDistance(1);
}

#endif // _GRAPHIC_PIPELINE_H_