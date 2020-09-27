#include "shape/LineSegment.h"
#include <sstream>
#include <iomanip>

double LineSegment::GetArea() const
{
    return 0;
}

double LineSegment::GetPerimeter() const
{
    return m_start.DistanceTo(m_end);
}

std::string LineSegment::ToString() const
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "line: points { ";
    oss << "(" << GetStartPoint().x << ", " << GetStartPoint().y << "), "
        << "(" << GetEndPoint().x << ", " << GetEndPoint().y << ") }. ";
    oss << "outline color: #" << std::hex << m_color << ", ";
    oss << "with perimeter: " << GetPerimeter() << '.';

    return oss.str();
}

uint32_t LineSegment::GetOutlineColor() const
{
    return m_color;
}

Point LineSegment::GetStartPoint() const
{
    return m_start;
}

Point LineSegment::GetEndPoint() const
{
    return m_end;
}

void LineSegment::Draw(const ICanvas& canvas) const
{
    canvas.DrawLine(m_start, m_end, m_color);
}
