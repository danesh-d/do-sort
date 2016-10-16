
#include "insertion_sort.h"

using namespace std;

// --- Insertion sort implementation.

// Perform the insertion sort.
void do_sort::insertion_sort::specific_do_sort() {
  for (int i = 1; i < v.size(); ++i) {
    int elem = v[i];
    int j = i;

    while ((j > 0) && (v[j - 1] > elem)) {
      v[j] = v[--j];
    }

    v[j] = elem;
  }
}

