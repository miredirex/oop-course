#include "../src/vector_process.h"
#include "catch_runner.h"

using namespace std;

TEST_CASE("Vector with max value of 0 throws exception")
{
    auto vectors = GENERATE(
            vector<double> { -2, -1, 0 },
            vector<double> { 0 },
            vector<double> { -999, 0 },
            vector<double> { -100, -50, 0 }
    );

    REQUIRE_THROWS_AS(DivideElementsByHalfMax(vectors), overflow_error);
}

TEST_CASE("Empty vector results in empty vector")
{
    vector<double> emptyVec;
    DivideElementsByHalfMax(emptyVec);

    REQUIRE(emptyVec.empty());
}

TEST_CASE("Max value in vector of same values equals any value")
{
    vector<double> test { 3, 3, 3, 3, 3, 3 };
    vector<double> expected { 2/1.5, 2/1.5, 2/1.5, 2/1.5, 2/1.5, 2/1.5 };

    DivideElementsByHalfMax(test);

    REQUIRE(test == expected);
}

TEST_CASE("Max value in vector of size 1 should equal to the first element")
{
    vector<double> test { 1 };
    vector<double> expected { 2 };

    DivideElementsByHalfMax(test);

    REQUIRE(test == expected);
}

TEST_CASE("Max value in vector with values in ascending order should equal to the last element")
{
    vector<double> test { 1, 2, 3, 4, 5 };
    vector<double> expected { 1 / 2.5,
                              2 / 2.5,
                              3 / 2.5,
                              4 / 2.5,
                              5 / 2.5 };

    DivideElementsByHalfMax(test);

    REQUIRE(test == expected);
}