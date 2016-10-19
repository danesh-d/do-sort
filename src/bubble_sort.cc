
#include "bubble_sort.h"

using namespace std;

// --- Bubble sort implementation.

void do_sort::bubble_sort::specific_do_sort() {
  size_t upper_bound = size();
  size_t lower_bound = 0;
  bool swapped = true;

  if (upper_bound <= 1) {
    return;
  }

  while (swapped) {
    swapped = false;

    size_t tmp_upper = 0;
    size_t tmp_lower = 0;

    for (int i = lower_bound; i < upper_bound - 1; ++i) {
      if (v[i] > v[i + 1]) {
        swap(v, i, i + 1);
        swapped = true;

        if (tmp_upper == 0) {
          lower_bound = i - 1;
        }

        // Save the place of last swap. The process in the next round will
        // continue up to this point since the rest of the list will be remain
        // sorted if no swap has happened.
        tmp_upper = i + 1;
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

