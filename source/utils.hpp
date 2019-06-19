#ifndef BUW_UTILS_HPP
#define BUW_UTILS_HPP

#include "point.hpp"

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>

namespace buw 
{

  /**
   * The euclidean distance between 2 points.
   */
  float distance(Point const& a, Point const& b)
  {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
  }

  /**
   * Generates a vector of random points, so that none of the points have the same coordinates.
   * @returns vector of random points
   */
  std::vector<Point> generateRandomPoints(unsigned int n, int minX, int maxX, int minY, int maxY)
  {
    srand(time(0));
    std::vector<Point> points;
    while(points.size() < n) {
      int x = minX + std::rand() % (( maxX + 1 ) - minX);
      int y = minY + std::rand() % (( maxY + 1 ) - minY);

      // check if the points already exists
      auto it = std::find_if(std::cbegin(points), std::cend(points), [x, y](Point const& p) {
        return p.x == x && p.y == y;
      });
      if(it == std::cend(points)) {
        points.push_back({ x, y });
      }
    }
    return points;
  }

  /**
   * Comares x-coordinates of two points.
   */
  template <typename T>
  bool lessX(T const& lhs, T const& rhs) {
    return lhs.x < rhs.x;
  }

  /**
   * Comares y-coordinates of two points.
   */
  template <typename T>
  bool lessY(T const& lhs, T const& rhs) {
    return lhs.y < rhs.y;
  }

}

#endif