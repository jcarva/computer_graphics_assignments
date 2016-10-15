#include <iostream>
#include <string>
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
        Matrix(int num_rows, int num_columns);
        ~Matrix();

        void SetMatrix(vector<double> values);

        vector<int> GetDimensions();

        void SetValue(int row, int column, double value);
        double GetValue(int row, int column);

        void LoadIdentityMatrix();

        void Multiplication(Matrix& m1, Matrix& m2);
        void Division(Matrix& m, double division_factor);

        void Display();
};


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

        for(int c = 0; c < this->columns; c++)
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

        for(int c = 0; c < this->columns; c++)
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

void Matrix::Multiplication(Matrix& m1, Matrix& m2)
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

void Matrix::Display() {

    for(int r = 0; r < rows; r++)
    {

        for(int c = 0; c < this->columns; c++)
        {

            clog << " " << matrix[r][c];

        }

        clog << endl;

    }

    clog << endl;
}


int main()
{
    vector<double> myvector;
    for (int i=11; i<=11+15; i++) myvector.push_back(i);


    Matrix Bt(4, 4);
    Matrix RES(4, 4);
    Bt.SetMatrix(myvector);

    Bt.SetValue(0, 3, 1);
    Bt.SetValue(2, 2, 23);
    Bt.Display();

//    vector<int> back = Bt.GetDimensions();
//    clog << " ROWS: " << back[0] << ", COLUMNS: " << back[1] << endl << endl;

//    Bt.SetValue(1,3,9);
//    Bt.SetValue(2,1,12);

//    Bt.Display();
//
//    clog << " MATRIX[2][3]: " << Bt.GetValue(2,1) << endl << endl;

//    Bt.LoadIdentityMatrix();

//    Bt.Display();

    RES.Multiplication(Bt, Bt);

    RES.Display();


    return 0;
}