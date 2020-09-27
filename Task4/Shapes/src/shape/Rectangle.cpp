#include "shape/Rectangle.h"
#include <sstream>
#include <iomanip>

double Rectangle::GetArea() const
{
    return GetWidth() * GetHeight();
}

double Rectangle::GetPerimeter() const
{
    return 2 * (GetWidth() + GetHeight());
}

std::string Rectangle::ToString() const
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "rectangle: points { ";
    oss << "(" << GetTopLeft().x << ", " << GetTopLeft().y << "), "
        << "(" << GetBottomRight().x << ", " << GetBottomRight().y << ") }. ";
    oss << "outline color: #" << std::hex << m_outlineColor << ", ";
    oss << "fill color: #" << std::hex << m_fillColor << ", ";
    oss << "with dimensions: " << "(w:" << GetWidth() << ", h:" << GetHeight() << ")" << ", ";
    oss << "with area: " << GetArea() << ", ";
    oss << "with perimeter: " << GetPerimeter() << '.';

    return oss.str();
}

uint32_t Rectangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t Rectangle::GetFillColor() const
{
    return m_fillColor;
}

Point Rectangle::GetTopLeft() const
{
    return m_topLeft;
}

Point Rectangle::GetBottomRight() const
{
    return m_bottomRight;
}

double Rectangle::GetWidth() const
{
    return m_bottomRight.x - m_topLeft.x;
}

double Rectangle::GetHeight() const
{
    return m_bottomRight.y - m_topLeft.y;
}

void Rectangle::Draw(const ICanvas& canvas) const
{
    canvas.FillRect(m_topLeft, m_bottomRight, m_fillColor);
    canvas.DrawRect(m_topLeft, m_bottomRight, m_outlineColor);
}
