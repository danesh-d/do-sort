#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/bubble_sort.h"

#include <vector>
#include <string>
#include <iostream>

const ULL VEC_SIZE = 1e4;
const double DOUBLE_COEFF = 7.1123454;

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

inline ULL randNumInt() {
  return (std::rand() % VEC_SIZE);
}

inline ULL randNumDouble() {
  return (std::rand() % VEC_SIZE) * DOUBLE_COEFF;
}

// Mock the "bubble_sort" class only with any given type.
template <typename T>
class mock_bubble_sort : public do_sort::bubble_sort<T> {
  public:
    MOCK_METHOD0(clear_data, void());
    MOCK_METHOD0(specific_do_sort, void());
    MOCK_METHOD1_T(get_data_at, T(size_t));
    MOCK_METHOD1_T(set_data, size_t(std::vector<T>&));
};

template <typename T>
class bubble_sort_wrapper {
  private:
    do_sort::bubble_sort<T> *m_bs;

  public:
    bubble_sort_wrapper(do_sort::bubble_sort<T> *bs) : m_bs(bs) {
      if (!bs) {
        std::cout << "The object could not be created." << std::endl;
      }
    }

    void clear_data() {
      m_bs->clear_data();
    };

    void specific_do_sort() {
      m_bs->specific_do_sort();
    }

    T get_data_at(size_t i) {
      return m_bs->get_data_at(i);
    }

    size_t set_data(std::vector<T>& v) {
      return m_bs->set_data(v);
    }

    // Not mocked, but just a wrapper to call the specific sort function for
    // each algorithm.
    LD do_sort(bool elapsed_time, bool asc = true) {
      return m_bs->do_sort(elapsed_time, asc);
    }
};

std::vector<int> v_int, expected_v_int;
std::vector<double> v_double, expected_v_double;

// Initialize the vector with random values with integer type.
void initVecInt() {
  v_int.clear();
  v_int.resize(VEC_SIZE);

  std::srand(0);
  std::generate(v_int.begin(), v_int.end(), randNumInt);
}

// Initialize the vector with random values with double type.
void initVecDouble() {
  v_double.clear();
  v_double.resize(VEC_SIZE);

  std::srand(0);
  std::generate(v_double.begin(), v_double.end(), randNumDouble);
}

TEST(SortingTest, BubbleSortMockedTest) {
  initVecInt();

  expected_v_int = v_int;

  // Make sure that the arrays are identical before sorting process is started.
  EXPECT_EQ(v_int, expected_v_int);

  std::sort(expected_v_int.begin(), expected_v_int.end());  

  mock_bubble_sort<int> mbs;
  bubble_sort_wrapper<int> bsw(&mbs);

  EXPECT_CALL(mbs, clear_data()).Times(1);
  EXPECT_CALL(mbs, set_data(v_int)).Times(1);
  EXPECT_CALL(mbs, specific_do_sort()).Times(1);

  bsw.clear_data();
  bsw.set_data(v_int);
  bsw.do_sort(false);
}

// Test Bubble sort with an array of integer data.
TEST(SortingTest, BubbleSortTestInt) {
  initVecInt();

  expected_v_int = v_int;

  EXPECT_EQ(v_int, expected_v_int);

  std::sort(expected_v_int.begin(), expected_v_int.end());  

  do_sort::bubble_sort<int> bs;

  bs.clear_data();
  bs.set_data(v_int);
  bs.do_sort(true, true);

  EXPECT_EQ(bs.getResult(), expected_v_int);
}

// Test Bubble sort with an array of double data.
TEST(SortingTest, BubbleSortTestDouble) {
  initVecDouble();

  expected_v_double = v_double;

  EXPECT_EQ(v_double, expected_v_double);

  std::sort(expected_v_double.begin(), expected_v_double.end());  

  do_sort::bubble_sort<double> bs;

  bs.clear_data();
  bs.set_data(v_double);
  bs.do_sort(true, true);

  EXPECT_EQ(bs.getResult(), expected_v_double);
}

