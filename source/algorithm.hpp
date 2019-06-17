#ifndef BUW_ALGORITHM_HPP
#define BUW_ALGORITHM_HPP

#include "point.hpp"
#include "quicksort.hpp"
#include "utils.hpp"

#include <math.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace buw 
{

  std::pair<Point, Point> bruteForce(std::vector<Point> const& points)
  {
    std::pair<Point, Point> closestPair;
    float shortestDistance = std::numeric_limits<float>::max();

    for(Point p1 : points) {
      for(Point p2 : points) {
        if(p1.x == p2.x && p1.y == p2.y) {
          continue;
        }

        float d = buw::distance(p1, p2);
        if(d < shortestDistance) {
          shortestDistance = d;
          closestPair = std::make_pair(p1, p2);
        }
      }
    }

    return closestPair;
  }

  std::pair<Point, Point> divideAndConquer(std::vector<Point> const& pointsSortedX, std::vector<Point> const& pointsSortedY)
  {
    unsigned int size = pointsSortedX.size();

    // Base case
    if(size < 4) {
      return bruteForce(pointsSortedX);
    }

    unsigned int median = (size / 2);
    int medianX = pointsSortedX[median].x;

    std::vector<Point> leftX;
    for(unsigned int i=0; i<median; i++) {
      leftX.push_back(pointsSortedX[i]);
    }

    std::vector<Point> rightX;
    for(unsigned int i=median; i<size; i++) {
      rightX.push_back(pointsSortedX[i]);
    }

    std::vector<Point> leftY;
    std::vector<Point> rightY;

    for(Point p : pointsSortedY) {
      if(p.x < medianX) {
        leftY.push_back(p);
      } else {
        rightY.push_back(p);
      }
    }

    auto leftPair  = divideAndConquer(leftX, leftY);
    auto rightPair = divideAndConquer(rightX, rightY);

    float dl = buw::distance(leftPair.first, leftPair.second);
    float dr = buw::distance(rightPair.first, rightPair.second);
    float d = std::min(dl, dr);
    std::pair<Point, Point> bestPair = (d == dl ? leftPair : rightPair);

    /**
     * closest strip pair subroutine
     */

    std::vector<Point> stripY;
    for(Point p : pointsSortedY) {
      if(p.x >= (medianX-d) && p.x <= (medianX+d)) {
        stripY.push_back(p);
      }
    }

    for(unsigned int i=0; i<stripY.size(); i++) {
      for(unsigned int j=i+1; j<stripY.size() && (stripY[j].y - stripY[i].y) < d; j++) {
        float d2 = buw::distance(stripY[i], stripY[j]);
        if(d2 < d) {
          bestPair = std::make_pair(stripY[i], stripY[j]);
          d = d2;
        }
      }
    }

    return bestPair;
  }

  std::pair<Point, Point> closestPair(std::vector<Point> const& points)
  {
    std::vector<Point> pointsSortedX{points};
    buw::quicksort(std::begin(pointsSortedX), std::end(pointsSortedX), buw::lessX<Point>);

    std::vector<Point> pointsSortedY{points};
    buw::quicksort(std::begin(pointsSortedY), std::end(pointsSortedY), buw::lessY<Point>);

    return buw::divideAndConquer(pointsSortedX, pointsSortedY);
  }

}

#endif