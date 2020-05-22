#include <car/EnumUtil.h>

std::string GearToString(Gear g)
{
    switch (g)
    {
        case Gear::REVERSE:
            return "reverse";
        case Gear::NEUTRAL:
            return "neutral";
        case Gear::FIRST:
            return "first";
        case Gear::SECOND:
            return "second";
        case Gear::THIRD:
            return "third";
        case Gear::FOURTH:
            return "fourth";
        case Gear::FIFTH:
            return "fifth";
    }
}

std::string MoveDirectionToString(MoveDirection dir)
{
    switch (dir)
    {
        case MoveDirection::STILL:
            return "still";
        case MoveDirection::FORWARD:
            return "forward";
        case MoveDirection::BACKWARD:
            return "backward";
    }
}