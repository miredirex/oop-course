#include "vector_io.h"

void PrintVector(const std::vector<double>& vec, std::ostream& outStream, const char* delimiter)
{
    outStream << std::fixed << std::setprecision(3);
    for (auto const& d : vec)
    {
        outStream << d << delimiter;
    }
}
