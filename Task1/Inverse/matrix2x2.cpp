#include "matrix2x2.h"

Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
    m_matrix[0][0] = a;
    m_matrix[0][1] = b;
    m_matrix[1][0] = c;
    m_matrix[1][1] = d;
}

Matrix2x2::Matrix2x2(const double arr[MATRIX_SIZE * MATRIX_SIZE])
{
    m_matrix[0][0] = arr[0];
    m_matrix[0][1] = arr[1];
    m_matrix[1][0] = arr[2];
    m_matrix[1][1] = arr[3];
}

double Matrix2x2::GetDeterminant()
{
    if (!m_determinant.has_value())
    {
        m_determinant = m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0];
    }
    return *m_determinant;
}

double Matrix2x2::GetValueAt(unsigned int row, unsigned int col) const
{
    return m_matrix[row][col];
}

void Matrix2x2::SetValueAt(unsigned int row, unsigned int col, double value)
{
    m_matrix[row][col] = value;
    m_determinant.reset();
}

Matrix2x2 Matrix2x2::GetTransposed() const
{
    return Matrix2x2
    {
        m_matrix[0][0], m_matrix[1][0],
        m_matrix[0][1], m_matrix[1][1]
    };
}

std::optional<Matrix2x2> Matrix2x2::GetInverseMatrix()
{
    double det = this->GetDeterminant();
    if (det == 0)
    {
        return std::nullopt;
    }

    return Matrix2x2
    {
            1 / det * m_matrix[0][0], 1 / det * m_matrix[0][1],
            1 / det * m_matrix[1][0], 1 / det * m_matrix[1][1]
    };
}