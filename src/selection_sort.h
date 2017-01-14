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
        LL n = sort<T>::size();

        if (n <= 1) {
          return;
        }

        if (sort<T>::asc) {
          // The data will be sorted in ascending order.
          for (LL i = 0; i < n; ++i) {
            T key = sort<T>::v[i];
            LL ind = i;

            // From the current element to the end of the list, find the minimum
            // value and swap it with the current element.
            for (LL j = i  + 1; j < n; ++j) {
              if (sort<T>::v[j] < key) {
                key = sort<T>::v[j];
                ind = j;
              }
            }

            if (ind != i) {
              swap(sort<T>::v[i], sort<T>::v[ind]);
            }
          }
        } else {
          // The data will be sorted in descending order.
          for (LL i = 0; i < n; ++i) {
            T key = sort<T>::v[i];
            LL ind = i;

            // From the current element to the end of the list, find the minimum
            // value and swap it with the current element.
            for (LL j = i  + 1; j < n; ++j) {
              if (sort<T>::v[j] > key) {
                key = sort<T>::v[j];
                ind = j;
              }
            }

            if (ind != i) {
              swap(sort<T>::v[i], sort<T>::v[ind]);
            }
          }
        }
      }

    public:
      selection_sort() {
      }

      virtual ~selection_sort() {
      }
  };
}

#endif /* SELECTION_SORT_H */

