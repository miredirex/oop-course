#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <car/Car.h>

using namespace std;

void REQUIRE_CarMaxAccelerate(Car& car)
{
    REQUIRE(car.SetGear(Gear::FIRST));
    REQUIRE(car.SetSpeed(20));
    REQUIRE(car.SetGear(Gear::SECOND));
    REQUIRE(car.SetSpeed(30));
    REQUIRE(car.SetGear(Gear::THIRD));
    REQUIRE(car.SetSpeed(40));
    REQUIRE(car.SetGear(Gear::FOURTH));
    REQUIRE(car.SetSpeed(50));
    REQUIRE(car.SetGear(Gear::FIFTH));
}

TEST_CASE("Car Engine On/Off")
{
    Car car;
    car.TurnOnEngine(); // Always started in this test case

    SECTION("Default car instance starts successfully")
    {
        REQUIRE(car.IsStarted());
    }

    SECTION("Already running car can't be started again")
    {
        REQUIRE_FALSE(car.TurnOnEngine());
    }

    SECTION("Already turned off car can't be turned off again")
    {
        REQUIRE(car.TurnOffEngine());
        REQUIRE_FALSE(car.TurnOffEngine());
    }

    SECTION("Car can only be turned off if speed is 0 and gear is set to neutral")
    {
        REQUIRE(car.IsStarted());

        // Move
        REQUIRE(car.SetGear(Gear::FIRST));
        REQUIRE(car.SetSpeed(5));
        REQUIRE(car.GetDirection() != MoveDirection::STILL);
        // Check
        REQUIRE_FALSE(car.TurnOffEngine());

        // Stop
        REQUIRE(car.SetSpeed(0));
        // Check
        REQUIRE_FALSE(car.TurnOffEngine());

        // Set Neutral
        REQUIRE(car.SetGear(Gear::NEUTRAL));
        // Check
        REQUIRE(car.TurnOffEngine());
        // Confirm
        REQUIRE_FALSE(car.IsStarted());
    }
}

TEST_CASE("Gears and ranges")
{
    Car car;

    SECTION("Set gear won't work if the car is not started")
    {
        REQUIRE_FALSE(car.IsStarted());

        REQUIRE(car.SetGear(Gear::NEUTRAL)); // Switching to the same gear is ok
        REQUIRE_FALSE(car.SetGear(Gear::FIFTH));

        REQUIRE_FALSE(car.SetGear(Gear::REVERSE));
    }

    SECTION("Speed can't be raised on neutral gear")
    {
        REQUIRE(car.TurnOnEngine());

        REQUIRE(car.GetGear() == Gear::NEUTRAL);
        REQUIRE_FALSE(car.SetSpeed(5));
    }

    SECTION("It should be possible to switch from any gear to neutral")
    {
        REQUIRE(car.TurnOnEngine());

        // Accelerate
        REQUIRE(car.SetGear(Gear::FIRST));
        REQUIRE(car.SetSpeed(20));
        REQUIRE(car.SetGear(Gear::SECOND));
        REQUIRE(car.SetSpeed(30));
        REQUIRE(car.SetGear(Gear::THIRD));
        REQUIRE(car.SetSpeed(40));
        REQUIRE(car.SetGear(Gear::FOURTH));

        // Check
        REQUIRE(car.SetGear(Gear::NEUTRAL));
        REQUIRE(car.SetSpeed(0));
    }

    SECTION("Speed can't go above maximum, should return false")
    {
        REQUIRE(car.TurnOnEngine());

        // Accelerate
        REQUIRE_CarMaxAccelerate(car);

        const int MAX_AVAILABLE_CAR_SPEED = 150;

        REQUIRE(car.SetSpeed(MAX_AVAILABLE_CAR_SPEED));

        // Check
        REQUIRE_FALSE(car.SetSpeed(MAX_AVAILABLE_CAR_SPEED + 1));
        REQUIRE_FALSE(car.SetSpeed(200));
    }

    SECTION("Setting invalid numeric gear should return false")
    {
        REQUIRE(car.TurnOnEngine());
        REQUIRE(car.SetGear(-1));

        // Lower bound check
        REQUIRE_FALSE(car.SetGear(-2));

        REQUIRE_CarMaxAccelerate(car);

        // Upper bound check
        REQUIRE_FALSE(car.SetGear(6));
        REQUIRE_FALSE(car.SetGear(7));
        REQUIRE_FALSE(car.SetGear(100));
    }

    SECTION("Setting any gear if moving backwards should be impossible")
    {
        REQUIRE(car.TurnOnEngine());

        REQUIRE(car.SetGear(-1));
        REQUIRE(car.SetSpeed(5));
        REQUIRE(car.GetDirection() == MoveDirection::BACKWARD);

        REQUIRE_FALSE(car.SetGear(0));
        REQUIRE_FALSE(car.SetGear(1));
    }
}