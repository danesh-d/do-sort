
#include <iostream>
#include <vector>

#include <time.h>
#include <stdlib.h>

using namespace std;

namespace do_sort {
  // Abstract class for sort.
  class sort {
    protected:
      vector<int> v;

      virtual void do_sort() = 0;

    public:
      void set_data(int* v, int s);
      void clear_data();
      void dump(string title);
      void init(int s);

      size_t size();

      int operator[](int i);
  };

  // --- Bubble sort.
  class bubble_sort : public sort {
    private:
      // Swap the elements v[i] and v[j].
      void swap(vector<int>& v, int i, int j);

    public:
      bubble_sort() {
      }

      ~bubble_sort() {
        v.clear();
      }

      void do_sort();
  };

  // --- Insertion sort.
  class insertion_sort : public sort {
    public:
      insertion_sort() {
      }

      ~insertion_sort() {
        v.clear();
      }

      void do_sort();
  };

  // --- Merge sort.
  class merge_sort : public sort {
    private:
      vector<int> sorted_v;

      void merge(int* v, int* sorted_v, int low, int border, int high);
      void msort(int* v, int* sorted_v, int low, int high);

    public:
      merge_sort() {
      }

      ~merge_sort() {
        sorted_v.clear();
      }

      void do_sort();
  };

  // --- Quick sort implementation.

  // --- Selection sort implementation.

  // --- Shell sort implementation.

  // --- Heap sort implementation.
}
