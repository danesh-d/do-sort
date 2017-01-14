#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "do_sort.h"

#define MAX_GAPS 9

using namespace std;

namespace do_sort {
  // --- Shell sort implementation.
  template <class T>
  class shell_sort : public sort<T> {
    private:
      vector<LL> gaps;

      // This function generates the sequence of gaps. The original
      // implementation is baed on the origtinal sequence used in the Shell's
      // algorithm. However, other sequence of gaps such as Knuth's can be used.
      // In that case, the user needs to re-implement the gap generator.
      void generate_gaps(LL n) {
        LL gap = n;

        while ((gap = gap >> 1) > 0) {
          gaps.push_back(gap);
        }
      }

    protected:
      void specific_do_sort() {
        LL n = sort<T>::size();

        if (n <= 1) {
          return;
        }

        // Generate sequence of gaps where the sorting (far elements first) will
        // be based on this sequence.
        generate_gaps(n);

        // Different gap sequences can be used. The gap sequence which is used
        // here is the original sequence which is [n / 2 ^ k].
        if (sort<T>::asc) {
          for (vector<LL>::iterator it = gaps.begin(); it != gaps.end(); ++it) {
            LL gap = *it;
            for (LL i = gap; i < n; ++i) {
              for (LL j = i - gap;
                   j >= 0 && sort<T>::v[j] > sort<T>::v[j + gap];
                   j -= gap) {
                swap(sort<T>::v[j + gap], sort<T>::v[j]);
              }
            }
          }
        } else {
          for (vector<LL>::iterator it = gaps.begin(); it != gaps.end(); ++it) {
            LL gap = *it;
            for (LL i = gap; i < n; ++i) {
              for (LL j = i - gap;
                   j >= 0 && sort<T>::v[j] < sort<T>::v[j + gap];
                   j -= gap) {
                swap(sort<T>::v[j + gap], sort<T>::v[j]);
              }
            }
          }
        }
      }

    public:
      shell_sort() {
        gaps.clear();
      }

      virtual ~shell_sort() {
        gaps.clear();
      }
  };
}

#endif /* SHELL_SORT_H */

