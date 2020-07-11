#include <iostream>
#include <string>
#include <car/Car.h>
#include <car/CarApplication.h>

inline bool IsConvertibleToInt(const std::string& s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

int main()
{
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
            std::string speedParameter;
            std::cin >> speedParameter;

            if (IsConvertibleToInt(speedParameter))
            {
                application::SetCarSpeed(car, std::stoi(speedParameter));
            }
            else
            {
                application::PrintBadInput();
            }

            continue;
        }
        else if (command == application::COMMAND_SET_GEAR)
        {
            std::string gearParameter;
            std::cin >> gearParameter;

            if (IsConvertibleToInt(gearParameter))
            {
                application::SetCarGear(car, std::stoi(gearParameter));
            }
            else
            {
                application::PrintBadInput();
            }

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
