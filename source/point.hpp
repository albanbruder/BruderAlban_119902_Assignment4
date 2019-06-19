#ifndef BUW_POINT_HPP
#define BUW_POINT_HPP

#include <ostream>

/**
 * Simple representation of a point.
 */
struct Point
{
  int x = 0;
  int y = 0;
};

/**
 * This helps to print a point to the standard output.
 */
std::ostream& operator<<(std::ostream& os, Point const& p)
{
  os << "(x: " << p.x << ", y: " << p.y << ")";
  return os;
}


#endif