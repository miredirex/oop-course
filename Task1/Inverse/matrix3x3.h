#ifndef INVERSE_MATRIX3X3_H
#define INVERSE_MATRIX3X3_H

#include "matrix2x2.h"
#include <iostream>
#include <optional>
#include <fstream>
#include <cmath>
#include <iomanip>

class Matrix3x3 {
public:
    static const unsigned int MATRIX_SIZE = 3;

    Matrix3x3() = default; // All zeros

    Matrix3x3(double arr[MATRIX_SIZE * MATRIX_SIZE]);

    Matrix3x3(const char *inputFileName);

    double GetDeterminant();

    double GetValueAt(unsigned int row, unsigned int col);

    void SetValueAt(unsigned int row, unsigned int col, double value);

    Matrix2x2 GetMinor(unsigned int blockingRow, unsigned int blockingColumn);

    Matrix3x3 Transpose();

    std::optional<Matrix3x3> GetInverseMatrix();

    void PrintMatrix(std::ostream& stream, const char separator, unsigned int decimalPlaces);

private:
    std::optional<double> determinant;
    double matrix[MATRIX_SIZE][MATRIX_SIZE] = {0.0};
};

#endif //INVERSE_MATRIX3X3_H
