#include "Scene.h"

void Scene::InputDrawMode(std::istream& stream)
{
    std::string input;

    while (std::getline(stream, input))
    {
        for (auto const& [shapeName, regex, construct] : m_shapesRegex)
        {
            std::smatch shapeConstructGroups;

            if ((input.rfind(shapeName, 0) == 0) && std::regex_search(input, shapeConstructGroups, regex))
            {
                std::unique_ptr<IShape> constructedShape = construct(shapeConstructGroups);
                m_shapes.push_back(std::move(constructedShape));
            }
        }
    }
}

const std::vector<std::unique_ptr<IShape>>& Scene::GetShapes() const
{
    return m_shapes;
}

void Scene::DrawScene(const ICanvas& canvas) const
{
    for (const auto& shape : m_shapes)
    {
        shape->Draw(canvas);
        canvas.Render();
    }
}

uint32_t Scene::ParseColor(const std::string& str)
{
    auto colorRgb = static_cast<uint32_t>(stoul(str, nullptr, 16) << 8);
    uint32_t colorRgbOpaque = colorRgb | 0x000000FF;

    return colorRgbOpaque;
}

std::unique_ptr<LineSegment> Scene::ConstructLineFromCaptureGroups(const std::smatch& groups)
{
    double x1 = stod(groups[1]);
    double y1 = stod(groups[2]);
    double x2 = stod(groups[3]);
    double y2 = stod(groups[4]);
    uint32_t color = Scene::ParseColor(groups[5]);

    return std::make_unique<LineSegment>(Point{ x1, y1 }, Point{ x2, y2 }, color);
}

std::unique_ptr<Triangle> Scene::ConstructTriangleFromCaptureGroups(const std::smatch& groups)
{
    double x1 = stod(groups[1]);
    double y1 = stod(groups[2]);
    double x2 = stod(groups[3]);
    double y2 = stod(groups[4]);
    double x3 = stod(groups[5]);
    double y3 = stod(groups[6]);
    uint32_t outlineColor = Scene::ParseColor(groups[7]);
    uint32_t fillColor = Scene::ParseColor(groups[8]);

    return std::make_unique<Triangle>(Point{ x1, y1 }, Point{ x2, y2 }, Point{ x3, y3 }, outlineColor, fillColor);
}

std::unique_ptr<Rectangle> Scene::ConstructRectangleFromCaptureGroups(const std::smatch& groups)
{
    double x1 = stod(groups[1]);
    double y1 = stod(groups[2]);
    double x2 = stod(groups[3]);
    double y2 = stod(groups[4]);
    uint32_t outlineColor = Scene::ParseColor(groups[5]);
    uint32_t fillColor = Scene::ParseColor(groups[6]);

    return std::make_unique<Rectangle>(Point{ x1, y1 }, Point{ x2, y2 }, outlineColor, fillColor);
}

std::unique_ptr<Circle> Scene::ConstructCircleFromCaptureGroups(const std::smatch& groups)
{
    double x = stod(groups[1]);
    double y = stod(groups[2]);
    double radius = stod(groups[3]);
    uint32_t outlineColor = Scene::ParseColor(groups[4]);
    uint32_t fillColor = Scene::ParseColor(groups[5]);

    return std::make_unique<Circle>(Point { x, y }, radius, outlineColor, fillColor);
}
