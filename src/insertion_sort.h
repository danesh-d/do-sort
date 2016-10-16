#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Insertion sort.
  class insertion_sort : public sort {
    protected:
      void specific_do_sort();

    public:
      insertion_sort() {
      }

      ~insertion_sort() {
      }
  };
}

#endif /* INSERTION_SORT_H */

