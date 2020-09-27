#pragma once

#include "Point.h"
#include "shape/ISolidShape.h"
#include "canvas/ICanvasDrawable.h"

class Triangle : public ISolidShape
{
public:
    Triangle(Point v1, Point v2, Point v3, uint32_t outlineColor, uint32_t fillColor)
    : m_vertices { v1, v2, v3 },
      m_outlineColor(outlineColor),
      m_fillColor(fillColor) {}

    void Draw(const ICanvas& canvas) const override;

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] uint32_t GetFillColor() const override;

    [[nodiscard]] Point GetVertex1() const;

    [[nodiscard]] Point GetVertex2() const;

    [[nodiscard]] Point GetVertex3() const;

private:
    Point m_vertices[3];
    uint32_t m_outlineColor, m_fillColor;
};