
#include "quick_sort.h"

using namespace std;

// --- Quick sort implementation.

// Sort an array recursively by assigning a pivot and partitioning.
void do_sort::quick_sort::qsort_partition(vector<int>& v, ULL left, ULL right) {
  ULL l = left;
  ULL r = right;
  int pivot = v[(l + r) >> 1];

 // Perform partioning according to the current pivot.
  while (l <= r) {
    while (v[l] < pivot) {
      ++l;
    }

    while (v[r] > pivot) {
      --r;
    }

    if (l <= r) {
      swap(v, l++, r--);
    }
  }

  // Sort the two other halfs partitioned by the pivot.
  if (left < r) {
    qsort_partition(v, left, r);
  }

  if (right > l) {
    qsort_partition(v, l, right);
  }
}

// Perform the quick sort.
void do_sort::quick_sort::specific_do_sort() {
  if (size() <= 1) {
    return;
  }

  qsort_partition(v, 0, size() - 1);
}

