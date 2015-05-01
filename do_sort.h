
#include <iostream>
#include <vector>

#include <string.h>
#include <stdlib.h>

using namespace std;

namespace do_sort {
  // Abstract class for sort.
  class sort {
    protected:
      vector<int> v;

      virtual void do_sort() = 0;

      // Swap the elements v[i] and v[j].
      void swap(vector<int>& v, int i, int j);
      // Merge two sorted lists.
      void merge(vector<int>& v, vector<int>& sorted_v, int low, int border, int high);

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

      size_t size();

      int operator[](int i);
  };

  // --- Bubble sort.
  class bubble_sort : public sort {
    public:
      bubble_sort() {
      }

      ~bubble_sort() {
      }

      void do_sort();
  };

  // --- Selection sort.
  class selection_sort : public sort {
    public:
      selection_sort() {
      }

      ~selection_sort() {
      }

      void do_sort();
  };

  // --- Insertion sort.
  class insertion_sort : public sort {
    public:
      insertion_sort() {
      }

      ~insertion_sort() {
      }

      void do_sort();
  };

  // --- Merge sort.
  class merge_sort : public sort {
    private:
      vector<int> aux;

      void msort(vector<int>& v, vector<int>& aux, int low, int high);

    public:
      merge_sort() {
      }

      ~merge_sort() {
        aux.clear();
      }

      void do_sort();
  };

  // --- Quick sort implementation.
  class quick_sort : public sort {
    private:
      void qsort(vector<int>& v, int left, int right);

    public:
      quick_sort() {
      }

      ~quick_sort() {
      }

      void do_sort();
  };

  // --- Strand sort implementation.
  class strand_sort : public sort {
    private:
      // This vector indicates which element has been deleted from the main
      // vector, by setting the deleted element's element to false.
      vector<bool> flags;
      vector<int> sub_v;
      vector<int> sorted_v;
      vector<int> aux;

    public:
      strand_sort() {
      }

      ~strand_sort() {
        flags.clear();
        sub_v.clear();
        sorted_v.clear();
        aux.clear();
      }

      void do_sort();
  };

  // --- Shell sort implementation.

  // --- Heap sort implementation.
}

