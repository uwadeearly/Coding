/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/BackTracking/Combination.cpp Path:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/BackTracking Created Date: Thursday,
 * August 25th 2022, 5:15:20 pm Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;

void backTacking(vector<vector<int>>& result, vector<int>& path, int start,
                 int m, int n) {
  if (path.size() == n) {
    result.push_back(path);
    return;
  }

  for (int i = start; i <= m; ++i) {
    path.push_back(i);
    backTacking(result, path, i + 1, m, n);
    path.pop_back();
  }
}

vector<vector<int>> solution(int m, int n) {
  vector<vector<int>> result;
  vector<int> path;
  backTacking(result, path, 1, m, n);
  return result;
}

int main() {
  auto ret = solution(4, 3);
  for (const auto& elems : ret) {
    for (const auto& elem : elems) {
      cout << elem << ", ";
    }
    cout << endl;
  }
  return 0;
}