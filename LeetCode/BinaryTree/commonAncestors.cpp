/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/BinaryTree/commonAnsert.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/BinaryTree
 * Created Date: Friday, September 2nd 2022, 10:13:16 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val_) : val(val_), left(nullptr), right(nullptr) {}
};

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr || p == nullptr || q == nullptr) {
    return nullptr;
  }

  if (root == p || root == q) {
    return root;
  }

  TreeNode* left = commonAncestor(root->left, p, q);
  TreeNode* right = commonAncestor(root->right, p, q);
  if (right == nullptr) {
    return left;
  } else if (left == nullptr) {
    return right;
  } else {
    return root;
  }
}

int main() { return 0; }