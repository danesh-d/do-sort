#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Merge sort.
  class merge_sort : public sort {
    private:
      vector<int> aux;

      void recursive_msort(vector<int>& v, vector<int>& aux, int low, int high);

    protected:
      void specific_do_sort();

    public:
      merge_sort() {
      }

      ~merge_sort() {
        aux.clear();
      }
  };
}

#endif /* MERGE_SORT_H */

