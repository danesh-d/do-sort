#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "do_sort.h"

#define MAX_GAPS 9

using namespace std;

namespace do_sort {
  // --- Shell sort implementation.
  template <class T>
  class shell_sort : public sort<T> {
    protected:
      void specific_do_sort() {
        LL n = this->size();

        if (n <= 1) {
          return;
        }

        // Different gap sequences can be used. The gap sequence which is used
        // here is the original sequence which is [n / 2 ^ k].
        if (this->asc) {
          for (LL gap = n / 2; gap > 0; gap /= 2) {
            for (LL i = gap; i < n; ++i) {
              for (LL j = i - gap;
                   j >= 0 && this->v[j] > this->v[j + gap];
                   j -= gap) {
                swap(this->v[j + gap], this->v[j]);
              }
            }
          }
        } else {
          for (LL gap = n / 2; gap > 0; gap /= 2) {
            for (LL i = gap; i < n; ++i) {
              for (LL j = i - gap;
                   j >= 0 && this->v[j] < this->v[j + gap];
                   j -= gap) {
                swap(this->v[j + gap], this->v[j]);
              }
            }
          }
        }
      }

    public:
      shell_sort() {
      }

      ~shell_sort() {
      }
  };
}

#endif /* SHELL_SORT_H */

