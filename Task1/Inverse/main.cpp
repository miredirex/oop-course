#include <iostream>
#include "matrix3x3.h"
#include <optional>

Matrix3x3 ReadMatrixFromStream(std::istream& stream)
{
    Matrix3x3 mat;
    for (unsigned int i = 0; i < Matrix3x3::MATRIX_SIZE; i++)
    {
        for (unsigned int j = 0; j < Matrix3x3::MATRIX_SIZE; j++)
        {
            double value;
            stream >> value;
            mat.SetValueAt(i, j, value);
        }
    }
    return mat;
}

void PrintMatrixToStream(std::ostream& stream, Matrix3x3& mat, char separator, unsigned int decimalPlaces)
{
    for (unsigned int i = 0; i < Matrix3x3::MATRIX_SIZE; i++)
    {
        for (unsigned int j = 0; j < Matrix3x3::MATRIX_SIZE; j++)
        {
            double value = mat.GetValueAt(i, j) + 0.0; // To avoid -0.0 values
            stream << round(value * pow(10.0, decimalPlaces)) / pow(10.0, decimalPlaces);
            if (j < Matrix3x3::MATRIX_SIZE - 1) stream << separator;
        }
        stream << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: inverse.exe <matrix_file.txt>\n");
        return 1;
    }

    std::ifstream fileInputMatrix(argv[1]);
    if (!fileInputMatrix.is_open() || fileInputMatrix.bad())
    {
        printf("Input file can not be opened or not found\n");
        return 1;
    }

    Matrix3x3 matrix = ReadMatrixFromStream(fileInputMatrix);
    std::optional<Matrix3x3> inverse = matrix.GetInverseMatrix();

    if (inverse.has_value())
    {
        PrintMatrixToStream(std::cout, *inverse, '\t', 3);
    }
    else
    {
        printf("Determinant of the matrix is 0. Inverse matrix can not be found.\n");
        return 1;
    }

    return 0;
}
