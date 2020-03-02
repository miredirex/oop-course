#include <iostream>
#include "matrix_io.h"
#include "matrix3x3.h"
#include <optional>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: inverse.exe <matrix_file.txt>\n");
        return 1;
    }

    int errorCode = 0;
    Matrix3x3 matrix = ReadMatrixFromFile(argv[1], errorCode);

    if (errorCode)
    {
        printf("Input file can not be opened or not found\n");
        return 1;
    }

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
