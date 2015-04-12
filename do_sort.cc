
#include "do_sort.h"

using namespace std;


// Fill the vector with the input data.
void sort::set_data(int* arr, int s) {
  for (int i = 0; i < s; ++i)
    v.push_back(arr[i]);
}

void sort::clear_data() {
  v.clear();
}

// Dump values in a vector.
void sort::dump(string title) {
  cout << "---------- " << title << " ----------" << endl;
  for (int i = 0; i < v.size(); ++i)
    cout << "v[" << i << "]: " << v[i] << endl;
}

// Initialize a vector with the given size with some random data.
void sort::init(int s) {
  srand((unsigned)time(NULL));

  for (int i = 0; i < s; ++i)
    v.push_back(rand() % s + 1);
}

int sort::operator[](int i) {
  return v[i];
}

// --- Bubble sort implementation.

// Swap two values in a vector by giving the indices.
void bubble_sort::swap(vector<int>& v, int i, int j) {
  int tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

// Perform the bubble sort.
void bubble_sort::do_sort() {
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
void insertion_sort::do_sort() {
  for (int i = 1; i < v.size(); ++i) {
    int elem = v[i];
    int j = i;

    while (j > 0 && v[j - 1] > elem)
      v[j] = v[--j];

    v[j] = elem;
  }
}

// --- Merge sort implementation.

// Merge two sorted lists into one list.
void merge_sort::merge(int* v, int* sorted_v, int low, int border, int high) {
  int num = high - low + 1;
  int ptr = low;
  int low_end = border - 1;

  // Start mergin two lists until a list is finished before the other or if
  // both lists are finished at the same time, if they have same length.
  while (low <= low_end && border <= high)
    sorted_v[ptr++] = (v[low] < v[border]) ? v[low++] : v[border++];

  // Merge the ramaining.
  while (low <= low_end)
    sorted_v[ptr++] = v[low++];

  // Merge the ramaining.
  while (border <= high)
    sorted_v[ptr++] = v[border++];

  // Copy the sorted list to the original.
  for (int i = 0; i < num; ++i, --high)
    v[high] = sorted_v[high];
}

void merge_sort::msort(int* v, int* sorted_v, int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;

    msort(v, sorted_v, low, mid);
    msort(v, sorted_v, mid + 1, high);
    merge(v, sorted_v, low, mid + 1, high);
  }
}

void merge_sort::do_sort() {
  sorted_v.resize(v.size());

  if (v.size() > 1)
    msort(&v[0], &sorted_v[0], 0, v.size() - 1);

  v = sorted_v;
  sorted_v.clear();
}

// --- Quick sort implementation.

// --- Selection sort implementation.

// --- Shell sort implementation.

// --- Heap sort implementation.


int main() {
  bubble_sort *bs = new bubble_sort();
  bs->init(20);
  bs->do_sort();
  bs->dump("Bubble Sort");
  delete bs;

  insertion_sort *is = new insertion_sort();
  is->init(20);
  is->do_sort();
  is->dump("Insertion Sort");
  delete is;

  merge_sort *ms = new merge_sort();
  ms->init(20);
  ms->do_sort();
  ms->dump("Merge Sort");
  delete ms;

  return 0;
}

