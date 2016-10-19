
#include "do_sort.h"

using namespace std;

// Return the size of the sorted data.
size_t do_sort::sort::size() {
  return v.size();
}

// Return true if the sorted data is empty.
bool do_sort::sort::empty() {
  return v.empty();
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
  for (unsigned long i = 0; i < size(); ++i) {
    cout << "v[" << i << "]: " << v[i] << endl;
  }
}

// Initialize a vector with the given size with some random data.
void do_sort::sort::init(int s) {
  srand((unsigned)time(NULL));

  for (unsigned long i = 0; i < s; ++i) {
    v.push_back(rand() % s + 1);
  }
}

int do_sort::sort::operator[](size_t i) {
  return v[i];
}

// Swap two values in a vector by giving the indices.
void do_sort::sort::swap(vector<int>& v, size_t i, size_t j) {
  int tmp = v[i];

  v[i] = v[j];
  v[j] = tmp;
}

// Merge two sorted lists into one list.
void do_sort::sort::merge(vector<int>& v,
                          vector<int>& aux,
                          size_t low,
                          size_t border,
                          size_t high) {
  size_t num = high - low + 1;
  size_t ptr = low;
  size_t low_end = border - 1;

  // Start mergin two lists until a list is finished before the other or if
  // both lists are finished at the same time, if they have same length.
  while (low <= low_end && border <= high) {
    aux[ptr++] = (v[low] < v[border]) ? v[low++] : v[border++];
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
  memcpy(&v[high - num + 1], &aux[high - num + 1], num * sizeof(int));
}

double do_sort::sort::do_sort(bool elapsed_time) {
  double t = 0.0;

  if (!elapsed_time) {
    // The elapsed time for the current sorting process is not needed to be
    // reported, so just 0.0 will be returned instead.
    specific_do_sort();
  } else {
    clock_t begin = clock();

    specific_do_sort();

    clock_t end = clock();
    t = double(end - begin) / CLOCKS_PER_SEC;
  }

  return t;
}

