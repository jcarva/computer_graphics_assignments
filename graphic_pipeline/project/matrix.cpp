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
    for (int i=1; i<=20; i++) myvector.push_back(i+50);


    Matrix Bt(4, 5);
    Bt.SetMatrix(myvector);
    Bt.Display();

    vector<int> back = Bt.GetDimensions();
    clog << " ROWS: " << back[0] << ", COLUMNS: " << back[1] << endl << endl;

    Bt.SetValue(1,3,9);
    Bt.SetValue(2,1,12);

    Bt.Display();

    clog << "MATRIX[2][3]: " << Bt.GetValue(2,1) << endl;


    return 0;
}