#pragma once

#include <vector>
#include "shape/IShape.h"

const std::unique_ptr<IShape>& FindWithLargestArea(const std::vector<std::unique_ptr<IShape>>& shapes);
const std::unique_ptr<IShape>& FindWithLeastPerimeter(const std::vector<std::unique_ptr<IShape>>& shapes);