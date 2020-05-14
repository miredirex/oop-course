#include <iostream>
#include <string>
#include <car/Car.h>

const char* COMMAND_INFO = "Info";
const char* COMMAND_ENGINE_ON = "EngineOn";
const char* COMMAND_ENGINE_OFF = "EngineOff";
const char* COMMAND_SET_GEAR = "SetGear";
const char* COMMAND_SET_SPEED = "SetSpeed";

const char* COMMAND_QUIT = "Quit";

int main()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");

    Car car;

    std::string command;
    while (command != COMMAND_QUIT)
    {
        std::cin >> command;

        if (command == COMMAND_INFO)
        {
            std::cout << "Двигатель автомобиля: " << (car.IsStarted() ? "включён" : "выключен") << '\n';
            std::cout << "Автомобиль ";
            switch (car.GetDirection())
            {
                case MoveDirection::STILL:
                    std::cout << "стоит на месте\n";
                    break;
                case MoveDirection::FORWARD:
                    std::cout << "движется вперёд.\n";
                    break;
                case MoveDirection::BACKWARD:
                    std::cout << "движется назад.\n";
                    break;
            }
            std::cout << "Скорость: " << car.GetSpeed() << '\n';
            std::string gearName;
            switch (car.GetGear())
            {
                case Gear::REVERSE:
                    gearName = "задняя";
                    break;
                case Gear::NEUTRAL:
                    gearName = "нейтральная";
                    break;
                case Gear::FIRST:
                    gearName = "первая";
                    break;
                case Gear::SECOND:
                    gearName = "вторая";
                    break;
                case Gear::THIRD:
                    gearName = "третья";
                    break;
                case Gear::FOURTH:
                    gearName = "четвертая";
                    break;
                case Gear::FIFTH:
                    gearName = "пятая";
                    break;
            }
            std::cout << "Передача: " << gearName << '\n';
            continue;
        }

        if (command == COMMAND_ENGINE_ON)
        {
            if (car.TurnOnEngine())
            {
                std::cout << "Двигатель был включен\n";
            } else
            {
                std::cout << "Двигатель уже включен\n";
            }
            continue;
        }

        if (command == COMMAND_ENGINE_OFF)
        {
            if (car.TurnOffEngine())
            {
                std::cout << "Двигатель был выключен\n";
            } else
            {
                std::cout << "Двигатель либо уже был выключен, либо машина находится "
                             "в движении.\n";
            }
            continue;
        }

        if (command == COMMAND_SET_SPEED)
        {
            int speedParameter;
            std::cin >> speedParameter;

            if (car.SetSpeed(speedParameter))
            {
                std::cout << "Теперь автомобиль двигается со скоростью " << car.GetSpeed() << '\n';
            } else
            {
                std::cout << "Не удалось выставить скорость.\n";
            }
            continue;
        }

        if (command == COMMAND_SET_GEAR)
        {
            int gearParameter;
            std::cin >> gearParameter;

            if (car.SetGear(gearParameter))
            {
                std::cout << "Передача была успешно переключена\n";
            } else
            {
                std::cout << "Не удалось переключить передачу\n";
            }
            continue;
        }
    }
}
