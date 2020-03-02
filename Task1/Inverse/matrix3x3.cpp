#include "matrix3x3.h"

Matrix3x3::Matrix3x3(const char* input) {
    std::ifstream filein(input);
    if (!filein.is_open() || filein.bad()) {
        printf("Input file can not be opened\n");
        exit(1);
    }

    for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
        for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
            filein >> matrix[i][j];
        }
    }
}

double Matrix3x3::GetValueAt(unsigned int row, unsigned int col) {
    return matrix[row][col];
}

void Matrix3x3::SetValueAt(unsigned int row, unsigned int col, double value) {
    matrix[row][col] = value;
}

void Matrix3x3::PrintMatrix(std::ostream& stream, const char separator, unsigned int decimalPlaces) {
    for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
        for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
            double value = matrix[i][j] + 0.0; // To avoid -0.0 values
            stream << round(value * pow(10.0, decimalPlaces)) / pow(10.0, decimalPlaces);
            if (j < MATRIX_SIZE - 1) stream << separator;
        }
        stream << std::endl;
    }
}

double Matrix3x3::GetDeterminant() {
    if (!determinant.has_value()) {
        double det = 0.0;
        for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
            auto sign = (i % 2 == 0) ? 1 : -1;
            Matrix2x2 minor = GetMinor(0, i);

            det += sign * matrix[0][i] * minor.GetDeterminant();
        }
        determinant = det;
    }

    return *determinant;
}

Matrix2x2 Matrix3x3::GetMinor(unsigned int blockingRow, unsigned int blockingColumn) {
    double values[4];
    unsigned int counter = 0;
    for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
        for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
            if (i != blockingRow && j != blockingColumn) {
                values[counter] = matrix[i][j];
                counter++;
            }
        }
    }

    return Matrix2x2 { values };
}

Matrix3x3 Matrix3x3::Transpose() {
    Matrix3x3 transposed;
    for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
        for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
            transposed.SetValueAt(j, i, matrix[i][j]);
        }
    }

    return transposed;
}

std::optional<Matrix3x3> Matrix3x3::GetInverseMatrix() {
    double det = GetDeterminant();

    if (det == 0) {
        return std::nullopt;
    }

    Matrix3x3 inverse;

    for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
        for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
            int sign = pow(-1, (i+1)+(j+1));
            double minorDeterminant = sign * GetMinor(i, j).GetDeterminant();
            inverse.SetValueAt(i, j, 1 / det * minorDeterminant);
        }
    }
    return inverse.Transpose();
}