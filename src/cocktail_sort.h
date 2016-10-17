#ifndef COCKTAIL_SORT_H
#define COCKTAIL_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Cocktail sort.
  class cocktail_sort : public sort {
    protected:
      void specific_do_sort();

    public:
      cocktail_sort() {
      }

      ~cocktail_sort() {
      }
  };
}

#endif /* COCKTAIL_SORT_H */

