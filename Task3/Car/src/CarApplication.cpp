#include <car/CarApplication.h>
#include <iostream>
#include <car/EnumUtil.h>

void application::PrintCarInfo(const Car& car)
{
    std::cout << "Car: " << (car.IsStarted() ? "started" : "stopped") << '\n';
    std::cout << "Car move direction: " << MoveDirectionToString(car.GetDirection()) << '\n';
    std::cout << "Speed: " << car.GetSpeed() << '\n';
    std::cout << "Gear: " << GearToString(car.GetGear()) << '\n';
}

void application::TurnOnCarEngine(Car& car)
{
    if (car.TurnOnEngine())
    {
        std::cout << "Car has been started\n";
    } else
    {
        std::cout << "Car is already started\n";
    }
}

void application::TurnOffCarEngine(Car& car)
{
    if (car.TurnOffEngine())
    {
        std::cout << "Car has been stopped\n";
    } else
    {
        std::cout << "Car is either already stopped "
                     "or is not stationary at the moment\n";
    }
}

void application::SetCarSpeed(Car& car, int speed)
{
    if (car.SetSpeed(speed))
    {
        std::cout << "Car speed has been set to " << car.GetSpeed() << '\n';
    } else
    {
        std::cout << "Unable to set speed\n";
    }
}

void application::SetCarGear(Car& car, int gear)
{
    if (car.SetGear(gear))
    {
        std::cout << "Gear has been successfully set\n";
    } else
    {
        std::cout << "Unable to set gear\n";
    }
}

void application::PrintCommandList()
{
    std::cout << application::COMMAND_INFO << '\n'
              << application::COMMAND_ENGINE_ON << '\n'
              << application::COMMAND_ENGINE_OFF << '\n'
              << application::COMMAND_SET_GEAR << '\n'
              << application::COMMAND_SET_SPEED << '\n'
              << application::COMMAND_QUIT << '\n';
}