#include "vector_process.h"

void DivideElementsByHalfMax(std::vector<double>& vec)
{
    if (vec.empty()) return;

    const auto max = std::max_element(vec.begin(), vec.end());

    if (*max == 0.0)
    {
        throw std::overflow_error("Maximum value in vector is 0. Division by zero would occur.");
    }

    const double halfMax = *max / 2.0;

    for (double& element : vec)
    {
        element /= halfMax;
    }
}