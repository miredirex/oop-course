#include <iostream>
#include "matrix3x3.h"
#include <optional>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: inverse.exe <matrix_file.txt>\n");
        return 1;
    }

    Matrix3x3 matrix(argv[1]);
    std::optional<Matrix3x3> inverse = matrix.GetInverseMatrix();

    if (inverse.has_value()) {
        inverse->PrintMatrix(std::cout, '\t');
    } else {
        printf("Determinant of the matrix is 0. Inverse matrix can not be found.\n");
        return 1;
    }

    return 0;
}
