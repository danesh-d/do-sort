
#include "do_sort.h"

using namespace std;

// Return the size of the sorted data.
size_t do_sort::sort::size() {
  return v.size();
}

// Fill the vector with the input data.
void do_sort::sort::set_data(vector<int>& arr, int s) {
  v = arr;
}

void do_sort::sort::clear_data() {
  v.clear();
}

// Dump values in a vector.
void do_sort::sort::dump(string title) {
  cout << "---------- " << title << " ----------" << endl;
  for (int i = 0; i < v.size(); ++i)
    cout << "v[" << i << "]: " << v[i] << endl;
}

// Initialize a vector with the given size with some random data.
void do_sort::sort::init(int s) {
  srand((unsigned)time(NULL));

  for (int i = 0; i < s; ++i)
    v.push_back(rand() % s + 1);
}

int do_sort::sort::operator[](int i) {
  return v[i];
}

// Swap two values in a vector by giving the indices.
void do_sort::sort::swap(vector<int>& v, int i, int j) {
  int tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

// Merge two sorted lists into one list.
void do_sort::sort::merge(vector<int>& v, vector<int>& aux, int low, int border, int high) {
  int num = high - low + 1;
  int ptr = low;
  int low_end = border - 1;

  // Start mergin two lists until a list is finished before the other or if
  // both lists are finished at the same time, if they have same length.
  while (low <= low_end && border <= high)
    aux[ptr++] = (v[low] < v[border]) ? v[low++] : v[border++];

  // Merge the ramaining.
  while (low <= low_end)
    aux[ptr++] = v[low++];

  // Merge the ramaining.
  while (border <= high)
    aux[ptr++] = v[border++];

  // Copy the sorted list to the original.
  memcpy(&v[high - num + 1], &aux[high - num + 1], num * sizeof(int));
}

// --- Bubble sort implementation.

void do_sort::bubble_sort::do_sort() {
  int n = v.size();
  int j = 0;
  bool swapped = true;

  while (swapped) {
    swapped = false;

    for (int i = 0; i < n - j; ++i)
      if (v[i] > v[i + 1]) {
        swap(v, i, i + 1);
        swapped = true;
      }
  }
}

// --- Selection sort implementation.

// Perform the selection sort.
void do_sort::selection_sort::do_sort() {
  for (int i = 0; i < v.size(); ++i) {
    int min_val = v[i];
    int ind = i;

    for (int j = i  + 1; j < v.size(); ++j) {
      if (v[j] < min_val) {
        min_val = v[j];
        ind = j;
      }
    }

    if (ind != i)
      swap(v, i, ind);
  }
}

// --- Insertion sort implementation.

// Perform the insertion sort.
void do_sort::insertion_sort::do_sort() {
  for (int i = 1; i < v.size(); ++i) {
    int elem = v[i];
    int j = i;

    while (j > 0 && v[j - 1] > elem)
      v[j] = v[--j];

    v[j] = elem;
  }
}

// --- Merge sort implementation.

void do_sort::merge_sort::msort(vector<int>& v, vector<int>& aux, int low, int high) {
  if (low < high) {
    int mid = (low + high) >> 1;

    msort(v, aux, low, mid);
    msort(v, aux, mid + 1, high);
    merge(v, aux, low, mid + 1, high);
  }
}

// Perform the merge sort.
void do_sort::merge_sort::do_sort() {
  aux.resize(v.size());

  if (v.size() > 1)
    msort(v, aux, 0, v.size() - 1);

  aux.clear();
}

// --- Quick sort implementation.

void do_sort::quick_sort::qsort(vector<int>& v, int left, int right) {
  int l = left;
  int r = right;
  int pivot = v[(l + r) >> 1];

 // Perform partioning according to the current pivot.
  while (l <= r) {
    while (v[l] < pivot)
      ++l;

    while (v[r] > pivot)
      --r;

    if (l <= r)
      swap(v, l++, r--);
  }

  // Sort the two other halfs divided by the pivot.
  if (left < r)
    qsort(v, left, r);
  if (right > l)
    qsort(v, l, right);
}

// Perform the quick sort.
void do_sort::quick_sort::do_sort() {
  qsort(v, 0, v.size() - 1);
}

// --- Strand sort implementation.

// Perform the quick sort.
void do_sort::strand_sort::do_sort() {
}

// --- Shell sort implementation.

// --- Heap sort implementation.

