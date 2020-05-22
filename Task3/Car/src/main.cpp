#include <iostream>
#include <string>
#include <car/Car.h>
#include <car/CarApplication.h>

int main()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");

    Car car;

    std::string command;
    while (command != application::COMMAND_QUIT)
    {
        std::cin >> command;

        if (command == application::COMMAND_INFO)
        {
            application::PrintCarInfo(car);
            continue;
        }
        else if (command == application::COMMAND_ENGINE_ON)
        {
            application::TurnOnCarEngine(car);
            continue;
        }
        else if (command == application::COMMAND_ENGINE_OFF)
        {
            application::TurnOffCarEngine(car);
            continue;
        }
        else if (command == application::COMMAND_SET_SPEED)
        {
            int speedParameter;
            std::cin >> speedParameter;

            application::SetCarSpeed(car, speedParameter);
            continue;
        }
        else if (command == application::COMMAND_SET_GEAR)
        {
            int gearParameter;
            std::cin >> gearParameter;

            application::SetCarGear(car, gearParameter);
            continue;
        }
        else
        {
            std::cout << "Unknown command\nAll commands:\n";
            application::PrintCommandList();
            continue;
        }
    }
}
