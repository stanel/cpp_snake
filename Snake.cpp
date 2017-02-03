#include <vector>
#include "Point.h"
#include "Direction.cpp"

using namespace std;

class Snake
{
  public:
    Snake(int headRowPosition, int headColumnPosition)
    {
        _points.push_back(Point{headRowPosition, headColumnPosition});
    }

    // Snake(Snake& snake)
    // {
        
    // }    

    vector<Point> getPoints()
    {
        return _points;
    }

    void move(Direction direction)
    {
        // get the last point of the snake and put it first

        Point newHeadPosition = getHeadPositionAfterMove(_points[0], direction);

        _points.insert(_points.begin(), newHeadPosition);
        _points.pop_back();
    }

    void grow(Direction direction)
    {
        Point newHeadPosition = getHeadPositionAfterMove(_points[0], direction);
        _points.insert(_points.begin(), newHeadPosition);
    }    

  private:
    vector<Point> _points;

    Point getHeadPositionAfterMove(Point headPosition, Direction direction)
    {
        switch (direction)
        {
        case Direction::West:
            return Point{headPosition.row, headPosition.column - 1};
        case Direction::East:
            return Point{headPosition.row, headPosition.column + 1};
        case Direction::North:
            return Point{headPosition.row - 1, headPosition.column};
        case Direction::South:
            return Point{headPosition.row + 1, headPosition.column};
            
        }
    }
};