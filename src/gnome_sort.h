#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "do_sort.h"

using namespace std;

// Note: This method can be highly ineffective.

namespace do_sort {
  // --- Gnome sort.
  class gnome_sort : public sort {
    protected:
      void specific_do_sort();

    public:
      gnome_sort() {
      }

      ~gnome_sort() {
      }
  };
}

#endif /* GNOME_SORT_H */

