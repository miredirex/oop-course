#include <sstream>
#include "shape/Triangle.h"
#include <iomanip>

double Triangle::GetArea() const
{
    const Point& A = m_vertices[0];
    const Point& B = m_vertices[1];
    const Point& C = m_vertices[2];

    // Shoelace formula
    return 0.5 * std::abs((A.x - C.x)*(B.y - A.y) - (A.x - B.x)*(C.y - A.y));
}

double Triangle::GetPerimeter() const
{
    return m_vertices[0].DistanceTo(m_vertices[1])
         + m_vertices[1].DistanceTo(m_vertices[2])
         + m_vertices[2].DistanceTo(m_vertices[0]);
}

std::string Triangle::ToString() const
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "triangle: points { ";
    oss << "(" << GetVertex1().x << ", " << GetVertex1().y << "), "
        << "(" << GetVertex2().x << ", " << GetVertex2().y << "), "
        << "(" << GetVertex3().x << ", " << GetVertex3().y << ") }. ";
    oss << "outline color: #" << std::hex << m_outlineColor << ", ";
    oss << "fill color: #" << std::hex << m_fillColor << ", ";
    oss << "with area: " << GetArea() << ", ";
    oss << "with perimeter: " << GetPerimeter() << '.';

    return oss.str();
}

uint32_t Triangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t Triangle::GetFillColor() const
{
    return m_fillColor;
}

Point Triangle::GetVertex1() const
{
    return m_vertices[0];
}

Point Triangle::GetVertex2() const
{
    return m_vertices[1];
}

Point Triangle::GetVertex3() const
{
    return m_vertices[2];
}

void Triangle::Draw(const ICanvas& canvas) const
{
    std::vector vertices { m_vertices[0], m_vertices[1], m_vertices[2] };

    canvas.FillPolygon(vertices, m_fillColor);
    canvas.DrawPolygon(vertices, m_outlineColor);
}
