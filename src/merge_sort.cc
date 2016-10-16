
#include "merge_sort.h"

using namespace std;

// --- Merge sort implementation.

void do_sort::merge_sort::recursive_msort(vector<int>& v,
                                          vector<int>& aux,
                                          int low,
                                          int high) {
  if (low < high) {
    int mid = (low + high) >> 1;

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
  aux.resize(v.size());

  if (v.size() > 1) {
    recursive_msort(v, aux, 0, v.size() - 1);
  }

  aux.clear();
}

