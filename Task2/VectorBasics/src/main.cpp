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
    std::vector<double> vectorOfDoubles;
    std::string inputLine;
    std::getline(std::cin, inputLine);

    // Feed line to function to form a vector
    SeparatedValuesToVector(inputLine, vectorOfDoubles);
    // Process
    try
    {
        DivideElementsOnHalvedMax(vectorOfDoubles);
    }
    catch (const std::overflow_error& err)
    {
        std::cerr << err.what();
        return 1;
    }

    // Sort and display
    std::sort(vectorOfDoubles.begin(), vectorOfDoubles.end());
    PrintVector(vectorOfDoubles, std::cout);

    return 0;
}
