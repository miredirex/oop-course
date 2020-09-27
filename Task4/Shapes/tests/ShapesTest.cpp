#define CATCH_CONFIG_MAIN

#include <vector>
#include <regex>
#include "catch.hpp"
#include "Scene.h"
#include "calculation/Calculations.h"
#include "ShapeInputPatterns.h"

using namespace std;

using Rect = class Rectangle;

const double TOLERANCE = 0.001;

TEST_CASE("Perimeter/Area")
{
    // Area: 2100, perimeter: 200;
    auto rect = Rect{{ 0, 10 }, { 30, 80 }, 0xFFF, 0xFFF };
    // Area: 12.5, perimeter: 17.0710..
    auto tri = Triangle{{ 0, 0 }, { 5, 5 }, { 5, 0 }, 0xFFF, 0xFFF };
    // Area: 7853.98.., perimeter: 314.15..
    auto circle = Circle{{ 100, 100 }, 50, 0xFFF, 0xFFF };
    // Area: 0, perimeter: 111.80..
    auto line = LineSegment{{ 100, 100 }, { 200, 150 }, 0xFFF };
    // Area: 314,15.., perimeter: 62.83..
    auto circle2 = Circle{{ 50, 50 }, 10, 0xFFF, 0xFFF };

    // Vector of shapes fixture
    vector<unique_ptr<IShape>> shapes;
    shapes.push_back(make_unique<Rect>(rect));
    shapes.push_back(make_unique<Triangle>(tri));
    shapes.push_back(make_unique<Circle>(circle));
    shapes.push_back(make_unique<LineSegment>(line));
    shapes.push_back(make_unique<Circle>(circle2));

    SECTION("Perimeter and area of shapes should always be correct")
    {
        REQUIRE(rect.GetArea() == Approx(2100).epsilon(TOLERANCE));
        REQUIRE(rect.GetPerimeter() == Approx(200).epsilon(TOLERANCE));

        REQUIRE(tri.GetArea() == Approx(12.5).epsilon(TOLERANCE));
        REQUIRE(tri.GetPerimeter() == Approx(17.0710).epsilon(TOLERANCE));

        REQUIRE(circle.GetArea() == Approx(7853.98).epsilon(TOLERANCE));
        REQUIRE(circle.GetPerimeter() == Approx(314.15).epsilon(TOLERANCE));

        REQUIRE(line.GetArea() == 0);
        REQUIRE(line.GetPerimeter() == Approx(111.803).epsilon(TOLERANCE));

        REQUIRE(circle2.GetArea() == Approx(314.15).epsilon(TOLERANCE));
        REQUIRE(circle2.GetPerimeter() == Approx(62.83).epsilon(TOLERANCE));
    }

    SECTION("FindWithLargestArea function should return shape with largest area from a vector")
    {
        REQUIRE(FindWithLargestArea(shapes)->GetArea() == circle.GetArea());
    }

    SECTION("FindWithLeastPerimeter function should return shape with least perimeter from a vector")
    {
        REQUIRE(FindWithLeastPerimeter(shapes)->GetPerimeter() == tri.GetPerimeter());
    }
}

TEST_CASE("Patterns for shapes")
{
    auto triangleInput = "triangle 12.0 12.0 15 15.0 0.0 0.0 EE37CC EEFFCC";
    auto expectedTriangle = Triangle{{ 12.0, 12.0 }, { 15, 15.0 }, { 0, 0 }, 0xEE37CCFF, 0xEEFFCCFF };

    auto rectangleInput = "rectangle 12 12.0 14.8 13.2 AAFFCC EEFF88";
    auto expectedRectangle = Rect{{ 12, 12.0 }, { 14.8, 13.2 }, 0xAAFFCCFF, 0xEEFF88FF };

    auto lineInput = "line 12.0 12.0 15.0 15.0 A1FFCC";
    auto expectedLine = LineSegment{{ 12.0, 12.0 }, { 15.0, 15.0 }, 0xA1FFCCFF };

    auto circleInput = "circle 12 12.0 15 EEFFCC EEB38C";
    auto expectedCircle = Circle{{ 12, 12.0 }, 15, 0xEEFFCCFF, 0xEEB38CFF };

    SECTION("Patterns should match its regex")
    {
        REQUIRE(regex_match(triangleInput, regex(patterns::REGEX_TRIANGLE)));
        REQUIRE(regex_match(rectangleInput, regex(patterns::REGEX_RECTANGLE)));
        REQUIRE(regex_match(lineInput, regex(patterns::REGEX_LINE)));
        REQUIRE(regex_match(circleInput, regex(patterns::REGEX_CIRCLE)));
    }

    SECTION("Shapes are constructed correctly from regex patterns")
    {
        Scene scene;
        stringstream inputMock;

        inputMock << triangleInput << '\n';
        inputMock << rectangleInput << '\n';
        inputMock << lineInput << '\n';
        inputMock << circleInput << '\n';

        scene.InputDrawMode(inputMock);

        const auto& actualTriangle = scene.GetShapes()[0];
        const auto& actualRectangle = scene.GetShapes()[1];
        const auto& actualLine = scene.GetShapes()[2];
        const auto& actualCircle = scene.GetShapes()[3];

        REQUIRE(actualTriangle->ToString() == expectedTriangle.ToString());
        REQUIRE(actualRectangle->ToString() == expectedRectangle.ToString());
        REQUIRE(actualLine->ToString() == expectedLine.ToString());
        REQUIRE(actualCircle->ToString() == expectedCircle.ToString());
    }
}

TEST_CASE("ToString()s for shapes")
{
    SECTION("ToString() for triangle should return correct string representation")
    {
        auto triangle = Triangle{{ 12.0, 16.0 }, { 50, 20.0 }, { 0, 0 }, 0xEE37CCFF, 0xEEFFCCFF };

        REQUIRE(triangle.ToString() ==
                "triangle: points { (12.0, 16.0), (50.0, 20.0), (0.0, 0.0) }. outline color: #ee37ccff, fill color: #eeffccff, with area: 280.0, with perimeter: 112.1.");
    }

    SECTION("ToString() for rectangle should return correct string representation")
    {
        auto rectangle = Rect{{ 12, 12.0 }, { 14.8, 13.2 }, 0xAAFFCCFF, 0xEEFF88FF };

        REQUIRE(rectangle.ToString() ==
                "rectangle: points { (12.0, 12.0), (14.8, 13.2) }. outline color: #aaffccff, fill color: #eeff88ff, with dimensions: (w:2.8, h:1.2), with area: 3.4, with perimeter: 8.0.");
    }

    SECTION("ToString() for line should return correct string representation")
    {
        auto line = LineSegment{{ 12.0, 12.0 }, { 15.0, 15.0 }, 0xA1FFCCFF };

        REQUIRE(line.ToString() ==
                "line: points { (12.0, 12.0), (15.0, 15.0) }. outline color: #a1ffccff, with perimeter: 4.2.");
    }

    SECTION("ToString() for circle should return correct string representation")
    {
        auto circle = Circle{{ 12, 12.0 }, 15, 0xEEFFCCFF, 0xEEB38CFF };

        REQUIRE(circle.ToString() ==
                "circle: center { (12.0, 12.0) }. radius: 15.0, outline color: #eeffccff, fill color: #eeb38cff, with area: 706.9, with perimeter: 94.2.");
    }
}