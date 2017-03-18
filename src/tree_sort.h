#ifndef TREE_SORT_H
#define TREE_SORT_H

#include "do_sort.h"
#include "BST.h"

using namespace std;

namespace do_sort {
  // --- Tree sort.
  template <class T>
  class tree_sort : public sort<T>, private BST<T> {
    private:
      void create_tree(vector<T>& v, LL n) {
        // Construct the BST from the input data.
        for (LL i = 0; i < n; i++) {
          BST<T>::insert(&v[i]);
        }
      }

      void read_tree(vector<T>& v, bool asc) {
        // Dump the tree either in ascending or descending order.
        BST<T>::dump(v, asc);
      }

      void destroy_tree() {
        // Destroy the sorted tree i.e BST based on the input data.
        BST<T>::destroy();
      }

    protected:
      void specific_do_sort() {
        LL n = sort<T>::size();

        if (n <= 1) {
          return;
        }

        // Create a sorted tree.
        create_tree(sort<T>::v, n);

        // Read back the tree elements in a sorted fashion.
        read_tree(sort<T>::v, sort<T>::asc);

        // Destroy the tree from its root.
        destroy_tree();
      }

    public:
      tree_sort() {
      }

      virtual ~tree_sort() {
      }
  };
}

#endif /* TREE_SORT_H */

