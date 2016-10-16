#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Bubble sort.
  class bubble_sort : public sort {
    protected:
      void specific_do_sort();

    public:
      bubble_sort() {
      }

      ~bubble_sort() {
      }
  };
}

#endif /* BUBBLE_SORT_H */

