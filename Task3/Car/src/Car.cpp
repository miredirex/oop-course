#include <car/Car.h>

bool Car::TurnOnEngine()
{
    if (!m_isStarted)
    {
        m_isStarted = true;
        return true;
    }
    return false;
}

bool Car::TurnOffEngine()
{
    if (m_isStarted && m_currentGear == Gear::NEUTRAL && m_currentSpeed == 0)
    {
        m_isStarted = false;
        return true;
    }
    return false;
}

bool Car::IsStarted() const
{
    return m_isStarted;
}

bool Car::SetGear(Gear gear)
{
    // Switching gears is impossible if moving backward
    if (gear > Gear::REVERSE && GetDirection() == MoveDirection::BACKWARD)
    {
        return false;
    }
    // Switching to the same gear is fine
    if (gear == m_currentGear)
    {
        return true;
    }
    if (m_isStarted && GetSpeedRange(gear).Contains(m_currentSpeed))
    {
        m_currentGear = gear;
        return true;
    }
    return false;
}

bool Car::SetGear(int gear)
{
    if (gear < static_cast<int>(Gear::REVERSE) || gear > static_cast<int>(Gear::FIFTH))
    {
        return false;
    }

    Gear gearEnum = static_cast<Gear>(gear);
    return SetGear(gearEnum);
}

Gear Car::GetGear() const
{
    return m_currentGear;
}

bool Car::SetSpeed(int speed)
{
    if (!m_isStarted || !GetSpeedRange(m_currentGear).Contains(speed) ||
        !GetSpeedRange(m_currentGear).Contains(m_currentSpeed))
    {
        return false;
    }
    if (m_currentGear == Gear::NEUTRAL && speed > m_currentSpeed)
    {
        return false;
    }

    m_currentSpeed = speed;
    return true;
}

int Car::GetSpeed() const
{
    return m_currentSpeed;
}

MoveDirection Car::GetDirection() const
{
    if (m_currentGear != Gear::REVERSE && m_currentSpeed > 0)
    {
        return MoveDirection::FORWARD;
    } else if (m_currentGear == Gear::REVERSE && m_currentSpeed > 0)
    {
        return MoveDirection::BACKWARD;
    } else
    {
        return MoveDirection::STILL;
    }
}

IntRange Car::GetSpeedRange(Gear gear) const
{
    // +1 because it starts with -1 (Gear::REVERSE)
    return m_gearSpeedRanges[static_cast<int>(gear) + 1];
}
