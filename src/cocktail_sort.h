#ifndef COCKTAIL_SORT_H
#define COCKTAIL_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Cocktail sort.
  template <class T>
  class cocktail_sort : public sort<T> {
    protected:
      void specific_do_sort() {
        LL n = sort<T>::size();

        if (n <= 1) {
          return;
        }

        LL upper_bound = n - 1;
        LL lower_bound = 0;
        bool swapped = true;

        if (sort<T>::asc) {
          // Sort the data in ascending order.
          while (swapped) {
            swapped = false;

            LL tmp = 0;

            for (LL i = 0; i < upper_bound; ++i) {
              if (sort<T>::v[i] > sort<T>::v[i + 1]) {
                swap(sort<T>::v[i], sort<T>::v[i + 1]);
                swapped = true;

                // Save the place of last swap. The process in the next round
                // will continue up to this point since the rest of the list
                // will be remain sorted if no swap has happened.
                tmp = i + 1;
              }
            }

            // Shrink the range of the sorting since it is needed to continue
            // the process up to the last non-sorted element in the list.
            upper_bound = tmp - 1;

            if (!swapped) {
              // No swap has been done, so no reverse check is needed and the
              // loop will be terminated.
              break;
            }

            for (LL i = upper_bound; i >= 0; --i) {
              if (sort<T>::v[i] > sort<T>::v[i + 1]) {
                swap(sort<T>::v[i], sort<T>::v[i + 1]);
                swapped = true;

                // Save the place of last swap. The process in the next round
                // will start from this point since the rest of the list will be
                // remain sorted if no swap has happened.
                tmp = i + 1;
              }
            }

            lower_bound = tmp;
          } // End for the main while.
        } else {
          // Sort the data in descending order.
          while (swapped) {
            swapped = false;

            LL tmp = 0;

            for (LL i = 0; i < upper_bound; ++i) {
              if (sort<T>::v[i] < sort<T>::v[i + 1]) {
                swap(sort<T>::v[i], sort<T>::v[i + 1]);
                swapped = true;

                // Save the place of last swap. The process in the next round
                // will continue up to this point since the rest of the list
                // will be remain sorted if no swap has happened.
                tmp = i + 1;
              }
            }

            // Shrink the range of the sorting since it is needed to continue
            // the process up to the last non-sorted element in the list.
            upper_bound = tmp - 1;

            if (!swapped) {
              // No swap has been done, so no reverse check is needed and the
              // loop will be terminated.
              break;
            }

            for (LL i = upper_bound; i >= 0; --i) {
              if (sort<T>::v[i] < sort<T>::v[i + 1]) {
                swap(sort<T>::v[i], sort<T>::v[i + 1]);
                swapped = true;

                // Save the place of last swap. The process in the next round
                // will start from this point since the rest of the list will be
                // remain sorted if no swap has happened.
                tmp = i + 1;
              }
            }

            lower_bound = tmp;
          } // End for the main while.
        }
      }

    public:
      cocktail_sort() {
      }

      virtual ~cocktail_sort() {
      }
  };
}

#endif /* COCKTAIL_SORT_H */

