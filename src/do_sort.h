#ifndef DO_SORT_H
#define DO_SORT_H

#include <iostream>
#include <vector>
#include <list>
#include <ctime>

#include <string.h>
#include <stdlib.h>

typedef long L;
typedef long long LL;
typedef unsigned long UL;
typedef unsigned long long ULL;

using namespace std;

namespace do_sort {
  // Abstract class for sort.
  class sort {
    protected:
      vector<int> v;    // A sequential array-based data structure.
      list<int> l;      // A two way linked list data structure.
      bool asc;         // Specify the order of sorting.
      int (*cmpFunc)(const void*, const void*);

      // Each sorting algorithm will implement this funciton which will not be
      // explicitely called but from "do_sort" public functionk.
      virtual void specific_do_sort() = 0;

      // Swap the elements v[i] and v[j].
      void swap(vector<int>& v, LL i, LL j);

      // Merge two sorted lists.
      void merge(vector<int>& v,
                 vector<int>& sorted_v,
                 LL low,
                 LL border,
                 LL high);

    public:
      sort() {
      }

      virtual ~sort() {
        v.clear();
      }

      void set_data(vector<int>& arr, int s);
      void clear_data();
      void dump(string title);
      void init(int s);
      double do_sort(bool elapsed_time,
                     bool asc = true,
                     int (*cmpFunc)(const void*, const void*) = NULL);

      LL size();

      bool empty();

      int operator[](size_t i);
  };


  // --- Shell sort implementation.

  // --- Heap sort implementation.
}

#endif /* DO_SORT_H */

