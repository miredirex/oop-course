#include "matrix2x2.h"

Matrix2x2::Matrix2x2(double a, double b, double c, double d) {
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;
}

Matrix2x2::Matrix2x2(const double arr[MATRIX_SIZE * MATRIX_SIZE]) {
    matrix[0][0] = arr[0];
    matrix[0][1] = arr[1];
    matrix[1][0] = arr[2];
    matrix[1][1] = arr[3];
}

double Matrix2x2::GetDeterminant() {
    if (!determinant.has_value()) {
        determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    return *determinant;
}

Matrix2x2 Matrix2x2::GetTransposed() {
    return Matrix2x2 {
        matrix[0][0], matrix[1][0],
        matrix[0][1], matrix[1][1]
    };
}

std::optional<Matrix2x2> Matrix2x2::GetInverseMatrix() {
    double det = this->GetDeterminant();
    if (det == 0) {
        return std::nullopt;
    }

    return Matrix2x2 {
            1 / det * matrix[0][0], 1 / det * matrix[0][1],
            1 / det * matrix[1][0], 1 / det * matrix[1][1]
    };
}