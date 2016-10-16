#ifndef STRAND_SORT_H
#define STRAND_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Strand sort implementation.
  class strand_sort : public sort {
    private:
      // This vector indicates which element has been deleted from the main
      // vector, by setting the deleted element's flag to false.
      vector<bool> flags;
      vector<int> sub_v;
      vector<int> sorted_v;
      vector<int> aux;

    protected:
      void specific_do_sort();

    public:
      strand_sort() {
      }

      ~strand_sort() {
        flags.clear();
        sub_v.clear();
        sorted_v.clear();
        aux.clear();
      }
  };
}

#endif /* STRNAD_SORT_H */

