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
      void gnome_sort_bounded(LL upper_bound) {
        LL pos = upper_bound;

        while ((pos > 0) && (this->v[pos - 1] > this->v[pos])) {
          this->swap(this->v, pos, pos - 1);
          --pos;
        }
      }

    protected:
      void specific_do_sort() {
        LL n = this->size();

        if (n <= 1) {
          return;
        }

        for (LL i = 1; i < n; ++i) {
          gnome_sort_bounded(i);
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

