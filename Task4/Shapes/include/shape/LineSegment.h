#pragma once

#include "Point.h"
#include "shape/IShape.h"
#include "canvas/ICanvasDrawable.h"

class LineSegment : public IShape
{
public:
    LineSegment(Point start, Point end, uint32_t color)
    : m_start(start),
      m_end(end),
      m_color(color) {}

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] Point GetStartPoint() const;

    [[nodiscard]] Point GetEndPoint() const;

    void Draw(const ICanvas& canvas) const override;

private:
    Point m_start;
    Point m_end;
    uint32_t m_color;
};