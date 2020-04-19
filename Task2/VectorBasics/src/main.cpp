#include <vector>
#include <iostream>
#include <algorithm>
#include "vector_io.h"
#include "vector_process.h"

/**
 * Вариант 4: Разделить элементы массива на половину макс. элемента.
 */
int main()
{
    // Get first line from std::cin
    std::string inputLine;
    std::getline(std::cin, inputLine);

    std::vector<double> vectorOfDoubles;
    // Pass line with space separated values to form a vector
    SeparatedValuesToVector(inputLine, vectorOfDoubles);

    try
    {
        DivideElementsByHalfMax(vectorOfDoubles);
    }
    catch (const std::overflow_error& err)
    {
        std::cerr << err.what();
        return 1;
    }

    std::sort(vectorOfDoubles.begin(), vectorOfDoubles.end());
    PrintVector(vectorOfDoubles, std::cout);

    return 0;
}
