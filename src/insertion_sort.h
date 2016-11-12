#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Insertion sort.
  template <class T>
  class insertion_sort : public sort<T> {
    protected:
      void specific_do_sort() {
        LL n = this->size();

        if (n <= 1) {
          return;
        }

        for (LL i = 1; i < n; i++) {
          T key = this->v[i];
          LL j = i - 1;

          while ((j >= 0) && (this->v[j] > key)) {
            this->v[j + 1] = this->v[j];
            --j;
          }

          this->v[j + 1] = key;
        }
      }

    public:
      insertion_sort() {
      }

      ~insertion_sort() {
      }
  };
}

#endif /* INSERTION_SORT_H */

