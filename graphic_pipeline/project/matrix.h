#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix
{
    private:
        double ** matrix;
        int rows;
        int columns;

    public:
        Matrix();
        Matrix(int num_rows, int num_columns);
        ~Matrix();

        void SetMatrix(vector<double> values);

        vector<int> GetDimensions();

        void SetValue(int row, int column, double value);
        double GetValue(int row, int column);

        void LoadIdentityMatrix();

        void MatrixMultiplication(Matrix& m1, Matrix& m2);
        void DivisionByScalar(Matrix& m, double scalar);

        void Display();
};

Matrix::Matrix()
{
    rows = 3;
    columns =  3;
    matrix = new double * [rows];

    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new double[columns];
    }
}

Matrix::Matrix(int num_rows, int num_columns)
{
    rows = num_rows;
    columns =  num_columns;
    matrix = new double * [rows];

    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new double[columns];
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; ++i)
    {

        delete[] matrix[i];

    }

    delete[] matrix;
}

void Matrix::SetMatrix(vector<double> values)
{

    if (rows * columns != values.size())
    {
        throw overflow_error("The matrix do not support the inserted set size");
    }
    int current_value_index = 0;

    for(int r = 0; r < rows; r++)
    {

        for(int c = 0; c < columns; c++)
        {

            matrix[r][c] = values[current_value_index];
            current_value_index++;

        }

    }
}

vector<int> Matrix::GetDimensions()
{
    vector<int> dimensions{rows, columns};
    return  dimensions;
}

void Matrix::SetValue(int row, int column, double value)
{
    if(rows <= row  || columns <= column)
    {
        throw overflow_error("The position is out of range");
    }
    matrix[row][column] = value;
}

double Matrix::GetValue(int row, int column)
{
    if(rows <= row  || columns <= column)
    {
        throw overflow_error("The position is out of range");
    }
    return matrix[row][column];
}

void Matrix::LoadIdentityMatrix()
{
    if(rows != columns)
    {
        throw overflow_error("Impossible LoadIdentity, this matrix is not a square matrix.");
    }

    for(int r = 0; r < rows; r++)
    {

        for(int c = 0; c < columns; c++)
        {

            if(r == c)
            {
                matrix[c][r] = 1;
            }
            else
            {
                matrix[c][r] = 0;
            }

        }
    }
}

void Matrix::MatrixMultiplication(Matrix& m1, Matrix& m2)
{
    vector<int> m1_dimensions = m1.GetDimensions();
    vector<int> m2_dimensions = m2.GetDimensions();

    if(m1_dimensions[1] != m2_dimensions[0] || rows != m2_dimensions[0] || columns != m2_dimensions[1])
    {
        throw std::overflow_error("There is not compatibility in the dimensions of the matrices.");
    }
    vector<double> result;
    result.resize(rows * columns);

    for(int r = 0; r < rows; r++)
    {

        for(int c = 0; c < columns; c++) {

            result[columns * r + c] = 0.0;

            for(int cr = 0; cr < m1_dimensions[1]; cr++)
            {

                result[columns * r + c] += m1.GetValue(r, cr) * m2.GetValue(cr, c);

            }

        }

    }

    SetMatrix(result);

}

void Matrix::DivisionByScalar(Matrix& m, double scalar)
{
    if(scalar == 0.0)
    {
        throw std::overflow_error("Division by 0 is undefined");
    }

    for(int r = 0; r < rows; r++)
    {

        for(int c = 0; c < columns; c++)
        {

            SetValue(r, c, m.GetValue(r, c)/scalar);

        }

    }
}

void Matrix::Display() {

    for(int r = 0; r < rows; r++)
    {

        for(int c = 0; c < columns; c++)
        {

            clog << " " << matrix[r][c];

        }

        clog << endl;

    }

    clog << endl;
}

#endif // _MATRIX_H_

