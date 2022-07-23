/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure/RotaMatrix.cpp Path:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure Created Date: Saturday,
 * July 23rd 2022, 6:16:57 pm Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;

void rota_matrix(vector<vector<int>>& inputs) {
  int m = inputs.size();
  int n = inputs[0].size();

  for (int i=0; i < m/2; ++i) {
    for (int j=i; j < n-i-1; ++j) {
      int tmp = inputs[i][j];
      std::swap(tmp, inputs[j][n - 1 - i]);
      std::swap(tmp, inputs[m - 1 - i][n - 1 - j]);
      std::swap(tmp, inputs[m - 1 - j][i]);
      std::swap(tmp, inputs[i][j]);
    }
  }
}

int main() {
  vector<vector<int>> inputs = {
      {1, 2, 3, 4}, 
      {5, 6, 7, 8}, 
      {9, 10, 11, 12}, 
      {13, 14, 15, 16}};
  rota_matrix(inputs);
  for (const auto& elems : inputs) {
    for (const auto& elem : elems) {
      cout << elem << ", ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}