#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Merge sort.
  template <class T>
  class merge_sort : public sort<T> {
    private:
      vector<T> aux;

      void recursive_msort(vector<T>& v,
                           vector<T>& aux,
                           LL low,
                           LL high,
                           bool asc) {
        if (low < high) {
          LL mid = (low + high) >> 1;

          // The original list is partitioned at the middle and each part will
          // be sorted separately while each sub-list will be divided and sorted
          // recursively until the list consists of two elements and then they
          // wil be merged.
          recursive_msort(v, aux, low, mid, asc);
          recursive_msort(v, aux, mid + 1, high, asc);

          // Both lists partitioned at the middle have been sorted and now will
          // be merged while the order will be preserved.
          sort<T>::merge(v, aux, low, mid + 1, high, asc);
        }
      }

    protected:
      void specific_do_sort() {
        LL n = sort<T>::size();

        if (n <= 1) {
          return;
        }

        aux.resize(n);
        recursive_msort(sort<T>::v, aux, 0, n - 1, sort<T>::asc);
        aux.clear();
      }

    public:
      merge_sort() {
      }

      virtual ~merge_sort() {
        aux.clear();
      }
  };
}

#endif /* MERGE_SORT_H */

