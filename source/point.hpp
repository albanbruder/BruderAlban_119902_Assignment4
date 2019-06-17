#ifndef BUW_POINT_HPP
#define BUW_POINT_HPP

#include <ostream>

struct Point
{
  int x = 0;
  int y = 0;
};

std::ostream& operator<<(std::ostream& os, Point const& p)
{
  os << "(x: " << p.x << ", y: " << p.y << ")";
  return os;
}


#endif