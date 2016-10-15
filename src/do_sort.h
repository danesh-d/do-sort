
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

      // Each sorting algorithm will implement this funciton which will not be
      // explicitely called but from "do_sort" public functionk.
      virtual void specific_do_sort() = 0;

      // Swap the elements v[i] and v[j].
      void swap(vector<int>& v, int i, int j);

      // Merge two sorted lists.
      void merge(vector<int>& v,
                 vector<int>& sorted_v,
                 int low,
                 int border,
                 int high);

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
      void do_sort();

      size_t size();

      int operator[](int i);
  };

  // --- Bubble sort.
  class bubble_sort : public sort {
    protected:
      void specific_do_sort();

    public:
      bubble_sort() {
      }

      ~bubble_sort() {
      }
  };

  // --- Selection sort.
  class selection_sort : public sort {
    protected:
      void specific_do_sort();

    public:
      selection_sort() {
      }

      ~selection_sort() {
      }
  };

  // --- Insertion sort.
  class insertion_sort : public sort {
    protected:
      void specific_do_sort();

    public:
      insertion_sort() {
      }

      ~insertion_sort() {
      }
  };

  // --- Merge sort.
  class merge_sort : public sort {
    private:
      vector<int> aux;

      void recursive_msort(vector<int>& v, vector<int>& aux, int low, int high);

    protected:
      void specific_do_sort();

    public:
      merge_sort() {
      }

      ~merge_sort() {
        aux.clear();
      }
  };

  // --- Quick sort implementation.
  class quick_sort : public sort {
    private:
      void qsort_partition(vector<int>& v, int left, int right);

    protected:
      void specific_do_sort();

    public:
      quick_sort() {
      }

      ~quick_sort() {
      }
  };

  // --- Strand sort implementation.
  class strand_sort : public sort {
    private:
      // This vector indicates which element has been deleted from the main
      // vector, by setting the deleted element's flag to false.
      vector<bool> flags;
      vector<int> sub_v;
      vector<int> sorted_v;
      vector<int> aux;

    protected:
      void specific_do_sort();

    public:
      strand_sort() {
      }

      ~strand_sort() {
        flags.clear();
        sub_v.clear();
        sorted_v.clear();
        aux.clear();
      }
  };

  // --- Shell sort implementation.

  // --- Heap sort implementation.
}

