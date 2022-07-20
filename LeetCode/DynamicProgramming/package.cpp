/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/DynamicProgramming/pakeg.cpp Path:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/DynamicProgramming Created Date:
 * Sunday, July 10th 2022, 4:29:18 pm Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

//背包问题
/* finde dp[i][j]
 * transfer fucntion
  n 个包 每个包都有自己的重量 w 和价值 v
  dp[i][j] 表示前i个包在不超过j的重量下的最大价值
 */
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& pkgValues, vector<int>& pkgWeights,
             int totalWeights) {
  int pkgNums = pkgValues.size();
  vector<vector<int>> dp(pkgNums + 1, vector<int>(totalWeights + 1, 0));

  for (int i = 1; i < pkgNums + 1; ++i) {
    int v = pkgValues[i - 1];
    int w = pkgWeights[i - 1];

    for (int j = 1; j < totalWeights + 1; ++j) {
      if (j > w) {
        dp[i][j] = max(dp[i - 1][j], dp[i-1][j-w] + v);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[pkgNums][totalWeights];
}

int main() { return 0; }