/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:50:45 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/02/11 20:20:30 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int val;
  Node *left = nullptr;
  Node *right = nullptr;
};

/*preoder traversal*/
/*recursion*/
void PreOrderRec(Node *node) {
  if (node == nullptr)
    return;

  cout << node->val << ", ";
  PreOrderRec(node->left);
  PreOrderRec(node->right);
}

/*loop no recursion*/
void PreOrderNoRec(Node *node) {
  if (node == nullptr)
    return;

  stack<Node *> node_s;
  cout << node->val << ", ";

  node_s.push(node);
  node = node->left;

  while (!node_s.empty() || node) {
    while (node) {
      cout << node->val << ", ";
      node_s.push(node);
      node = node->left;
    }

    node = node_s.top()->right;
    node_s.pop();
  }
}

/*middle order travseral*/
/*recursion*/

void InOrderRec(Node *node) {
  if (node == nullptr)
    return;

  InOrderRec(node->left);
  cout << node->val << ", ";
  InOrderRec(node->right);
}

/*loop no recursion*/
void InOrderNoRec(Node *node) {
  if (node == nullptr)
    return;

  stack<Node *> node_s;

  node_s.push(node);
  node = node->left;

  while (!node_s.empty() || node) {
    while (node) {
      node_s.push(node);
      node = node->left;
    }

    cout << node_s.top()->val << ", ";
    node = node_s.top()->right;
    node_s.pop();
  }
}

/*post order travseral*/
/*recursion*/
void PostOrderRec(Node *node) {
  if (node == nullptr)
    return;
  PostOrderRec(node->left);
  PostOrderRec(node->right);
  cout << node->val << ", ";
}

/*loop no recursion*/
void PostOrderNoRec(Node *node) {}

void secondMax(Node *node, int* ret) {
  static int nums;
  if (nums == 2 || node == nullptr) {
    return;
  } else {
    ++nums;
    secondMax(node->right, ret);
    *ret = node->val;
    secondMax(node->left, ret);
  }
}

int max_depth(Node *node) {
  if (node == nullptr)
    return 0;
 
  int left = 1 + max_depth(node->left);
  int right = 1 + max_depth(node->right);
  return left > right ? left : right;
}

int main() {
  Node* Tree = new Node;
  Tree->val = 11;
  Tree->left = new Node;
  Tree->left->val = 10;
  
  Tree->right = new Node;
  Tree->right->val = 12;
  int ret=0;
  secondMax(Tree, &ret);
  cout << "ret: " << ret << endl;
     
  return 0; }