
#include "insertion_sort.h"

using namespace std;

// --- Insertion sort implementation.

// Perform the insertion sort.
void do_sort::insertion_sort::specific_do_sort() {
  size_t n = size();

  if (n <= 1) {
    return;
  }

  for (int i = 1; i < n; ++i) {
    int elem = v[i];
    size_t j = i;

    while ((j > 0) && (v[j - 1] > elem)) {
      v[j] = v[--j];
    }

    v[j] = elem;
  }
}

