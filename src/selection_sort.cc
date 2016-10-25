
#include "selection_sort.h"

using namespace std;

// --- Selection sort implementation.

// Perform the selection sort.
void do_sort::selection_sort::specific_do_sort() {
  if (size() <= 1) {
    return;
  }

  LL n = size();

  // Traverse the list until all elements are sorted.
  for (int i = 0; i < n; ++i) {
    int min_val = v[i];
    LL ind = i;

    // From the current element to the end of the list, find the minimum value
    // and swap it with the current element.
    for (int j = i  + 1; j < n; ++j) {
      if (v[j] < min_val) {
        min_val = v[j];
        ind = j;
      }
    }

    if (ind != i) {
      swap(v, i, ind);
    }
  }
}

