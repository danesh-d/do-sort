#ifndef STRAND_SORT_H
#define STRAND_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Strand sort implementation.
  class strand_sort : public sort {
    private:
      list<int> sorted_list;

    protected:
      void specific_do_sort();

    public:
      strand_sort() {
      }

      ~strand_sort() {
      }
  };
}

#endif /* STRNAD_SORT_H */

