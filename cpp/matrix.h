#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
class Matrix {
private:
    int rows, cols;
    int **matrix;
public:
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, int** matrix);
    Matrix (Matrix&& other);
    Matrix (const Matrix& other);
    friend std::istream& operator>>(std::istream &in, Matrix &matrix);
    friend std::ostream& operator<<(std::ostream &out, const Matrix &matrix);
    Matrix operator*(const Matrix &other);
    Matrix operator+(const Matrix &other);
    Matrix operator-(const Matrix& other);
    bool operator==(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix &&other);  
    ~Matrix();


};
#endif