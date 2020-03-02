#include "matrix_io.h"

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

Matrix3x3 ReadMatrixFromFile(const char* fileName, int& errorCode)
{
    std::ifstream inputMatrixStream(fileName);
    if (!inputMatrixStream.is_open() || inputMatrixStream.bad())
    {
        printf("Input file can not be opened or not found\n");
        errorCode = 1;
    }
    return ReadMatrixFromStream(inputMatrixStream);
}

void PrintMatrixToStream(std::ostream& stream, const Matrix3x3& mat, char separator, unsigned int decimalPlaces)
{
    stream << std::setprecision(decimalPlaces) << std::fixed;
    for (unsigned int i = 0; i < Matrix3x3::MATRIX_SIZE; i++)
    {
        for (unsigned int j = 0; j < Matrix3x3::MATRIX_SIZE; j++)
        {
            double value = mat.GetValueAt(i, j) + 0.0; // To avoid -0.0 values
            stream << value;
            if (j < Matrix3x3::MATRIX_SIZE - 1)
            {
                stream << separator;
            }
        }
        stream << std::endl;
    }
}