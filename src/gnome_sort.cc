
#include "gnome_sort.h"

using namespace std;

// --- Gnome sort implementation.

void do_sort::gnome_sort::gnome_sort_bounded(int upper_bound) {
  ULL pos = upper_bound;

  while ((pos > 0) && (v[pos - 1] > v[pos])) {
    swap(v, pos, pos - 1);
    --pos;
  }
}

void do_sort::gnome_sort::specific_do_sort() {
  if (size() <= 1) {
    return;
  }

  for (int i = 1; i < size(); ++i) {
    gnome_sort_bounded(i);
  }
}

