
#include "strand_sort.h"

using namespace std;

// --- Strand sort implementation.

// Perform the strand sort. This sorting algorithm utilizes a linked list
// instead of a simple array (vector) because frequent add/remove operations are
// needed to be done which can be done efficiently in a linked list with lower
// cost.
void do_sort::strand_sort::specific_do_sort() {
  if (v.size() <= 1) {
    return;
  }

  // Copy the vector which holds all input data to a linked list. The interface
  // is kept as vector to maintain compatibility and consistency with all other
  // sorting algorithms.
  copy(v.begin(), v.end(), back_inserter(l));
  v.clear();

  // This list holds sorted sub-list in each iteration.
  list<int> sorted_sublist;

  while (!l.empty()) {
    // Copy the head of the list into the sorted sub-list and then add all
    // elements which are less or equal to the recently added element to the
    // sub-list iteratively.
    sorted_sublist.push_back(l.front());
    l.pop_front();

    for (list<int>::iterator it = l.begin(); it != l.end();) {
      if (sorted_sublist.back() <= *it) {
        sorted_sublist.push_back(*it);
        it = l.erase(it);
      } else {
        ++it;
      }
    }

    // Merge the sorted sub-list with the final sorted list. The sub-list will
    // be released after each merge automatically.
    sorted_list.merge(sorted_sublist);
  }

  copy(sorted_list.begin(), sorted_list.end(), back_inserter(v));
  sorted_list.clear();
}

