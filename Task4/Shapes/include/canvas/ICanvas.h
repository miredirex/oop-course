#pragma once

#include <vector>
#include "Point.h"

class ICanvas
{
public:
    virtual void DrawLine(Point from, Point to, uint32_t color) const = 0;

    virtual void DrawPolygon(const std::vector<Point>& points, uint32_t lineColor) const = 0;

    virtual void FillPolygon(const std::vector<Point>& points, uint32_t fillColor) const = 0;

    virtual void DrawCircle(Point center, double radius, uint32_t lineColor) const = 0;

    virtual void FillCircle(Point center, double radius, uint32_t fillColor) const = 0;

    virtual void DrawRect(Point topLeft, Point bottomRight, uint32_t lineColor) const = 0;

    virtual void FillRect(Point topLeft, Point bottomRight, uint32_t fillColor) const = 0;

    virtual void Render() const = 0;

    virtual ~ICanvas() = default;
};