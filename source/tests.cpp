#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "quicksort.hpp"
#include <vector>

TEST_CASE("quicksort", "[sort]")
{
  std::vector<int> v{1, 2, -3, 5, 10, 3};
  buw::quicksort(std::begin(v), std::end(v), [](int lhs, int rhs) { return lhs < rhs; });
  REQUIRE(std::is_sorted(std::cbegin(v), std::cend(v)));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
