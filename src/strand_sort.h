#ifndef STRAND_SORT_H
#define STRAND_SORT_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Strand sort implementation.
  template <class T>
  class strand_sort : public sort<T> {
    private:
      list<T> sorted_list;

    protected:
      // Perform the strand sort. This sorting algorithm utilizes a linked list
      // instead of a simple array (vector) because frequent add/remove
      // operations are needed to be done which can be done efficiently in a
      // linked list with lower cost.
      void specific_do_sort() {
        if (sort<T>::size() <= 1) {
          return;
        }

        // Copy the vector which holds all input data to a linked list. The
        // interface is kept as vector to maintain compatibility and consistency
        // with all other sorting algorithms.
        copy(sort<T>::v.begin(), sort<T>::v.end(), back_inserter(sort<T>::l));
        sort<T>::v.clear();

        // This list holds sorted sub-list in each iteration.
        list<T> sorted_sublist;

        while (!sort<T>::l.empty()) {
          // Copy the head of the list into the sorted sub-list and then add all
          // elements which are less or equal to the recently added element to
          // the sub-list iteratively.
          sorted_sublist.push_back(sort<T>::l.front());
          sort<T>::l.pop_front();

          for (typename list<T>::iterator it = sort<T>::l.begin();
               it != sort<T>::l.end();) {
            if (sorted_sublist.back() <= *it) {
              sorted_sublist.push_back(*it);
              it = sort<T>::l.erase(it);
            } else {
              ++it;
            }
          }

          // Merge the sorted sub-list with the final sorted list. The sub-list
          // will be released after each merge automatically.
          sorted_list.merge(sorted_sublist);
        }

        if (!sort<T>::asc) {
          // The sorted list should be in descending order so just revert the
          // list. Since it is a linked list, so the complexity will be O(n)
          // which is quite low.
          sorted_list.reverse();
        }

        copy(sorted_list.begin(),
             sorted_list.end(),
             back_inserter(sort<T>::v));
        sorted_list.clear();
      }

    public:
      strand_sort() {
      }

      virtual ~strand_sort() {
      }
  };
}

#endif /* STRNAD_SORT_H */

