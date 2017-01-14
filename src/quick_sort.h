#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Quick sort implementation.
  template <class T>
  class quick_sort : public sort<T> {
    private:
      LL partition(vector<T>& v, LL left, LL right, bool asc) {
        T piv = v[right];    // Initial guess of the pivot is the last element.
        LL ind = left - 1;

        if (asc) {
          for (LL i = left; i <= right - 1; ++i) {
            if (v[i] <= piv) {
              // Swap all elements smaller than pivot from left to right and
              // then swap the pivot itself when processing of all elements is
              // done.
              swap(sort<T>::v[++ind], sort<T>::v[i]);
            }
          }
        } else {
          for (LL i = left; i <= right - 1; ++i) {
            if (v[i] >= piv) {
              // Swap all elements smaller than pivot from left to right and
              // then swap the pivot itself when processing of all elements is
              // done.
              swap(sort<T>::v[++ind], sort<T>::v[i]);
            }
          }
        }

        // Adjust the place of the pivot and put it in the correct place in the
        // final sorted list.
        swap(sort<T>::v[++ind], sort<T>::v[right]);

        // Return the correct place of the pivot, so the sorting will continue
        // for the two halfs, partitioned by the pivot.
        return ind;
      }

      void qs_partition(vector<T>& v, LL left, LL right) {
        if (left < right) {
          // Partition the array based on the two given bounds.
          LL piv_ind = partition(v, left, right, sort<T>::asc);

          // Sort two separated partitions based on the pivot.
          qs_partition(v, left, piv_ind - 1);
          qs_partition(v, piv_ind + 1, right);
        }
      }

    protected:
      void specific_do_sort() {
        if (sort<T>::size() <= 1) {
          return;
        }

        qs_partition(sort<T>::v, 0, sort<T>::size() - 1);
      }

    public:
      quick_sort() {
      }

      virtual ~quick_sort() {
      }
  };
}

#endif /* QUICK_SORT_H */

