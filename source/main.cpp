#include "point.hpp"
#include "quicksort.hpp"
#include "algorithm.hpp"
#include "utils.hpp"

#include "cxxopts.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace buw;

int main(int argc, char *argv[])
{
  cxxopts::Options options(argv[0], " - Divide & Conquer Closest Points");
  options
    .positional_help("[optional args]")
    .show_positional_help();

  options.add_options()
    ("h,help", "give this help list")
    ("d,debug", "Enable debugging (will print all generated numbers)")
    ("n,num", "number of points to generate", cxxopts::value<int>()->default_value("50"))
    ("x,minX", "minimum x value", cxxopts::value<int>()->default_value("-100"))
    ("X,maxX", "maximum x value", cxxopts::value<int>()->default_value("100"))
    ("y,minY", "minimum y value", cxxopts::value<int>()->default_value("-100"))
    ("Y,maxY", "maximum y value", cxxopts::value<int>()->default_value("100"));

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help({"", "Group"}) << std::endl;
    exit(0);
  }

  int minX = result["minX"].as<int>();
  int maxX = result["maxX"].as<int>();
  int minY = result["minY"].as<int>();
  int maxY = result["maxY"].as<int>();

  int n = result["num"].as<int>();

  std::vector<Point> points = generateRandomPoints(n, minX, maxX, minY, maxY);

  std::cout << "Generated " << points.size() << " random points between (x: " << minX << ", y: " << minY << ") and (x: " << maxX << ", y: " << maxY << ")" << std::endl;
  std::cout << std::endl;

  if(result.count("debug")) {
    for(Point point : points) {
      std::cout << std::left  << std::setw(2) << std::setfill(' ') << "x:";
      std::cout << std::right << std::setw(4) << std::setfill(' ') << point.x << ",";
      std::cout << std::left  << std::setw(3) << std::setfill(' ') << "  y:";
      std::cout << std::right << std::setw(4) << std::setfill(' ') << point.y << std::endl;
    }
    std::cout << std::endl;
  }

  auto start1 = std::chrono::high_resolution_clock::now();
  std::pair<Point, Point> cp = closestPair(points);
  auto finish1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed1 = finish1 - start1;

  std::cout << "Result using Divide & Conquer algorithm:" << std::endl;
  std::cout << "Closest pair: " << cp.first << " -- " << cp.second << std::endl;
  std::cout << "Distance: " << distance(cp.first, cp.second) << std::endl;
  std::cout << "Elapsed time: " << elapsed1.count() << "s" << std::endl;
  std::cout << std::endl;

  auto start2 = std::chrono::high_resolution_clock::now();
  std::pair<Point, Point> bf = bruteForce(points);
  auto finish2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed2 = finish2 - start2;

  std::cout << "Result using naive algorithm:" << std::endl;
  std::cout << "Closest pair: " << bf.first << " -- " << bf.second << std::endl;
  std::cout << "Distance: " << distance(bf.first, bf.second) << std::endl;
  std::cout << "Elapsed time: " << elapsed2.count() << "s" << std::endl;
  std::cout << std::endl;

  if(distance(cp.first, cp.second) == distance(bf.first, bf.second)) {
    std::cout << "Result is CORRECT." << std::endl;
  } else {
    std::cout << "Result is INCORRECT." << std::endl;
  }

  return 0;
}
