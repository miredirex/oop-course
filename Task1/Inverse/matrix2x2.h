#ifndef INVERSE_MATRIX2X2_H
#define INVERSE_MATRIX2X2_H

#include <optional>

class Matrix2x2 {
public:
    static const unsigned int MATRIX_SIZE = 2;

    Matrix2x2() = default; // All zeros

    Matrix2x2(double a, double b, double c, double d);

    Matrix2x2(const double arr[MATRIX_SIZE * MATRIX_SIZE]);

    double GetDeterminant();

    Matrix2x2 GetTransposed();

    std::optional<Matrix2x2> GetInverseMatrix();

private:
    std::optional<double> determinant;
    double matrix[MATRIX_SIZE][MATRIX_SIZE] = { 0.0 };
};

#endif //INVERSE_MATRIX2X2_H
