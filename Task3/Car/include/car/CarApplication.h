#pragma once
#include <car/Car.h>

namespace application
{
    constexpr const auto COMMAND_INFO = "Info";
    constexpr const auto COMMAND_ENGINE_ON = "EngineOn";
    constexpr const auto COMMAND_ENGINE_OFF = "EngineOff";
    constexpr const auto COMMAND_SET_GEAR = "SetGear";
    constexpr const auto COMMAND_SET_SPEED = "SetSpeed";
    constexpr const auto COMMAND_QUIT = "Quit";
    constexpr const auto ERR_BAD_INPUT = "Bad input parameter\nTry again";

    void PrintCarInfo(const Car& car);

    void TurnOnCarEngine(Car& car);

    void TurnOffCarEngine(Car& car);

    void SetCarSpeed(Car& car, int speed);

    void SetCarGear(Car& car, int gear);

    void PrintCommandList();

    void PrintBadInput();
}

