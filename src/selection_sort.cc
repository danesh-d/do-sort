
#include "selection_sort.h"

using namespace std;

// --- Selection sort implementation.

// Perform the selection sort.
void do_sort::selection_sort::specific_do_sort() {
  // Traverse the list until all elements are sorted.
  for (int i = 0; i < v.size(); ++i) {
    int min_val = v[i];
    int ind = i;

    // From the current element to the end of the list, find the minimum value
    // and swap it with the current element.
    for (int j = i  + 1; j < v.size(); ++j) {
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

