#include <iostream>
#include <vector>
#include "../ui/SceneCleaner.h"

const char BorderPoint = '#';
const char SnakePoint = '*';
const char FoodPoint = '$';
const char EmptyPoint = ' ';

using namespace std;

/**
Runs the game by using a console. Different other runners will be built to show the same game in different ways.
Implement an interface. How can I test that a method has been called? Do we have something like NSubstitute
*/
class ConsoleGameRunner
{
public:
  ConsoleGameRunner(
      SceneCleaner *cleaner,
      Rectangle *rectangle,
      Snake *snake)
  {
    _cleaner = cleaner;
    _rectangle = rectangle;
    _snake = snake;
  }

  void run()
  {
    int numberOfFramesToShow = 20;
    int frameCounter = 0;

    while (frameCounter <= numberOfFramesToShow)
    {
      clean();
      display();

      _snake->grow(Direction::East);

      // wait a millisecond
      Pause();

      frameCounter++;
    }

    // while (true) // this is the game loop
    // {

    //   // move the snake

    //   // check the new position of the snake. It was a valid move, continue; otherwise finish and display a message

    //   // wait a couple of milliseconds
    // }
  }

private:
  SceneCleaner *_cleaner;
  Rectangle *_rectangle;
  Snake *_snake;

  void clean()
  {
    _cleaner->clean();
  }

  void display()
  {
    // ConsoleGameMap or ConsoleScene
    // can be created based on an interface
    // based on an interface

    vector<string> scene = buildScene();

    vector<Point> borderPoints = _rectangle->getBorderPoints();

    for (Point point : borderPoints)
    {
      scene[point.row][point.column] = BorderPoint;
    }

    for (Point point : _snake->getPoints())
    {
      scene[point.row][point.column] = SnakePoint;
    }

    for (string line : scene)
    {
      cout << line << endl;
    }
  }

  vector<string> buildScene()
  {
    vector<string> scene;

    for (int j = 0; j <= _rectangle->getBottomRightRow(); j++)
    {
      string line;

      for (int i = 0; i <= _rectangle->getBottomRightColumn(); i++)
      {
        line.push_back(EmptyPoint);
      }

      scene.push_back(line);
    }

    return scene;
  }

  void Pause(){
    int clockTicks = clock();

    while(true){      
      int deltaClockTicks = clock() - clockTicks;

      if(deltaClockTicks / CLOCKS_PER_SEC > 0.10)
        break;
    }
  }
};