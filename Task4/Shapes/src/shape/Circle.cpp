#include <sstream>
#include <iomanip>
#include <SDL_stdinc.h>
#include "shape/Circle.h"

double Circle::GetArea() const
{
    return M_PI * m_radius * m_radius;
}

double Circle::GetPerimeter() const
{
    return 2 * M_PI * m_radius;
}

std::string Circle::ToString() const
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "circle: center { ";
    oss << "(" << GetCenter().x << ", " << GetCenter().y << ") }. ";
    oss << "radius: " << GetRadius() << ", ";
    oss << "outline color: #" << std::hex << m_outlineColor << ", ";
    oss << "fill color: #" << std::hex << m_fillColor << ", ";
    oss << "with area: " << GetArea() << ", ";
    oss << "with perimeter: " << GetPerimeter() << '.';

    return oss.str();
}

uint32_t Circle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t Circle::GetFillColor() const
{
    return m_fillColor;
}

Point Circle::GetCenter() const
{
    return m_center;
}

double Circle::GetRadius() const
{
    return m_radius;
}

void Circle::Draw(const ICanvas& canvas) const
{
    canvas.FillCircle(m_center, m_radius, m_fillColor);
    canvas.DrawCircle(m_center, m_radius, m_outlineColor);
}
