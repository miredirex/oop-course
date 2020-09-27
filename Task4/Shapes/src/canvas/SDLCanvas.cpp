#include <SDL2_gfxPrimitives.h>
#include "canvas/SDLCanvas.h"

void SDLCanvas::DrawLine(Point from, Point to, uint32_t color) const
{
    lineColor(m_renderer, (Sint16)from.x, (Sint16)from.y, (Sint16)to.x, (Sint16)to.y, SDL_Swap32(color));
}

void SDLCanvas::DrawPolygon(const std::vector<Point>& points, uint32_t lineColor) const
{
    PointsXY pointsData = UnwrapPoints(points);

    polygonColor(m_renderer, pointsData.xs.data(), pointsData.ys.data(), pointsData.count, SDL_Swap32(lineColor));
}

void SDLCanvas::FillPolygon(const std::vector<Point>& points, uint32_t fillColor) const
{
    PointsXY pointsData = UnwrapPoints(points);

    filledPolygonColor(m_renderer, pointsData.xs.data(), pointsData.ys.data(), pointsData.count, SDL_Swap32(fillColor));
}

void SDLCanvas::DrawCircle(Point center, double radius, uint32_t lineColor) const
{
    circleColor(m_renderer, (Sint16)center.x, (Sint16)center.y, (Sint16)radius, SDL_Swap32(lineColor));
}

void SDLCanvas::FillCircle(Point center, double radius, uint32_t fillColor) const
{
    filledCircleColor(m_renderer, (Sint16)center.x, (Sint16)center.y, (Sint16)radius, SDL_Swap32(fillColor));
}

SDLCanvas::PointsXY SDLCanvas::UnwrapPoints(const std::vector<Point>& points)
{
    std::vector<Sint16> pointsX;
    pointsX.reserve(points.size());

    std::vector<Sint16> pointsY;
    pointsY.reserve(points.size());

    for (const Point& p : points)
    {
        pointsX.push_back((Sint16)p.x);
        pointsY.push_back((Sint16)p.y);
    }

    return PointsXY { pointsX, pointsY, static_cast<int>(points.size()) };
}

void SDLCanvas::DrawRect(Point topLeft, Point bottomRight, uint32_t lineColor) const
{
    rectangleColor(m_renderer, topLeft.x, topLeft.y, bottomRight.x, bottomRight.y, SDL_Swap32(lineColor));
}

void SDLCanvas::FillRect(Point topLeft, Point bottomRight, uint32_t lineColor) const
{
    boxColor(m_renderer, topLeft.x, topLeft.y, bottomRight.x, bottomRight.y, SDL_Swap32(lineColor));
}

void SDLCanvas::Render() const
{
    SDL_RenderPresent(m_renderer);
}