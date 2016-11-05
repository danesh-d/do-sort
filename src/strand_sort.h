#ifndef STRAND_SORT_H
#define STRAND_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Strand sort implementation.
  template <class T>
  class strand_sort : public sort<T> {
    private:
      list<int> sorted_list;

    protected:
      // Perform the strand sort. This sorting algorithm utilizes a linked list
      // instead of a simple array (vector) because frequent add/remove
      // operations are needed to be done which can be done efficiently in a
      // linked list with lower cost.
      void specific_do_sort() {
        if (this->size() <= 1) {
          return;
        }

        // Copy the vector which holds all input data to a linked list. The
        // interface is kept as vector to maintain compatibility and consistency
        // with all other sorting algorithms.
        copy(this->v.begin(), this->v.end(), back_inserter(this->l));
        this->v.clear();

        // This list holds sorted sub-list in each iteration.
        list<int> sorted_sublist;

        while (!this->l.empty()) {
          // Copy the head of the list into the sorted sub-list and then add all
          // elements which are less or equal to the recently added element to
          // the sub-list iteratively.
          sorted_sublist.push_back(this->l.front());
          this->l.pop_front();

          for (list<int>::iterator it = this->l.begin(); it != this->l.end();) {
            if (sorted_sublist.back() <= *it) {
              sorted_sublist.push_back(*it);
              it = this->l.erase(it);
            } else {
              ++it;
            }
          }

          // Merge the sorted sub-list with the final sorted list. The sub-list
          // will be released after each merge automatically.
          sorted_list.merge(sorted_sublist);
        }

        copy(sorted_list.begin(), sorted_list.end(), back_inserter(this->v));
        sorted_list.clear();
      }

    public:
      strand_sort() {
      }

      ~strand_sort() {
      }
  };
}

#endif /* STRNAD_SORT_H */

