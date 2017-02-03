#include "CppUTest/TestHarness.h"
#include <vector>
#include "Rectangle.cpp"

TEST_GROUP(RectangleTest){

};

TEST(RectangleTest, BorderPointsCanBeDetected)
{
    Rectangle rect(Point{2,2}, Point{5,5});
    
    vector<Point> points = rect.getBorderPoints();

    CHECK_EQUAL(12, points.size());
}