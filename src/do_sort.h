#ifndef DO_SORT_H
#define DO_SORT_H

#include <vector>
#include <list>
#include <ctime>

#include <string.h>
#include <stdlib.h>

typedef long L;
typedef long long LL;
typedef unsigned long UL;
typedef unsigned long long ULL;
typedef long double LD;

using namespace std;

namespace do_sort {
  // Abstract class for sort.
  template <class T>
  class sort {
    protected:
      vector<T> v;      // A sequential array-based data structure.
      list<T> l;        // A two way linked list data structure.
      bool asc;         // Specify the order of sorting.

      // Each sorting algorithm will implement this funciton which will not be
      // explicitely called but from "do_sort" public functionk.
      virtual void specific_do_sort() = 0;

      // Merge two sorted lists.
      void merge(vector<T>& v,
                 vector<T>& aux,
                 LL low,
                 LL border,
                 LL high,
                 bool asc) {
        LL num = high - low + 1;
        LL ptr = low;
        LL low_end = border - 1;

        // Start mergin two lists until a list is finished before the other or
        // if both lists are finished at the same time, if they have same
        // length.
        if (asc) {
          // Merge two lists while maintaining the ascending order.
          while (low <= low_end && border <= high) {
            aux[ptr++] = (v[low] < v[border]) ? v[low++] : v[border++];
          }
        } else {
          // Merge two lists while maintaining the descending order.
          while (low <= low_end && border <= high) {
            aux[ptr++] = (v[low] > v[border]) ? v[low++] : v[border++];
          }
        }

        // Merge the ramaining.
        while (low <= low_end) {
          aux[ptr++] = v[low++];
        }

        // Merge the ramaining.
        while (border <= high) {
          aux[ptr++] = v[border++];
        }

        // Copy the sorted list to the original.
        copy(aux.begin() + (high - num + 1),
             aux.begin() + (high + 1),
             v.begin() + (high - num + 1));
      }

      // Heapify a subtree rooted with node "i" which is an index in the vector
      // "v". If the "i" is set to zero then the whole tree will be heapified.
      void heapify(vector<T>& v, LL n,  LL i, bool asc) {
        LL hit_ind = i;
        LL l = 2 * i + 1;
        LL r = 2 * i + 2;

        // Check whether the hit node (largest or smallest) is the root node,
        // otherwise set the hit to point to the child of the root.
        if (asc) {
          hit_ind = (l < n && v[l] > v[hit_ind]) ? l : hit_ind;
          hit_ind = (r < n && v[r] > v[hit_ind]) ? r : hit_ind;
        } else {
          hit_ind = (l < n && v[l] < v[hit_ind]) ? l : hit_ind;
          hit_ind = (r < n && v[r] < v[hit_ind]) ? r : hit_ind;
        }

        if (hit_ind != i) {
          // The hit node was not the root node. Swap the root with child and
          // then start the heapifying process recursively from the newly hit
          // node.
          swap(v[i], v[hit_ind]);
          heapify(v, n, hit_ind, sort<T>::asc);
        }
      }

    public:
      sort() {
      }

      virtual ~sort() {
        v.clear();
      }

      // Fill the vector with the input data.
      void set_data(vector<T>& arr) {
        // Note that while the vector's data i.e. header, metadata and control
        // parameters are stored on the stack (which is not a big part of the
        // whole data), the elements themselves will be stored on the heap which
        // will be managed internally by the C++ container.
        v = arr;
      }

      void clear_data() {
        v.clear();
      }

      // Dump values in a vector.
      void dump(string title) {
        cout << "---------- " << title << " ----------" << endl;
        for (LL i = 0; i < size(); ++i) {
          cout << "v[" << i << "]: " << v[i] << endl;
        }
      }

      LD do_sort(bool elapsed_time,
                     bool asc = true) {
        LD t = 0.0;

        this->asc = asc;

        if (!elapsed_time) {
          // The elapsed time for the current sorting process is not needed to
          // be reported, so just 0.0 will be returned instead.
          specific_do_sort();
        } else {
          clock_t begin = clock();
          specific_do_sort();
          clock_t end = clock();

          t = (LD)(end - begin) / CLOCKS_PER_SEC;
        }

        return t;
      }

      // Return the size of the sorted data. The size data type is signed by
      // purpose. Otherwise some other sorting algorithms such as quick sort
      // might fail as they would find some termination condition when the size
      // is negative.
      LL size() {
        return (LL)v.size();
      }

      // Return true if the sorted data is empty.
      bool empty() {
        return v.empty();
      }

      T operator[](size_t i) {
        return v[i];
      }
  };
}

#endif /* DO_SORT_H */

