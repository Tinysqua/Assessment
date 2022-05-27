//
// Created by 12506 on 26/5/2022.
//

#include <iostream>
#include "matrix.h"
Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
}}

Matrix::Matrix(int rows, int cols, int** matrix)
{
    this->rows = rows;
    this->cols = cols;
    this->matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];}
    for (int i = 0; i < this->rows; i++)
        for(int k=0;k< this->cols;k++)
            this->matrix[i][k] = matrix[i][k];


}


std::ostream &operator<<(std::ostream &out, const Matrix & matrix)
{
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            out << matrix.matrix[i][j] << " ";
            //printf("%2d", matrix.matrix[i][j]);

        }
        out << std::endl;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Matrix &matrix)
{
    for (int i = 0; i < matrix.rows; i++) {
        //int a[matrix.cols];
        printf("for the row: %d:\n", i + 1);
        for (int j = 0; j < matrix.cols; j++) {
            in >> matrix.matrix[i][j];
        }

    }
    return in;
}


Matrix Matrix::operator*(const Matrix &other)  {
    int new_rows = this->rows;
    int new_cols = other.cols;
    Matrix C(new_rows, new_cols);
    if (this->cols != other.rows) { std::cout << "These two matrix can't be multiplied"; }
    else {

        for (int i = 0; i < this->rows; i++)
            for (int j = 0; j < other.cols; j++) {
                int total = 0;
                for (int k = 0; k < this->cols; k++) {
                    total += this->matrix[i][k] * other.matrix[k][j];
                }
                C.matrix[i][j] = total;
            }

    }
    return C;
}
Matrix Matrix::operator+(const Matrix& other)
{
    int new_rows = this->rows;
    int new_cols = this->cols;
    Matrix C(new_rows, new_cols);
    for(int i=0;i< this->rows;i++)
        for(int k=0;k< this->cols;k++)
        {
            C.matrix[i][k] = this->matrix[i][k]+other.matrix[i][k];
        }
    return C;
}

Matrix Matrix::operator-(const Matrix& other)
{
    int new_rows = this->rows;
    int new_cols = this->cols;
    Matrix C(new_rows, new_cols);
    for(int i=0;i< this->rows;i++)
        for(int k=0;k< this->cols;k++)
        {
            C.matrix[i][k] = this->matrix[i][k]-other.matrix[i][k];
        }
    return C;
}

bool Matrix::operator==(const Matrix& other)
{
    bool flag = true;
    for(int i=0;i< this->rows;i++)
        for(int k=0;k< this->cols;k++)
        {
            if (this->matrix[i][k]!=other.matrix[i][k])
                flag = false;
        }
    return flag;
}

Matrix::~Matrix() {
    delete[] this->matrix;
}



