#ifndef INVERSE_MATRIX_IO_H
#define INVERSE_MATRIX_IO_H

#include "matrix3x3.h"

Matrix3x3 ReadMatrixFromFile(const char* fileName, int& errorCode);
Matrix3x3 ReadMatrixFromStream(std::istream& stream);
void PrintMatrixToStream(std::ostream& stream, const Matrix3x3& mat, char separator, unsigned int decimalPlaces);

#endif //INVERSE_MATRIX_IO_H
