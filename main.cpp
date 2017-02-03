#include "CppUTest/CommandLineTestRunner.h"
#include "SnakeTest.cpp"
#include "RectangleTest.cpp"
#include "GameTest.cpp"
#include "ui.console/ConsoleGameRunner.cpp"
#include "ui.console/ConsoleSceneCleaner.cpp"

int main(int ac, char** av)
{
    // ConsoleGameRunner gameRunner(
    //     new ConsoleSceneCleaner(),
    //     new Rectangle(Point{1,1}, Point{20,50}),
    //     new Snake(4,4));

    // gameRunner.run();

    return CommandLineTestRunner::RunAllTests(ac, av);
}