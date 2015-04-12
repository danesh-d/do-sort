
#include "do_sort.h"

#define DATA_SIZE 20
#define DUMP_DATA 0

using namespace std;

// Check whether the list is correctly sorted.
bool is_sorted(do_sort::sort* ss) {
  for (int i = 0; i < ss->size() - 1; ++i)
    if ((*ss)[i] > (*ss)[i + 1])
      return false;

  return true;
}

// Report the testing results.
void report_test_result(do_sort::sort* ss, string sorting_method) {
  string test_result = (is_sorted(ss)) ? "\033[32mPASSED" : "\033[31mFAILED";
  cout << sorting_method << " test --> " << "[" << test_result << "\033[39m]" << endl;;
}

int main() {
  string test_result = "";

  // Unit test for the bubble sort.
  do_sort::selection_sort *ss = new do_sort::selection_sort();
  ss->init(DATA_SIZE);
  ss->do_sort();
  report_test_result(static_cast<do_sort::sort*>(ss), "Selection sort");
#if DUMP_DATA
  ss->dump("Bubble Sort");
#endif
  delete ss;

  // Unit test for the insertion sort.
  do_sort::insertion_sort *is = new do_sort::insertion_sort();
  is->init(DATA_SIZE);
  is->do_sort();
  report_test_result(static_cast<do_sort::sort*>(is), "Insertion sort");
#if DUMP_DATA
  is->dump("Insertion Sort");
#endif
  delete is;

  // Unit test for the merge sort.
  do_sort::merge_sort *ms = new do_sort::merge_sort();
  ms->init(DATA_SIZE);
  ms->do_sort();
  report_test_result(static_cast<do_sort::sort*>(ms), "Merge sort");
#if DUMP_DATA
  ms->dump("Merge Sort");
#endif
  delete ms;

  // Unit test for the quick sort.
  do_sort::quick_sort *qs = new do_sort::quick_sort();
  qs->init(DATA_SIZE);
  qs->do_sort();
  report_test_result(static_cast<do_sort::sort*>(qs), "Quick sort");
#if DUMP_DATA
  qs->dump("Merge Sort");
#endif
  delete qs;

  return 0;
}

