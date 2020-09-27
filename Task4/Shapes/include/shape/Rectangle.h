#pragma once

#include "Point.h"
#include "shape/ISolidShape.h"
#include "canvas/ICanvasDrawable.h"

class Rectangle : public ISolidShape
{
public:
    Rectangle(Point topLeft, Point bottomRight, uint32_t outlineColor, uint32_t fillColor)
    : m_topLeft(topLeft),
      m_bottomRight(bottomRight),
      m_outlineColor(outlineColor),
      m_fillColor(fillColor) {}

    void Draw(const ICanvas& canvas) const override;

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] uint32_t GetFillColor() const override;

    [[nodiscard]] Point GetTopLeft() const;

    [[nodiscard]] Point GetBottomRight() const;

    [[nodiscard]] double GetWidth() const;

    [[nodiscard]] double GetHeight() const;

private:
    Point m_topLeft, m_bottomRight;
    uint32_t m_outlineColor, m_fillColor;
};