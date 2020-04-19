#include "vector_io.h"

void SeparatedValuesToVector(const std::string& line, std::vector<double>& vec)
{
    std::istringstream inputStream(line);
    double d;
    while (inputStream >> d)
    {
        vec.push_back(d);
    }
}

void PrintVector(const std::vector<double>& vec, std::ostream& outStream, const char* delimiter)
{
    outStream << std::fixed << std::setprecision(3);
    for (auto const& d : vec)
    {
        outStream << d << delimiter;
    }
}
