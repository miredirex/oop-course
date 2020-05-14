#pragma once

#include <IntRange.h>
#include <car/Gear.h>
#include <car/MoveDirection.h>

class Car
{
public:
    Car() = default;

    bool TurnOnEngine();

    bool TurnOffEngine();

    [[nodiscard]] bool IsStarted() const;

    bool SetGear(int gear);

    bool SetGear(Gear gear);

    [[nodiscard]] Gear GetGear() const;

    bool SetSpeed(int speed);

    [[nodiscard]] int GetSpeed() const;

    [[nodiscard]] MoveDirection GetDirection() const;

private:
    [[nodiscard]] IntRange GetSpeedRange(Gear gear) const;

    bool m_isStarted = false;
    int m_currentSpeed = 0;
    Gear m_currentGear = Gear::NEUTRAL;

    const int MAX_AVAILABLE_SPEED = 150;

    const IntRange m_gearSpeedRanges[7]
    {
        IntRange(0, 20),  // Reverse
        IntRange(0, MAX_AVAILABLE_SPEED), // Neutral
        IntRange(0, 30),  // First
        IntRange(20, 50), // Second
        IntRange(30, 60), // Third
        IntRange(40, 90), // Fourth
        IntRange(50, MAX_AVAILABLE_SPEED) // Fifth
    };
};
