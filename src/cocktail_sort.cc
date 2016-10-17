
#include "cocktail_sort.h"

using namespace std;

// --- Cocktail sort implementation.

// This algorithm is similar to Bubble sort but the difference is that after
// each traverse from left to right, then next traverse will start from right to
// left and so on.
void do_sort::cocktail_sort::specific_do_sort() {
  int n = v.size();
  int upper_bound = n - 1;
  int lower_bound = 0;
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

    if (!swapped) {
      // No swap has been done, so no reverse check is needed and the loop will
      // be terminated.
      break;
    }

    for (int i = upper_bound; i >= 0; --i) {
      if (v[i] > v[i + 1]) {
        swap(v, i, i + 1);
        swapped = true;

        // Save the place of last swap. The process in the next round will
        // start from this point since the rest of the list will be remain
        // sorted if no swap has happened.
        tmp = i + 1;
      }
    }

    lower_bound = tmp;
  }
}

