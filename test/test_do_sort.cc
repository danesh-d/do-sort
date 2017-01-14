
#include "../src/bubble_sort.h"
#include "../src/selection_sort.h"
#include "../src/insertion_sort.h"
#include "../src/strand_sort.h"
#include "../src/quick_sort.h"
#include "../src/merge_sort.h"
#include "../src/cocktail_sort.h"
#include "../src/gnome_sort.h"
#include "../src/shell_sort.h"
#include "../src/tree_sort.h"

#define DATA_SIZE 42000
#define CUST_DATA_SIZE 10
#define FLOAT_CONST 937.32266
#define STRING_TEST_LEN 10

static const char alphanum[] = "0123456789"
                               "!@#$%^&*"
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "abcdefghijklmnopqrstuvwxyz";

class pers {
  public:
    int age;
    int ID;
    string first_name;
    string last_name;

    // Implement copy operator for the class.
    pers& operator=(const pers& p) {
      // check for self-assignment
      if (&p == this) {
        return *this;
      }

      age = p.age;
      ID = p.ID;
      first_name = p.first_name;
      last_name = p.last_name;

      return *this;
    }

    // Impolement comparison operators.
    bool operator==(const pers& p) {
      return (age == p.age);
    }

    bool operator!=(const pers& p) {
      return (age != p.age);
    }

    bool operator<=(const pers& p) {
      return (age <= p.age);
    }

    bool operator>=(const pers& p) {
      return (age >= p.age);
    }

    bool operator<(const pers& p) {
      return (age < p.age);
    }

    bool operator>(const pers& p) {
      return (age > p.age);
    }

    // Implement operator to send data to output stream.
    friend ostream& operator<<(ostream& os, pers& p) {
      os << "Age: " << p.age << endl;
      os << "ID: " << p.ID << endl;
      os << "First name: " << p.first_name << endl;
      os << "Last name: " << p.last_name << endl;
      return os;
    }
};

bool failed;

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
                        LD elapsed_time,
                        bool asc) {
  string test_result;

  if (is_sorted(ss, asc)) {
    test_result = "\033[32mPASSED";
  } else {
    test_result = "\033[31mFAILED";
    failed = true;
  }

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
              vector<T>& v4,
              bool asc) {

  vector<T> v;

  // Random data is generated only for numeric types.
  ptr->set_data(v1);
  LD elapsed_time = ptr->do_sort(true, asc);
  report_test_result(ptr,
                     method_name + " [normal case #0]",
                     elapsed_time,
                     asc);

  if (dump) {
    ptr->dump(method_name.c_str());
  }

  ptr->clear_data();
  ptr->do_sort(false, asc);
  report_test_result(ptr,
                     method_name + " [corner case #1]",
                     0.0,
                     asc);

  ptr->clear_data();
  ptr->set_data(v2);
  ptr->do_sort(false, asc);
  report_test_result(ptr,
                     method_name + " [corner case #2]",
                     0.0,
                     asc);

  if (dump) {
    ptr->dump(method_name.c_str());
  }

  ptr->clear_data();
  ptr->set_data(v3);
  ptr->do_sort(false, asc);
  report_test_result(ptr,
                     method_name + " [corner case #3]",
                     0.0,
                     asc);

  if (dump) {
    ptr->dump(method_name.c_str());
  }

  ptr->clear_data();
  ptr->set_data(v4);
  ptr->do_sort(false, asc);
  report_test_result(ptr,
                     method_name + " [corner case #4]",
                     0.0,
                     asc);

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
                        vector<T>& v4,
                        bool asc = true) {
  string test_result = "";

  cout << endl
       << endl
       << "-------------------- \033[34mTesting results for sorting an array with "
       << DATA_SIZE
       << " elements and type of "
       << type
       <<"\033[39m --------------------"
       << endl;

  // Unit test for the Bubble sort.
  do_sort::bubble_sort<T> *bs = new do_sort::bubble_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(bs),
           "Bubble Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete bs;

  // Unit test for the Shell sort.
  do_sort::shell_sort<T> *shs = new do_sort::shell_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(shs),
           "Shell Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete shs;

  // Unit test for the Selection sort.
  do_sort::selection_sort<T> *ss = new do_sort::selection_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(ss),
           "Selection Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete ss;

  // Unit test for the Insertion sort.
  do_sort::insertion_sort<T> *is = new do_sort::insertion_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(is),
           "Insertion Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete is;

  // Unit test for the Merge sort.
  do_sort::merge_sort<T> *ms = new do_sort::merge_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(ms),
           "Merge Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete ms;

  // Unit test for the Quick sort.
  do_sort::quick_sort<T> *qs = new do_sort::quick_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(qs),
           "Quick Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete qs;

  // Unit test for the Strand sort.
  do_sort::strand_sort<T> *sts = new do_sort::strand_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(sts),
           "Strand Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete sts;

  // Unit test for the Cocktail sort.
  do_sort::cocktail_sort<T> *cts = new do_sort::cocktail_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(cts),
           "Cocktail Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete cts;

  // Unit test for the Gnome sort.
  do_sort::gnome_sort<T> *gs = new do_sort::gnome_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(gs),
           "Gnome Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete gs;

  // Unit test for the Tree sort.
  do_sort::tree_sort<T> *ts = new do_sort::tree_sort<T>();
  run_test(static_cast<do_sort::sort<T>*>(ts),
           "Tree Sort",
           false,
           type,
           v1,
           v2,
           v3,
           v4,
           asc);
  delete ts;
}

