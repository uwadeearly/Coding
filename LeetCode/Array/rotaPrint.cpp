/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/Array/rotaPrint.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/Array
 * Created Date: Thursday, August 4th 2022, 9:45:49 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;

/* 旋转打印，给定一个整数n，顺时针顺序输出n^2的二维矩阵
 * n = 3
 * 1, 2, 3
 * 8, 9, 4
 * 7, 6, 5
 */

void rotaPrint(vector<vector<int>>& arr) {}

vector<vector<int>> rotaMtrix(int n) {
  vector<vector<int>> out(n, vector<int>(n));
  int count = 1;
  for (int i = 0; i < n / 2; ++i) {
    for (int j = i; j < n - i; ++j) {
      out[i][j] = count++;
    }

    for (int k = i + 1; k < n-i; ++k) {
      out[k][n - i - 1] = count++;
    }

    for (int p = n - i - 2; p >= i; --p) {
      out[n - i - 1][p] = count++;
    }
    for (int q = n - i - 2; q > i; --q) {
      out[q][i] = count++;
    }
  }
  if (n % 2) {
    out[(n-1) / 2][(n-1) / 2] = n * n;
  }
  return out;
}

int main() {
  int n = 5;
  auto out = rotaMtrix(n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << out[i][j] << ", ";
    }
    cout << endl;
  }

  return 0;
}