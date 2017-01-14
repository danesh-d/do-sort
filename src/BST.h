#ifndef BST_H
#define BST_H

#include "do_sort.h"

using namespace std;

namespace do_sort {
  // --- Binary Search Tree (BST).
  template <class T>
  class BST {
    private:
      struct btree {
        T key;
        struct btree *left, *right;
      };

      struct btree *root;

      // Add a new hanging node.
      struct btree* newNode(T key) {
        struct btree *temp = new btree;
        temp->key = key;
        temp->left = temp->right = NULL;

        return temp;
      }

      struct btree* tree_insert(struct btree *node, T key) {
        // If the tree is empty, return a new node.
        if (node == NULL) {
          return newNode(key);
        }

        // Otherwise, recur down the tree.
        if (key <= node->key) {
          node->left = tree_insert(node->left, key);
        } else if (key > node->key) {
          node->right = tree_insert(node->right, key);
        }
      }

      // Traverse the BST and return all sorted nodes in the ascending order.
      void tree_inorder_ascending(struct btree *node, vector<T>& arr) {
        if (node != NULL) {
          tree_inorder_ascending(node->left, arr);
          arr.push_back(node->key);
          tree_inorder_ascending(node->right, arr);
        }
      }

      // Traverse the BST and return all sorted nodes in the descending order.
      void tree_inorder_descending(struct btree *node, vector<T>& arr) {
        if (root != NULL) {
          tree_inorder_ascending(node->right, arr);
          arr.push_back(node->key);
          tree_inorder_ascending(node->left, arr);
        }
      }

      // Destroy the subtree from a node, or the whole tree if node points to
      // the root of the BST.
      void tree_destroy(struct btree *node) {
        if (node != NULL) {
          // First destroy subtrees.
          tree_destroy(node->left);
          tree_destroy(node->right);

          // Node release the node and make to point to NULL.
          delete node;

          if (node->left != NULL) {
            node->left = NULL;
          }

          if (node->right != NULL) {
            node->right = NULL;
          }

          node = NULL;
        }
      }

      // Return depth of the tree. Zero will be returned if the tree is empty.
      LL tree_depth(struct btree *node)  {
        return node ? max(tree_depth(node->left),
                          tree_depth(node->right)) + 1
                    : 0;
      }

      // Return number of nodes in the tree.
      LL tree_num_nodes(struct btree *node) {
        return node ? num_nodes(node->left) + num_nodes(node->right) + 1 : 0;
      }

    protected:
      bool is_empty() {
        return (root == NULL);
      }

      // Insert a key into a BST. It will remain sorted.
      void insert(T key) {
        tree_insert(root, key);
      }

      // Dump the BST in ascending or descending order.
      void dump(vector<T>& arr, bool asc) {
        if (asc) {
          tree_inorder_ascending(root, arr);
        } else {
          tree_inorder_descending(root, arr);
        }
      }

      // Destroy the current tree.
      void destroy() {
        tree_destroy(root);
      }

    public:
      BST() {
        root = NULL;
      }

      virtual ~BST() {
        // If the tree is not destroyed yet, destroy it before the class'
        // instance is being released.
        tree_destroy(root);
      }
  };
}

#endif /* BST_H */

