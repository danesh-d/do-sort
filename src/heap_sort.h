#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Heap sort.
  template <class T>
  class heap_sort : public sort<T> {
    protected:
      void specific_do_sort() {
        LL n = sort<T>::size();

        if (n <= 1) {
          return;
        }

        // Build the heap from the input data. The heap will be built in place
        // by re-arranging the input data.
        for (LL i = n / 2 - 1; i >= 0; --i) {
          sort<T>::heapify(sort<T>::v, n, i, sort<T>::asc);
        }

        // Extract each element from the heap and set as local root. Then move
        // the local root to the end of the heap and the heapy the reduce heap
        // starting from the local root.
        for (LL i = n - 1; i >= 0; --i) {
          swap(sort<T>::v[0], sort<T>::v[i]);
          sort<T>::heapify(sort<T>::v, i, 0, sort<T>::asc);
        }
      }

    public:
      heap_sort() {
      }

      virtual ~heap_sort() {
      }
  };
}

#endif /* HEAP_SORT_H */

