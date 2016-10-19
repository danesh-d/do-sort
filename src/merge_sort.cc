
#include "merge_sort.h"

using namespace std;

// --- Merge sort implementation.

void do_sort::merge_sort::recursive_msort(vector<int>& v,
                                          vector<int>& aux,
                                          size_t low,
                                          size_t high) {
  if (low < high) {
    size_t mid = (low + high) >> 1;

    // The original list is partitioned at the middle and each part will be
    // sorted separately while each sub-list will be divided and sorted
    // recursively until the list consists of two elements and then they wil be
    // merged.
    recursive_msort(v, aux, low, mid);
    recursive_msort(v, aux, mid + 1, high);

    // Both lists partitioned at the middle have been sorted and now will be
    // merged while the order will be preserved.
    merge(v, aux, low, mid + 1, high);
  }
}

// Perform the merge sort.
void do_sort::merge_sort::specific_do_sort() {
  size_t n = size();

  if (n <= 1) {
    return;
  }

  aux.resize(n);
  recursive_msort(v, aux, 0, n - 1);
  aux.clear();
}

