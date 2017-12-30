#ifndef COMB_SORT_H
#define COMB_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Heap sort.
  template <class T>
  class comb_sort : public sort<T> {
    private:
      float shrinkFactor;

      int nextGap(int gap) {
        gap = (int)(gap / shrinkFactor);
        return gap < 1 ? 1 : gap;
      }

    protected:
      void specific_do_sort() {
        LL n = sort<T>::size();

        if (n <= 1) {
          return;
        }

        LL gap = n;
        bool swapped = true;

        // Loop over the input data until the gap is not equal to one and at
        // at least one swap has been done during the last traverse.
        while (gap != 1  || swapped) {
          gap = nextGap(gap);

          swapped = false;

          // Sort the data within the current gap.
          for (LL i = 0; i < n - gap; ++i) {
            if (sort<T>::asc) {
              if (sort<T>::v[i] > sort<T>::v[i + gap]) {
                swap(sort<T>::v[i], sort<T>::v[i + gap]);
                swapped = true;
              }
            } else {
              if (sort<T>::v[i] < sort<T>::v[i + gap]) {
                swap(sort<T>::v[i], sort<T>::v[i + gap]);
                swapped = true;
              }
            }
          }
        }
      }

    public:
      comb_sort() {
        // This sorting algorithm is in fact an improvement to Bubble sort where
        // inversions are removed one by one. In this algorithm a gap is used
        // which is more than 1 (unlike Bubble sort with gap of size 1) so at
        // each swap more then one inversion is removed. The gap size is reduced
        // in each iteration by factor of 1.3 which is proven to be the best
        // constant.
        shrinkFactor = 1.3;
      }

      virtual ~comb_sort() {
      }
  };
}

#endif /* COMB_SORT_H */

