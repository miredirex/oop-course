#pragma once

#include <regex>
#include <functional>
#include <unordered_map>
#include "ShapeInputPatterns.h"
#include "shape/IShape.h"
#include "shape/LineSegment.h"
#include "shape/Triangle.h"
#include "shape/Circle.h"
#include "shape/Rectangle.h"

class Scene
{
public:
    Scene() = default;

    void InputDrawMode(std::istream& stream);

    void DrawScene(const ICanvas& canvas) const;

    [[nodiscard]] const std::vector<std::unique_ptr<IShape>>& GetShapes() const;

private:
    std::vector<std::unique_ptr<IShape>> m_shapes;

    struct CanvasDrawableData
    {
        const std::string name;
        const std::regex regex;
        const std::function<std::unique_ptr<IShape>(const std::smatch&)> construct;
    };

    const std::vector<CanvasDrawableData> m_shapesRegex = {
        CanvasDrawableData { "line",      std::regex(patterns::REGEX_LINE),      ConstructLineFromCaptureGroups },
        CanvasDrawableData { "rectangle", std::regex(patterns::REGEX_RECTANGLE), ConstructRectangleFromCaptureGroups },
        CanvasDrawableData { "triangle",  std::regex(patterns::REGEX_TRIANGLE),  ConstructTriangleFromCaptureGroups },
        CanvasDrawableData { "circle",    std::regex(patterns::REGEX_CIRCLE),    ConstructCircleFromCaptureGroups }
    };

    /** Parses hex color
     *  stoul("RRGGBB") -> 0x00RRGGBB -> 0xRRGGBB00 -> 0xRRGGBBFF (FF for alpha, always opaque)
     */
    static uint32_t ParseColor(const std::string& str);

    static std::unique_ptr<LineSegment> ConstructLineFromCaptureGroups(const std::smatch& groups);

    static std::unique_ptr<Triangle> ConstructTriangleFromCaptureGroups(const std::smatch& groups);

    static std::unique_ptr<Circle> ConstructCircleFromCaptureGroups(const std::smatch& groups);

    static std::unique_ptr<class Rectangle> ConstructRectangleFromCaptureGroups(const std::smatch& groups);

    // ^^^ 'class Rectangle' because wingdi.h has a function called Rectangle(..)
};