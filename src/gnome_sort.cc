
#include "gnome_sort.h"

using namespace std;

// --- Gnome sort implementation.

void do_sort::gnome_sort::gnome_sort_bounded(size_t upper_bound) {
  size_t pos = upper_bound;

  while ((pos > 0) && (v[pos - 1] > v[pos])) {
    swap(v, pos, pos - 1);
    --pos;
  }
}

void do_sort::gnome_sort::specific_do_sort() {
  size_t n = size();

  if (n <= 1) {
    return;
  }

  for (int i = 1; i < n; ++i) {
    gnome_sort_bounded(i);
  }
}

