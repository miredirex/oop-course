#include <algorithm>
#include "calculation/Calculations.h"

const std::unique_ptr<IShape>& FindWithLargestArea(const std::vector<std::unique_ptr<IShape>>& shapes)
{
    auto it = std::max_element(shapes.begin(), shapes.end(),
                               [](const std::unique_ptr<IShape>& shapeA, const std::unique_ptr<IShape>& shapeB) {
                                   return shapeA->GetArea() < shapeB->GetArea();
                               });

    return *it;
}

const std::unique_ptr<IShape>& FindWithLeastPerimeter(const std::vector<std::unique_ptr<IShape>>& shapes)
{
    auto it = std::min_element(shapes.cbegin(), shapes.cend(),
                               [](const std::unique_ptr<IShape>& shapeA, const std::unique_ptr<IShape>& shapeB) {
                                   return shapeA->GetPerimeter() < shapeB->GetPerimeter();
                               });

    return *it;
}
