
#include "bubble_sort.h"

using namespace std;

// --- Bubble sort implementation.

void do_sort::bubble_sort::specific_do_sort() {
  int n = v.size();
  int j = 0;
  bool swapped = true;

  while (swapped) {
    swapped = false;

    for (int i = 0; i < n - j; ++i) {
      if (v[i] > v[i + 1]) {
        swap(v, i, i + 1);
        swapped = true;
      }
    }
  }
}

