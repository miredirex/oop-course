#include "matrix3x3.h"

double Matrix3x3::GetValueAt(unsigned int row, unsigned int col) const
{
    return m_matrix[row][col];
}

void Matrix3x3::SetValueAt(unsigned int row, unsigned int col, double value)
{
    m_matrix[row][col] = value;
    m_determinant.reset();
}

double Matrix3x3::GetDeterminant()
{
    if (!m_determinant.has_value())
    {
        double det = 0.0;
        for (unsigned int i = 0; i < MATRIX_SIZE; i++)
        {
            auto sign = (i % 2 == 0) ? 1 : -1;
            Matrix2x2 minor = GetMinor(0, i);

            det += sign * m_matrix[0][i] * minor.GetDeterminant();
        }
        m_determinant = det;
    }

    return *m_determinant;
}

Matrix2x2 Matrix3x3::GetMinor(unsigned int blockingRow, unsigned int blockingColumn) const
{
    double values[4];
    unsigned int counter = 0;
    for (unsigned int i = 0; i < MATRIX_SIZE; i++)
    {
        for (unsigned int j = 0; j < MATRIX_SIZE; j++)
        {
            if (i != blockingRow && j != blockingColumn)
            {
                values[counter] = m_matrix[i][j];
                counter++;
            }
        }
    }

    return Matrix2x2 { values };
}

Matrix3x3 Matrix3x3::GetTransposed() const
{
    Matrix3x3 transposed;
    for (unsigned int i = 0; i < MATRIX_SIZE; i++)
    {
        for (unsigned int j = 0; j < MATRIX_SIZE; j++)
        {
            transposed.SetValueAt(j, i, m_matrix[i][j]);
        }
    }

    return transposed;
}

std::optional<Matrix3x3> Matrix3x3::GetInverseMatrix()
{
    double det = GetDeterminant();

    if (det == 0)
    {
        return std::nullopt;
    }

    Matrix3x3 inverse;

    for (unsigned int i = 0; i < MATRIX_SIZE; i++)
    {
        for (unsigned int j = 0; j < MATRIX_SIZE; j++)
        {
            int sign = pow(-1, (i+1)+(j+1));
            double minorDeterminant = sign * GetMinor(i, j).GetDeterminant();
            inverse.SetValueAt(i, j, 1 / det * minorDeterminant);
        }
    }
    return inverse.GetTransposed();
}