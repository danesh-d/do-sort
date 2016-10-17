
#include "bubble_sort.h"

using namespace std;

// --- Bubble sort implementation.

void do_sort::bubble_sort::specific_do_sort() {
  int n = size();
  int upper_bound = n - 1;
  bool swapped = true;

  while (swapped) {
    swapped = false;

    int tmp = 0;

    for (int i = 0; i < upper_bound; ++i) {
      if (v[i] > v[i + 1]) {
        swap(v, i, i + 1);
        swapped = true;

        // Save the place of last swap. The process in the next round will
        // continue up to this point since the rest of the list will be remain
        // sorted if no swap has happened.
        tmp = i + 1;
      }
    }

    // Shrink the range of the sorting since it is needed to continue the
    // process up to the last non-sorted element in the list.
    upper_bound = tmp;
  }
}

