
#include "../src/bubble_sort.h"
#include "../src/selection_sort.h"
#include "../src/insertion_sort.h"
#include "../src/strand_sort.h"
#include "../src/quick_sort.h"
#include "../src/merge_sort.h"
#include "../src/cocktail_sort.h"
#include "../src/gnome_sort.h"

#define DATA_SIZE 42000
#define FLOAT_CONST 937.32266
#define STRING_TEST_LEN 10

static const char alphanum[] = "0123456789"
                               "!@#$%^&*"
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "abcdefghijklmnopqrstuvwxyz";

using namespace std;

// Check whether the list is correctly sorted.
template <typename T>
bool is_sorted(do_sort::sort<T>* ss, bool asc) {
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
template <typename T>
void report_test_result(do_sort::sort<T>* ss,
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

// Initialize an "int" vector with the given size with some random data.
void init_int(vector<int>& v1,
              vector<int>& v2,
              vector<int>& v3,
              vector<int>& v4,
              LL s) {
  srand((unsigned)time(NULL));

  v1.clear();
  v2.clear();
  v3.clear();
  v4.clear();

  for (LL i = 0; i < s; ++i) {
    v1.push_back((int)rand() % s + 1);
  }

  v2.push_back(v1[0]);

  v3.push_back(v1[0]);
  v3.push_back(v1[1]);

  v4.push_back(v1[0]);
  v4.push_back(v1[1]);
  v4.push_back(v1[2]);
}

// Initialize a "float" vector with the given size with some random data.
void init_float(vector<float>& v1,
                vector<float>& v2,
                vector<float>& v3,
                vector<float>& v4,
                LL s) {
  srand((unsigned)time(NULL));

  v1.clear();
  v2.clear();
  v3.clear();
  v4.clear();

  for (LL i = 0; i < s; ++i) {
    v1.push_back((float)rand() / FLOAT_CONST);
  }

  v2.push_back(v1[0]);

  v3.push_back(v1[0]);
  v3.push_back(v1[1]);

  v4.push_back(v1[0]);
  v4.push_back(v1[1]);
  v4.push_back(v1[2]);
}

// Initialize a "double" vector with the given size with some random data.
void init_double(vector<double>& v1,
                 vector<double>& v2,
                 vector<double>& v3,
                 vector<double>& v4,
                 LL s) {
  srand((unsigned)time(NULL));

  v1.clear();
  v2.clear();
  v3.clear();
  v4.clear();

  for (LL i = 0; i < s; ++i) {
    v1.push_back((double)rand() / FLOAT_CONST);
  }

  v2.push_back(v1[0]);

  v3.push_back(v1[0]);
  v3.push_back(v1[1]);

  v4.push_back(v1[0]);
  v4.push_back(v1[1]);
  v4.push_back(v1[2]);
}

// Initialize a "char" vector with the given size with some random data.
void init_char(vector<char>& v1,
               vector<char>& v2,
               vector<char>& v3,
               vector<char>& v4,
               LL s) {
  srand((unsigned)time(NULL));

  v1.clear();
  v2.clear();
  v3.clear();
  v4.clear();

  for (LL i = 0; i < s; ++i) {
    v1.push_back((char)rand() % 256);
  }

  v2.push_back(v1[0]);

  v3.push_back(v1[0]);
  v3.push_back(v1[1]);

  v4.push_back(v1[0]);
  v4.push_back(v1[1]);
  v4.push_back(v1[2]);
}

// Initialize a "string" vector with the given size with some random data.
char genRandom() {
  return alphanum[rand() % (sizeof(alphanum) - 1)];
}

void init_str(vector<string>& v1,
              vector<string>& v2,
              vector<string>& v3,
              vector<string>& v4,
              LL s,
              LL l) {
  srand((unsigned)time(NULL));

  v1.clear();
  v2.clear();
  v3.clear();
  v4.clear();

  for (LL i = 0; i < s; ++i) {
    string ss = "";

    for (LL j = 0; j < l; ++j) {
      ss += genRandom();
    }

    v1.push_back(ss);
  }

  v2.push_back(v1[0]);

  v3.push_back(v1[0]);
  v3.push_back(v1[1]);

  v4.push_back(v1[0]);
  v4.push_back(v1[1]);
  v4.push_back(v1[2]);
}

template <typename T>
void run_test(do_sort::sort<T> *ptr,
              string method_name,
              bool dump,
              string type,
              vector<T>& v1,
              vector<T>& v2,
              vector<T>& v3,
              vector<T>& v4) {

  vector<T> v;

  // Random data is generated only for numeric types.
  ptr->set_data(v1);
  double elapsed_time = ptr->do_sort(true);
  report_test_result(ptr,
                     method_name + " [normal case #0]",
                     elapsed_time);

  if (dump) {
    ptr->dump(method_name.c_str());
  }

  ptr->clear_data();
  ptr->do_sort(false);
  report_test_result(ptr,
                     method_name + " [corner case #1]",
                     0.0);

  ptr->clear_data();
  ptr->set_data(v2);
  ptr->do_sort(false);
  report_test_result(ptr,
                     method_name + " [corner case #2]",
                     0.0);

  if (dump) {
    ptr->dump(method_name.c_str());
  }

  ptr->clear_data();
  ptr->set_data(v3);
  ptr->do_sort(false);
  report_test_result(ptr,
                     method_name + " [corner case #3]",
                     0.0);

  if (dump) {
    ptr->dump(method_name.c_str());
  }

  ptr->clear_data();
  ptr->set_data(v4);
  ptr->do_sort(false);
  report_test_result(ptr,
                     method_name + " [corner case #4]",
                     0.0);

  if (dump) {
    ptr->dump(method_name.c_str());
  }

  cout << "\033[36m---------------------------------------------------------\033[39m"
       << endl;
}

template <typename T>
void type_specific_test(string type,
                        vector<T>& v1,
                        vector<T>& v2,
                        vector<T>& v3,
                        vector<T>& v4) {
  string test_result = "";
  double elapsed_time = 0.0;

  cout << endl
       << endl
       << "-------------------- \033[34mTesting results for sorting an array with "
       << DATA_SIZE
       << " elements and type of "
       << type
       <<"\033[39m --------------------"
       << endl;

  // Unit test for the bubble sort.
  do_sort::bubble_sort<T> *bs = new do_sort::bubble_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(bs),
           "Bubble Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4);
  delete bs;

  // Unit test for the selection sort.
  do_sort::selection_sort<T> *ss = new do_sort::selection_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(ss),
           "Selection Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4);
  delete ss;

  // Unit test for the insertion sort.
  do_sort::insertion_sort<T> *is = new do_sort::insertion_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(is),
           "Insertion Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4);
  delete is;

  // Unit test for the merge sort.
  do_sort::merge_sort<T> *ms = new do_sort::merge_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(ms),
           "Merge Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4);
  delete ms;

  // Unit test for the quick sort.
  do_sort::quick_sort<T> *qs = new do_sort::quick_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(qs),
           "Quick Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4);
  delete qs;

  // Unit test for the strand sort.
  do_sort::strand_sort<T> *sts = new do_sort::strand_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(sts),
           "Strand Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4);
  delete sts;

  // Unit test for the cocktail sort.
  do_sort::cocktail_sort<T> *cts = new do_sort::cocktail_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(cts),
           "Cocktail Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4);
  delete cts;

  // Unit test for the gnome sort.
  do_sort::gnome_sort<T> *gs = new do_sort::gnome_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(gs),
           "Gnome Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4);
  delete gs;
}

int main() {
  vector<int> vint1, vint2, vint3, vint4;
  init_int(vint1, vint2, vint3, vint4, DATA_SIZE);
  type_specific_test<int>("int", vint1, vint2, vint3, vint4);

  vector<float> vfloat1, vfloat2, vfloat3, vfloat4;
  init_float(vfloat1, vfloat2, vfloat3, vfloat4, DATA_SIZE);
  type_specific_test<float>("float", vfloat1, vfloat2, vfloat3, vfloat4);

  vector<double> vdouble1, vdouble2, vdouble3, vdouble4;
  init_double(vdouble1, vdouble2, vdouble3, vdouble4, DATA_SIZE);
  type_specific_test<double>("double", vdouble1, vdouble2, vdouble3, vdouble4);

  vector<char> vchar1, vchar2, vchar3, vchar4;
  init_char(vchar1, vchar2, vchar3, vchar4, DATA_SIZE);
  type_specific_test<char>("char", vchar1, vchar2, vchar3, vchar4);

  vector<string> vstr1, vstr2, vstr3, vstr4;
  init_str(vstr1, vstr2, vstr3, vstr4, DATA_SIZE, STRING_TEST_LEN);
  type_specific_test<string>("string", vstr1, vstr2, vstr3, vstr4);

  return 0;
}

