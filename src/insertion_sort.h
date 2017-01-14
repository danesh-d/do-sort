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
        LL n = sort<T>::size();

        if (n <= 1) {
          return;
        }

        if (sort<T>::asc) {
          // Sort the data in ascending order.
          for (LL i = 1; i < n; i++) {
            T key = sort<T>::v[i];
            LL j = i - 1;

            while ((j >= 0) && (sort<T>::v[j] > key)) {
              sort<T>::v[j + 1] = sort<T>::v[j];
              --j;
            }

            sort<T>::v[j + 1] = key;
          }
        } else {
          // Sort the data in descending order.
          for (LL i = 1; i < n; i++) {
            T key = sort<T>::v[i];
            LL j = i - 1;

            while ((j >= 0) && (sort<T>::v[j] < key)) {
              sort<T>::v[j + 1] = sort<T>::v[j];
              --j;
            }

            sort<T>::v[j + 1] = key;
          }
        }
      }

    public:
      insertion_sort() {
      }

      virtual ~insertion_sort() {
      }
  };
}

#endif /* INSERTION_SORT_H */

