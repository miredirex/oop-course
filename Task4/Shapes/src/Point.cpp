#include "Point.h"
#include <cmath>

std::ostream& operator<<(std::ostream& output, const Point& p)
{
    output << "(" << p.x << "; " << p.y << ")";
    return output;
}

double Point::DistanceTo(const Point &other) const
{
    return std::sqrt(std::pow((other.x - this->x), 2) + std::pow((other.y - this->y), 2) );
}