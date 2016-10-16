
#include "strand_sort.h"

using namespace std;

// --- Strand sort implementation.

// Perform the strand sort.
void do_sort::strand_sort::specific_do_sort() {
  int n = v.size();
  int ptr = 0;

  if (n <= 1)
    return;

  aux.resize(v.size());
  flags.resize(v.size(), true);

  // Go through all elements, until all elements have been processed.
  while (n > 0) {
    // Ignore all already processed elements in the list.
    while (!flags[ptr]) {
      ptr++;
    }

    int e = v[ptr];
    int m = e;
    flags[ptr++] = false;
    --n;
    sub_v.push_back(e);

    // Generate a sorted list based on the first element.
    for (int i = ptr; i < v.size(); ++i) {
      if (flags[i] && v[i] >= m) {
        m = v[i];
        sub_v.push_back(m);
        flags[i] = false;
        --n;
      }
    }

    // Save the merging point where the current sorting list and the newly
    // generated sorting list will be merged.
    int mid = sorted_v.size();

    // Add the new sorted list to the already sorted list.
    for (int i = 0; i < sub_v.size(); ++i) {
      sorted_v.push_back(sub_v[i]);
    }

    // Perform the merge so form the new sorted list.
    merge(sorted_v, aux, 0, mid, sorted_v.size() - 1);

    sub_v.clear();
  }

  v = sorted_v;
}

