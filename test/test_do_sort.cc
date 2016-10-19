
#include "../src/bubble_sort.h"
#include "../src/selection_sort.h"
#include "../src/insertion_sort.h"
#include "../src/strand_sort.h"
#include "../src/quick_sort.h"
#include "../src/merge_sort.h"
#include "../src/cocktail_sort.h"
#include "../src/gnome_sort.h"

#define DATA_SIZE 30000

using namespace std;

// Check whether the list is correctly sorted.
bool is_sorted(do_sort::sort* ss, bool asc) {
  if (ss->empty()) {
    return true;
  }

  for (int i = 0; i < ss->size() - 1; ++i) {
    if (asc) {
      // Check if the list is sorted in ascending order.
      if ((*ss)[i] > (*ss)[i + 1]) {
        return false;
      }
    } else {
      // Check if the list is sorted in descending order.
      if ((*ss)[i] < (*ss)[i + 1]) {
        return false;
      }
    }
  }

  return true;
}

// Report the testing results.
void report_test_result(do_sort::sort* ss,
                        string sorting_method,
                        double elapsed_time) {
  string test_result = (is_sorted(ss, true)) ?
                        "\033[32mPASSED" :
                        "\033[31mFAILED";
  if (elapsed_time > 0.0) {
    cout << sorting_method
         << " test --> "
         << "["
         << test_result
         << "\033[39m] --> Elapsed time is "
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

void run_test(do_sort::sort *ptr, string method_name, bool dump) {
  ptr->init(DATA_SIZE);
  double elapsed_time = ptr->do_sort(true);
  report_test_result(ptr,
                     method_name + " [normal case #0]",
                     elapsed_time);

  ptr->clear_data();
  ptr->do_sort(false);
  report_test_result(ptr,
                     method_name + " [corner case #1]",
                     0.0);

  ptr->init(1);
  ptr->do_sort(false);
  report_test_result(ptr,
                     method_name + " [corner case #2]",
                     0.0);

  ptr->init(2);
  ptr->do_sort(false);
  report_test_result(ptr,
                     method_name + " [corner case #3]",
                     0.0);

  ptr->init(3);
  ptr->do_sort(false);
  report_test_result(ptr,
                     method_name + " [corner case #4]",
                     0.0);

  cout << "\033[36m---------------------------------------------------------\033[39m"
       << endl;

  if (dump) {
    ptr->dump(method_name.c_str());
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
  run_test(static_cast<do_sort::sort*>(bs), "Bubble Sort", false);
  delete bs;

  // Unit test for the selection sort.
  do_sort::selection_sort *ss = new do_sort::selection_sort();
  run_test(static_cast<do_sort::sort*>(ss), "Selection Sort", false);
  delete ss;

  // Unit test for the insertion sort.
  do_sort::insertion_sort *is = new do_sort::insertion_sort();
  run_test(static_cast<do_sort::sort*>(is), "Insertion Sort", false);
  delete is;

  // Unit test for the merge sort.
  do_sort::merge_sort *ms = new do_sort::merge_sort();
  run_test(static_cast<do_sort::sort*>(ms), "Merge Sort", false);
  delete ms;

  // Unit test for the quick sort.
  do_sort::quick_sort *qs = new do_sort::quick_sort();
  run_test(static_cast<do_sort::sort*>(qs), "Quick Sort", false);
  delete qs;

  // Unit test for the strand sort.
  do_sort::strand_sort *sts = new do_sort::strand_sort();
  run_test(static_cast<do_sort::sort*>(sts), "Strand Sort", false);
  delete sts;

  // Unit test for the cocktail sort.
  do_sort::cocktail_sort *cts = new do_sort::cocktail_sort();
  run_test(static_cast<do_sort::sort*>(cts), "Cocktail Sort", false);
  delete cts;

  // Unit test for the gnome sort.
  do_sort::gnome_sort *gs = new do_sort::gnome_sort();
  run_test(static_cast<do_sort::sort*>(gs), "Gnome Sort", false);
  delete gs;

  return 0;
}

