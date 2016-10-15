
#include "../src/do_sort.h"

#define DATA_SIZE 30000
#define DUMP_DATA 0

using namespace std;

// Check whether the list is correctly sorted.
bool is_sorted(do_sort::sort* ss) {
  if (ss->size() == 0) {
    return true;
  }

  for (int i = 0; i < ss->size() - 1; ++i) {
    if ((*ss)[i] > (*ss)[i + 1]) {
      return false;
    }
  }

  return true;
}

// Report the testing results.
void report_test_result(do_sort::sort* ss,
                        string sorting_method,
                        double elapsed_time) {
  string test_result = (is_sorted(ss)) ? "\033[32mPASSED" : "\033[31mFAILED";
  if (elapsed_time > 0.0) {
    cout << sorting_method
         << " test --> "
         << "["
         << test_result
         << "\033[39m] and the elapsed time is "
         << elapsed_time
         << " seconds."
         << endl;
  } else {
    cout << sorting_method
         << " test --> "
         << "["
         << test_result
         << "\033[39m]"
         << endl;
  }
}

int main() {
  string test_result = "";
  double elapsed_time = 0.0;

  cout << endl
       << endl
       << "-------------------- \033[34mTesting results for sorting an array with "
       << DATA_SIZE
       << " elements\033[39m --------------------"
       << endl;

  // Unit test for the bubble sort.
  do_sort::bubble_sort *bs = new do_sort::bubble_sort();

  bs->init(DATA_SIZE);
  elapsed_time = bs->do_sort(true);
  report_test_result(static_cast<do_sort::sort*>(bs),
                     "Bubble sort",
                     elapsed_time);

  bs->clear_data();
  bs->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(bs),
                     "Bubble sort [corner case #1]",
                     0.0);

  bs->init(1);
  bs->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(bs),
                     "Bubble sort [corner case #2]",
                     0.0);

  cout << "\033[36m---------------------------------------------------------\033[39m"
       << endl;

#if DUMP_DATA
  bs->dump("Bubble Sort");
#endif
  delete bs;

  // Unit test for the selection sort.
  do_sort::selection_sort *ss = new do_sort::selection_sort();
  ss->init(DATA_SIZE);
  elapsed_time = ss->do_sort(true);
  report_test_result(static_cast<do_sort::sort*>(ss),
                     "Selection sort",
                     elapsed_time);

  ss->clear_data();
  ss->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(ss),
                     "Selection sort [corner case #1]",
                     0.0);

  ss->init(1);
  ss->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(ss),
                     "Selection sort [corner case #2]",
                     0.0);

  cout << "\033[36m---------------------------------------------------------\033[39m"
       << endl;

#if DUMP_DATA
  ss->dump("Selection Sort");
#endif
  delete ss;

  // Unit test for the insertion sort.
  do_sort::insertion_sort *is = new do_sort::insertion_sort();
  is->init(DATA_SIZE);
  elapsed_time = is->do_sort(true);
  report_test_result(static_cast<do_sort::sort*>(is),
                     "Insertion sort",
                     elapsed_time);

  is->clear_data();
  is->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(is),
                     "Insertion sort [corner case #1]",
                     0.0);

  is->init(1);
  is->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(is),
                     "Insertion sort [corner case #2]",
                     0.0);

  cout << "\033[36m---------------------------------------------------------\033[39m"
       << endl;

#if DUMP_DATA
  is->dump("Insertion Sort");
#endif
  delete is;

  // Unit test for the merge sort.
  do_sort::merge_sort *ms = new do_sort::merge_sort();
  ms->init(DATA_SIZE);
  elapsed_time = ms->do_sort(true);
  report_test_result(static_cast<do_sort::sort*>(ms),
                     "Merge sort",
                     elapsed_time);

  ms->clear_data();
  ms->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(ms),
                     "Merge sort [corner case #1]",
                     0.0);

  ms->init(1);
  ms->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(ms),
                     "Merge sort [corner case #2]",
                     0.0);

  cout << "\033[36m---------------------------------------------------------\033[39m"
       << endl;

#if DUMP_DATA
  ms->dump("Merge Sort");
#endif
  delete ms;

  // Unit test for the quick sort.
  do_sort::quick_sort *qs = new do_sort::quick_sort();
  qs->init(DATA_SIZE);
  elapsed_time = qs->do_sort(true);
  report_test_result(static_cast<do_sort::sort*>(qs),
                     "Quick sort",
                     elapsed_time);

  qs->clear_data();
  qs->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(qs),
                     "Quick sort [corner case #1]",
                     0.0);

  qs->init(1);
  qs->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(qs),
                     "Quick sort [corner case #2]",
                     0.0);

  cout << "\033[36m---------------------------------------------------------\033[39m"
       << endl;

#if DUMP_DATA
  qs->dump("Quick Sort");
#endif
  delete qs;

  // Unit test for the strand sort.
  do_sort::strand_sort *sts = new do_sort::strand_sort();
  sts->init(DATA_SIZE);
  elapsed_time = sts->do_sort(true);
  report_test_result(static_cast<do_sort::sort*>(sts),
                     "Strand sort",
                     elapsed_time);

  sts->clear_data();
  sts->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(sts),
                     "Strand sort [corner case #1]",
                     0.0);

  sts->init(1);
  sts->do_sort(false);
  report_test_result(static_cast<do_sort::sort*>(sts),
                     "Strand sort [corner case #2]",
                     0.0);

#if DUMP_DATA
  sts->dump("Strand Sort");
#endif
  delete sts;

  cout << "---------------------------------------------------------"
       << endl
       << endl;

  return 0;
}

