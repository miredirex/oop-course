#ifndef INVERSE_MATRIX3X3_H
#define INVERSE_MATRIX3X3_H

#include "matrix2x2.h"
#include <iostream>
#include <optional>
#include <fstream>
#include <cmath>
#include <iomanip>

class Matrix3x3
{
public:
    static const unsigned int MATRIX_SIZE = 3;

    Matrix3x3() = default; // All zeros

    Matrix3x3(double arr[MATRIX_SIZE * MATRIX_SIZE]);

    double GetDeterminant();

    double GetValueAt(unsigned int row, unsigned int col) const;

    void SetValueAt(unsigned int row, unsigned int col, double value);

    Matrix2x2 GetMinor(unsigned int blockingRow, unsigned int blockingColumn) const;

    Matrix3x3 GetTransposed() const;

    std::optional<Matrix3x3> GetInverseMatrix();

private:
    std::optional<double> m_determinant;
    double m_matrix[MATRIX_SIZE][MATRIX_SIZE] = {0.0};
};

#endif //INVERSE_MATRIX3X3_H
