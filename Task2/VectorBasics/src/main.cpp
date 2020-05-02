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
    std::vector<double> vectorOfDoubles(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));

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
