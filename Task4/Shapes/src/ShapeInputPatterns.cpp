#include "ShapeInputPatterns.h"

/// line x1 y1 x2 y2 color
const char* patterns::REGEX_LINE = R"(^line (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) ([0-9a-fA-F]{6})$)";

/// triangle x1 y1 x2 y2 x3 y3 outline_color fill_color
const char* patterns::REGEX_TRIANGLE = R"(^triangle (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) ([0-9a-fA-F]{6}) ([0-9a-fA-F]{6})$)";

/// rectangle x1 y1 x2 y2 outline_color fill_color
const char* patterns::REGEX_RECTANGLE = R"(^rectangle (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) ([0-9a-fA-F]{6}) ([0-9a-fA-F]{6})$)";

/// circle x y radius outline_color fill_color
const char* patterns::REGEX_CIRCLE = R"(^circle (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) (\d+(?:\.\d+)?) ([0-9a-fA-F]{6}) ([0-9a-fA-F]{6})$)";
