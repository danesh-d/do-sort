#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Quick sort implementation.
  class quick_sort : public sort {
    private:
      void qsort_partition(vector<int>& v, size_t left, size_t right);

    protected:
      void specific_do_sort();

    public:
      quick_sort() {
      }

      ~quick_sort() {
      }
  };
}

#endif /* QUICK_SORT_H */

