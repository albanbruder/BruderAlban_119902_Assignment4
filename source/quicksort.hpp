#ifndef BUW_SORT_HPP
#define BUW_SORT_HPP

#include <algorithm>

namespace buw
{

  template <typename Iterator, typename Compare>
  Iterator partition(Iterator const& first, Iterator const& last, Compare const& comp)
  {
    Iterator p      = first;
    Iterator pivot  = last - 1;

    for(Iterator it = first; it != pivot; it++) {
      if(comp(*it, *pivot)) {
        std::iter_swap(it, p);
        p++;
      }
    }

    std::iter_swap(p, pivot);
    return p;
  }

  template <typename Iterator, typename Compare>
  void quicksort(Iterator const& first, Iterator const& last, Compare const& comp)
  {
    if(std::distance(first, last) > 1) {
      Iterator pivot = buw::partition(first, last, comp);
      buw::quicksort(first,   pivot, comp);
      buw::quicksort(pivot+1, last,  comp);
    }
  }

}

#endif