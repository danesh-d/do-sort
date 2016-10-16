#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Selection sort.
  class selection_sort : public sort {
    protected:
      void specific_do_sort();

    public:
      selection_sort() {
      }

      ~selection_sort() {
      }
  };
}

#endif /* SELECTION_SORT_H */

