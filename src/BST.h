#ifndef BST_H
#define BST_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Binary Search Tree (BST).
  template <class T>
  class BST {
    private:
      ULL num_nodes;
      vector<T> intern_vec;

      // The structure uses only pointers to the original data in the tree.
      // Therefore, the data will be dumped when it is needed into an internal
      // vectore before it is returned. This is mostly done for the sake of
      // efficiency first to avoid copying data and also to support non-POD data
      // types like strings.
      struct btree {
        T *key;
        struct btree *left, *right;
      };

      struct btree *root;

      // Add a new hanging node.
      struct btree* newNode(T *key) {
        struct btree *temp = new btree;
        temp->key = key;
        temp->left = temp->right = nullptr;

        return temp;
      }

      struct btree* tree_insert(struct btree *node, T *key) {
        // If the tree is empty, return a new node.
        if (node == nullptr) {
          // The first node is always root.
          if (num_nodes == 1) {
            root = newNode(key);
            return root;
          }

          return newNode(key);
        }

        // Otherwise, recur down the tree.
        if (*key <= *(node->key)) {
          node->left = tree_insert(node->left, key);
        } else if (key > node->key) {
          node->right = tree_insert(node->right, key);
        }
      }

      // Traverse the BST and return all sorted nodes in the ascending order.
      void tree_inorder_ascending(struct btree *node) {
        if (node != nullptr) {
          tree_inorder_ascending(node->left);
          intern_vec.push_back(*(node->key));
          tree_inorder_ascending(node->right);
        }
      }

      // Traverse the BST and return all sorted nodes in the descending order.
      void tree_inorder_descending(struct btree *node) {
        if (node != nullptr) {
          tree_inorder_descending(node->right);
          intern_vec.push_back(*(node->key));
          tree_inorder_descending(node->left);
        }
      }

      // Destroy the subtree from a node, or the whole tree if node points to
      // the root of the BST.
      void tree_destroy(struct btree *node) {
        if (node != nullptr) {
          // First destroy subtrees.
          tree_destroy(node->left);
          tree_destroy(node->right);

          // Node release the node and make to point to nullptr.
          delete node;

          --num_nodes;

          node->left = nullptr;
          node->right = nullptr;
          node = nullptr;
        }
      }

      // Return depth of the tree. Zero will be returned if the tree is empty.
      LL tree_depth(struct btree *node)  {
        return node ? max(tree_depth(node->left),
                          tree_depth(node->right)) + 1
                    : 0;
      }

      // Return number of nodes in the tree. Note that the result of this
      // function will be equal to "num_nodes" variable only if the function is
      // called from root. Otherwise, the function will retuen number of the
      // nodes from the given node.
      LL tree_num_nodes(struct btree *node) {
        return node ? tree_num_nodes(node->left) +
                      tree_num_nodes(node->right) + 1
                    : 0;
      }

      LL clear_tree() {
        root = nullptr;
        num_nodes = 0;
        intern_vec.clear();
      }

    protected:
      bool is_empty() {
        return (root == nullptr);
      }

      // Insert a key into a BST. It will remain sorted.
      void insert(T *key) {
        ++num_nodes;
        tree_insert(root, key);
      }

      // Dump the BST in ascending or descending order.
      void dump(vector<T>& vec, bool asc) {
        if (asc) {
          tree_inorder_ascending(root);
        } else {
          tree_inorder_descending(root);
        }

        vec = intern_vec;
      }

      // Destroy the current tree.
      void destroy() {
        tree_destroy(root);
        clear_tree();
      }

    public:
      BST() {
        clear_tree();
      }

      virtual ~BST() {
        // If the tree is not destroyed yet, destroy it before the class'
        // instance is being released.
        if (num_nodes > 0) {
          destroy();
        }
      }
  };
}

#endif /* BST_H */

