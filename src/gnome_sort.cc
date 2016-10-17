
#include "gnome_sort.h"

using namespace std;

// --- Gnome sort implementation.

void do_sort::gnome_sort::specific_do_sort() {
  int pos = 0;
  int n = size();

  while (pos < n) {
    if ((pos == 0) || (v[pos] >= v[pos -1])) {
      ++pos;
    } else {
      swap(v, pos, pos - 1);
      --pos;
    }
  }
}

