#include "../src/vector_process.h"
#include "catch_runner.h"

using namespace std;

TEST_CASE("Vector with max value as 0 throws exception")
{
    auto vectors = GENERATE(
            vector<double> { -2, -1, 0 },
            vector<double> { 0 },
            vector<double> { -999, 0 },
            vector<double> { -100, -50, 0 }
    );

    REQUIRE_THROWS_AS(DivideElementsOnHalvedMax(vectors), overflow_error);
}

TEST_CASE("Empty vector results in empty vector")
{
    vector<double> emptyVec;
    DivideElementsOnHalvedMax(emptyVec);

    REQUIRE(emptyVec.empty());
}

TEST_CASE("{0, 1} vector should become {0, 2}")
{
    vector<double> test { 0, 1 };
    vector<double> expected { 0, 2 };

    DivideElementsOnHalvedMax(test);

    REQUIRE(test == expected);
}

TEST_CASE("{1, 1} vector should become {2, 2}")
{
    vector<double> test { 1, 1 };
    vector<double> expected { 2, 2 };

    DivideElementsOnHalvedMax(test);

    REQUIRE(test == expected);
}

TEST_CASE("Vector with single value: { 1 } -> { 2 }")
{
    vector<double> test { 1 };
    vector<double> expected { 2 };

    DivideElementsOnHalvedMax(test);

    REQUIRE(test == expected);
}

TEST_CASE("1 to 5 vector")
{
    vector<double> test { 1, 2, 3, 4, 5 };
    vector<double> expected { 1 / 2.5,
                              2 / 2.5,
                              3 / 2.5,
                              4 / 2.5,
                              5 / 2.5 };

    DivideElementsOnHalvedMax(test);

    REQUIRE(test == expected);
}