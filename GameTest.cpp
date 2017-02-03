#include "CppUTest/TestHarness.h"
#include "Game.cpp"

TEST_GROUP(GameTest){

};

TEST(GameTest, GameCanBeCreated)
{
    // v1: 3 points as parameters
    // based on that the Snake and the worldMap is created

    // v2:
    // it will receive the Snake and worldMap as parameters

    Game game;



    // Rectangle rect(Point{2,2}, Point{5,5});
    
    // vector<Point> points = rect.getBorderPoints();

    CHECK_EQUAL(1, 2);
}