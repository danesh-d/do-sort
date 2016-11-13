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
          while ((pos > 0) && (this->v[pos - 1] > this->v[pos])) {
            swap(this->v[pos], this->v[pos - 1]);
            --pos;
          }
        } else {
          // Sort the data in descending order.
          while ((pos > 0) && (this->v[pos - 1] < this->v[pos])) {
            swap(this->v[pos], this->v[pos - 1]);
            --pos;
          }
        }
      }

    protected:
      void specific_do_sort() {
        LL n = this->size();

        if (n <= 1) {
          return;
        }

        for (LL i = 1; i < n; ++i) {
          gnome_sort_bounded(i, this->asc);
        }
      }

    public:
      gnome_sort() {
      }

      ~gnome_sort() {
      }
  };
}

#endif /* GNOME_SORT_H */

