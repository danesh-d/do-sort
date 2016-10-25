
#include "quick_sort.h"

using namespace std;

// --- Quick sort implementation.

// Sort an array recursively by assigning a pivot and partitioning.
int do_sort::quick_sort::partition(vector<int>& v, LL left, LL right) {
  int piv = v[right];    // Initial guess of the pivot is the last element.
  LL ind = left - 1;

  for (LL i = left; i <= right - 1; ++i) {
    if (v[i] <= piv) {
      // Swap all elements smaller than pivot from left to right and then swap
      // the pivot itself when processing of all elements is done.
      swap(v, ++ind, i);
    }
  }

  // Adjust the place of the pivot and put it in the correct place in the final
  // sorted list.
  swap(v, ++ind, right);

  // Return the correct place of the pivot, so the sorting will continue for the
  // two halfs, partitioned by the pivot.
  return ind;
}

void do_sort::quick_sort::qs_partition(vector<int>& v, LL left, LL right) {
  if (left < right) {
    // Partition the array based on the two given bounds.
    int piv = partition(v, left, right);

    // Sort two separated partitions based on the pivot.
    qs_partition(v, left, piv - 1);
    qs_partition(v, piv + 1, right);
  }
}

// Perform the quick sort.
void do_sort::quick_sort::specific_do_sort() {
  if (size() <= 1) {
    return;
  }

  qs_partition(v, 0, size() - 1);
}

