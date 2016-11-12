#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Selection sort.
  template <class T>
  class selection_sort : public sort<T> {
    protected:
      void specific_do_sort() {
        LL n = this->size();

        if (n <= 1) {
          return;
        }

        // Traverse the list until all elements are sorted.
        for (LL i = 0; i < n; ++i) {
          T min_val = this->v[i];
          LL ind = i;

          // From the current element to the end of the list, find the minimum
          // value and swap it with the current element.
          for (LL j = i  + 1; j < n; ++j) {
            if (this->v[j] < min_val) {
              min_val = this->v[j];
              ind = j;
            }
          }

          if (ind != i) {
            swap(this->v[i], this->v[ind]);
          }
        }
      }

    public:
      selection_sort() {
      }

      ~selection_sort() {
      }
  };
}

#endif /* SELECTION_SORT_H */

