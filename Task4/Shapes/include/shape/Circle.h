#pragma once

#include "Point.h"
#include "shape/ISolidShape.h"
#include "canvas/ICanvasDrawable.h"

class Circle : public ISolidShape
{
public:
    Circle(Point center, double radius, uint32_t outlineColor, uint32_t fillColor)
    : m_center(center),
      m_radius(radius),
      m_outlineColor(outlineColor),
      m_fillColor(fillColor) {}

    void Draw(const ICanvas& canvas) const override;

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] uint32_t GetFillColor() const override;

    [[nodiscard]] Point GetCenter() const;

    [[nodiscard]] double GetRadius() const;

private:
    Point m_center;
    double m_radius;
    uint32_t m_outlineColor, m_fillColor;
};
