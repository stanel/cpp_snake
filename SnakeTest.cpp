#include "CppUTest/TestHarness.h"
#include "Snake.cpp"
#include <vector>

TEST_GROUP(SnakeTest){

    void AssertSimpleSnakeCanBeMoved(Direction direction, int expectedDeltaRow, int expectedDeltaColumn){
        Snake snake(3, 4);

        Point headBeforeMove = snake.getPoints()[0];

        snake.move(direction);

        Point headAfterMove = snake.getPoints()[0];

        CHECK_EQUAL(1, snake.getPoints().size());
        CHECK_EQUAL(headBeforeMove.row + expectedDeltaRow, headAfterMove.row);
        CHECK_EQUAL(headBeforeMove.column + expectedDeltaColumn, headAfterMove.column);
    }

    void AssertSimpleSnakeCanGrow(Direction direction, int expectedDeltaRow, int expectedDeltaColumn){
        Snake snake(3, 4);

        snake.grow(Direction::North);

        vector<Point> points = snake.getPoints();

        CHECK_EQUAL(2, points.size());
        CHECK_EQUAL(3+expectedDeltaRow, points[0].row);
        CHECK_EQUAL(4 + expectedDeltaColumn, points[0].column);
        CHECK_EQUAL(3, points[1].row);
        CHECK_EQUAL(4, points[1].column);        
    }
};

TEST(SnakeTest, AfterCreationTheSnakeContainOnlyTheHead)
{
    Snake snake(3, 4);

    vector<Point> points = snake.getPoints();

    CHECK_EQUAL(1, points.size());
    CHECK_EQUAL(3, points[0].row);
    CHECK_EQUAL(4, points[0].column);
}

TEST(SnakeTest, SnakeCanMoveToTheWest)
{
    AssertSimpleSnakeCanBeMoved(Direction::West, 0, -1);
}

TEST(SnakeTest, SnakeCanMoveToTheEast)
{
    AssertSimpleSnakeCanBeMoved(Direction::East, 0, 1);
}

TEST(SnakeTest, SnakeCanMoveToTheNorth)
{
    AssertSimpleSnakeCanBeMoved(Direction::North, -1, 0);
}

TEST(SnakeTest, SnakeCanMoveToTheSouth)
{
    AssertSimpleSnakeCanBeMoved(Direction::South, 1, 0);
}

TEST(SnakeTest, SnakeCanGrowToNorth)
{
    AssertSimpleSnakeCanGrow(Direction::North, -1, 0);
}

