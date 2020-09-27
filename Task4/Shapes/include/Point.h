#pragma once

#include <iostream>

struct Point
{
    double x, y;

    friend std::ostream& operator <<(std::ostream& output, const Point& p);
    [[nodiscard]] double DistanceTo(const Point& other) const;
};