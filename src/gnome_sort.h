#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "do_sort.h"

using namespace std;

// Note: This method can be highly ineffective.

namespace do_sort {
  // --- Gnome sort.
  template <class T>
  class gnome_sort : public sort<T> {
    private:
      void gnome_sort_bounded(LL upper_bound, bool asc) {
        LL pos = upper_bound;

        if (asc) {
          // Sort the data in ascending order.
          while ((pos > 0) && (sort<T>::v[pos - 1] > sort<T>::v[pos])) {
            swap(sort<T>::v[pos], sort<T>::v[pos - 1]);
            --pos;
          }
        } else {
          // Sort the data in descending order.
          while ((pos > 0) && (sort<T>::v[pos - 1] < sort<T>::v[pos])) {
            swap(sort<T>::v[pos], sort<T>::v[pos - 1]);
            --pos;
          }
        }
      }

    protected:
      void specific_do_sort() {
        LL n = sort<T>::size();

        if (n <= 1) {
          return;
        }

        for (LL i = 1; i < n; ++i) {
          gnome_sort_bounded(i, sort<T>::asc);
        }
      }

    public:
      gnome_sort() {
      }

      virtual ~gnome_sort() {
      }
  };
}

#endif /* GNOME_SORT_H */

