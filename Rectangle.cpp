#include <vector>
#include "Point.h"

class Rectangle
{
public:
  Rectangle(Point leftTopPoint, Point rightBottomPoint)
  {
    _leftTopPoint = leftTopPoint;
    _rightBottomPoint = rightBottomPoint;
  }

  vector<Point> getBorderPoints()
  {
    vector<Point> points;

    // top border
    for (int i = _leftTopPoint.column; i <= _rightBottomPoint.column; i++)
    {
      points.push_back(Point{_leftTopPoint.row, i});
    }

    // bottom border
    for (int i = _leftTopPoint.column; i <= _rightBottomPoint.column; i++)
    {
      points.push_back(Point{_rightBottomPoint.row, i});
    }

    // left border
    for (int j = _leftTopPoint.row + 1; j < _rightBottomPoint.row; j++)
    {
      points.push_back(Point{j, _leftTopPoint.column});
    }

    // right border
    for (int j = _leftTopPoint.row + 1; j < _rightBottomPoint.row; j++)
    {
      points.push_back(Point{j, _rightBottomPoint.column});
    }

    return points;
  }

  int getBottomRightColumn(){
    return _rightBottomPoint.column;
  }

  int getBottomRightRow(){
    return _rightBottomPoint.row;
  }  

private:
  Point _leftTopPoint;
  Point _rightBottomPoint;
};