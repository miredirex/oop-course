#pragma once

#include "canvas/ICanvas.h"
#include <SDL.h>

class SDLCanvas : public ICanvas
{
public:
    explicit SDLCanvas(SDL_Renderer* renderer) : m_renderer(renderer) {}

    void DrawLine(Point from, Point to, uint32_t color) const override;

    void DrawPolygon(const std::vector<Point>& points, uint32_t lineColor) const override;

    void FillPolygon(const std::vector<Point>& points, uint32_t fillColor) const override;

    void DrawCircle(Point center, double radius, uint32_t lineColor) const override;

    void FillCircle(Point center, double radius, uint32_t fillColor) const override;

    void DrawRect(Point topLeft, Point bottomRight, uint32_t lineColor) const override;

    void FillRect(Point topLeft, Point bottomRight, uint32_t lineColor) const override;

    void Render() const override;

private:
    struct PointsXY
    {
        std::vector<Sint16> xs;
        std::vector<Sint16> ys;
        int count;
    };

    static PointsXY UnwrapPoints(const std::vector<Point>& points);

    SDL_Renderer* m_renderer;
};