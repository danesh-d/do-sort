
#include "bubble_sort.h"

using namespace std;

// --- Bubble sort implementation.

void do_sort::bubble_sort::specific_do_sort() {
  if (size() <= 1) {
    return;
  }

  ULL upper_bound = size() - 1;
  ULL lower_bound = 0;
  bool swapped = true;

  while (swapped) {
    swapped = false;

    ULL tmp_upper = 0;
    ULL tmp_lower = 0;

    for (int i = lower_bound; i < upper_bound; ++i) {
      if (v[i] > v[i + 1]) {
        swap(v, i, i + 1);
        swapped = true;

        if (tmp_upper == 0) {
          lower_bound = i - 1;
        }

        // Save the place of last swap. The process in the next round will
        // continue up to this point since the rest of the list will be remain
        // sorted if no swap has happened.
        tmp_upper = i;
      } else {
        // This might slow down a bit for an array with uniformly distributed
        // random numbers. But if the list is partially sorted at the begining
        // then it will move the lower bound so in the next round, the sorting
        // will start after the sorted sequence.
        if (!swapped) {
          tmp_lower = i;
        }
      }
    }

    // Shrink the range of the sorting since it is needed to continue the
    // process up to the last non-sorted element in the list. Also, jump over
    // all sorted elements at the begining of teh array.
    upper_bound = tmp_upper;
    lower_bound = tmp_lower;
  }
}

