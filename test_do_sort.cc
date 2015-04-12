
#include "do_sort.h"

#define DATA_SIZE 20
#define DUMP_DATA 0

using namespace std;

bool is_sorted(do_sort::sort* ss) {
  for (int i = 0; i < ss->size() - 1; ++i)
    if ((*ss)[i] > (*ss)[i + 1])
      return false;

  return true;
}


int main() {
  string test_result = "";

  do_sort::bubble_sort *bs = new do_sort::bubble_sort();
  bs->init(DATA_SIZE);
  bs->do_sort();
  test_result = (is_sorted(bs)) ? "\033[32mPASSED" : "\033[31mFAILED";
  cout << "Bubble sort test --> " << "[" << test_result << "\033[39m]" << endl;;
#if DUMP_DATA
  bs->dump("Bubble Sort");
#endif
  delete bs;

  do_sort::insertion_sort *is = new do_sort::insertion_sort();
  is->init(DATA_SIZE);
  is->do_sort();
  test_result = (is_sorted(is)) ? "\033[32mPASSED" : "\033[31mFAILED";
  cout << "Insertion sort test --> " << "[" << test_result << "\033[39m]" << endl;;
#if DUMP_DATA
  is->dump("Insertion Sort");
#endif
  delete is;

  do_sort::merge_sort *ms = new do_sort::merge_sort();
  ms->init(DATA_SIZE);
  ms->do_sort();
  test_result = (is_sorted(ms)) ? "\033[32mPASSED" : "\033[31mFAILED";
  cout << "Merge sort test --> " << "[" << test_result << "\033[39m]" << endl;;
#if DUMP_DATA
  ms->dump("Merge Sort");
#endif
  delete ms;

  return 0;
}