int main() {
  failed = false;

  cout << endl << endl;

  cout << "***** Performing tests in ascending order *****" << endl;

  {
    vector<int> vint1, vint2, vint3, vint4;
    init_int(vint1, vint2, vint3, vint4, DATA_SIZE);
    type_specific_test<int>("int",
                            vint1,
                            vint2,
                            vint3,
                            vint4);

    vector<float> vfloat1, vfloat2, vfloat3, vfloat4;
    init_float(vfloat1, vfloat2, vfloat3, vfloat4, DATA_SIZE);
    type_specific_test<float>("float",
                              vfloat1,
                              vfloat2,
                              vfloat3,
                              vfloat4);

    vector<double> vdouble1, vdouble2, vdouble3, vdouble4;
    init_double(vdouble1, vdouble2, vdouble3, vdouble4, DATA_SIZE);
    type_specific_test<double>("double",
                               vdouble1,
                               vdouble2,
                               vdouble3,
                               vdouble4);

    vector<char> vchar1, vchar2, vchar3, vchar4;
    init_char(vchar1, vchar2, vchar3, vchar4, DATA_SIZE);
    type_specific_test<char>("char",
                             vchar1,
                             vchar2,
                             vchar3,
                             vchar4);

    vector<string> vstr1, vstr2, vstr3, vstr4;
    init_str(vstr1, vstr2, vstr3, vstr4, DATA_SIZE, STRING_TEST_LEN);
    type_specific_test<string>("string",
                               vstr1,
                               vstr2,
                               vstr3,
                               vstr4);
  }

  cout << endl << endl;

  cout << "***** Performing tests in descending order *****" << endl;

  {
    vector<int> vint1, vint2, vint3, vint4;
    init_int(vint1, vint2, vint3, vint4, DATA_SIZE);
    type_specific_test<int>("int",
                            vint1,
                            vint2,
                            vint3,
                            vint4,
                            false);

    vector<float> vfloat1, vfloat2, vfloat3, vfloat4;
    init_float(vfloat1, vfloat2, vfloat3, vfloat4, DATA_SIZE);
    type_specific_test<float>("float",
                              vfloat1,
                              vfloat2,
                              vfloat3,
                              vfloat4,
                              false);

    vector<double> vdouble1, vdouble2, vdouble3, vdouble4;
    init_double(vdouble1, vdouble2, vdouble3, vdouble4, DATA_SIZE);
    type_specific_test<double>("double",
                               vdouble1,
                               vdouble2,
                               vdouble3,
                               vdouble4,
                               false);

    vector<char> vchar1, vchar2, vchar3, vchar4;
    init_char(vchar1, vchar2, vchar3, vchar4, DATA_SIZE);
    type_specific_test<char>("char",
                             vchar1,
                             vchar2,
                             vchar3,
                             vchar4,
                             false);

    vector<string> vstr1, vstr2, vstr3, vstr4;
    init_str(vstr1, vstr2, vstr3, vstr4, DATA_SIZE, STRING_TEST_LEN);
    type_specific_test<string>("string",
                               vstr1,
                               vstr2,
                               vstr3,
                               vstr4,
                               false);
  }

  {
    vector<pers> persons(CUST_DATA_SIZE);

    persons[0].age = 38;
    persons[0].ID = 6677;
    persons[0].first_name = "Danesh";
    persons[0].last_name = "Daroui";

    persons[1].age = 22;
    persons[1].ID = 4234;
    persons[1].first_name = "Pontus";
    persons[1].last_name = "Orega";

    persons[2].age = 22;
    persons[2].ID = 3324;
    persons[2].first_name = "Rickard";
    persons[2].last_name = "Johannesson";

    persons[3].age = 65;
    persons[3].ID = 2211;
    persons[3].first_name = "Arif";
    persons[3].last_name = "Yarsani";

    persons[4].age = 54;
    persons[4].ID = 2877;
    persons[4].first_name = "Alex";
    persons[4].last_name = "Smith";

    persons[5].age = 17;
    persons[5].ID = 9942;
    persons[5].first_name = "Sarah";
    persons[5].last_name = "Warx";

    persons[6].age = 32;
    persons[6].ID = 8766;
    persons[6].first_name = "Monica";
    persons[6].last_name = "Cortiz";

    persons[7].age = 81;
    persons[7].ID = 3099;
    persons[7].first_name = "Simon";
    persons[7].last_name = "Thomson";

    persons[8].age = 42;
    persons[8].ID = 7812;
    persons[8].first_name = "Sofia";
    persons[8].last_name = "Andreasson";

    persons[9].age = 20;
    persons[9].ID = 7790;
    persons[9].first_name = "Anna";
    persons[9].last_name = "Krantz";

    cout << "----> Customized data before sorting:" << endl;
    for (int i = 0; i < CUST_DATA_SIZE; ++i) {
      pers pp = persons[i];
      cout << pp;
      cout << "------------" << endl;
    }

    cout << endl << endl;

    do_sort::bubble_sort<pers> bs;
    bs.set_data(persons);
    LD elapsed_time = bs.do_sort(true, true);

    cout << "----> Customized data after sorting (bubble sort) based on the age:"
         << endl;
    for (int i = 0; i < CUST_DATA_SIZE; ++i) {
      pers pp = bs[i];
      cout << pp;
      cout << "------------" << endl;
    }
  }

  cout << endl;
  if (failed) {
    cout << "At least one test has been failed." << endl;
  } else {
    cout << "All tests have been passed." << endl;
  }

  return 0;
}

