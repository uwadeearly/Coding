/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaximalSquare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:38:54 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/05/05 17:06:36 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 给定一个二维的0-1 矩阵，求全由1 构成的最大正方形面积。
 * 输入是一个二维0-1 数组，输出是最大正方形面积。
    Input:
    [["1","0","1","0","0"],
     ["1","0","1","1","1"],
     ["1","1","1","1","1"],
     ["1","0","0","1","0"]]
    Output: 4
*/

int maximal_square(vector<vector<char>> &inputs) {
  if (inputs.empty() || inputs[0].empty()) {
    return 0;
  }
  int rows = inputs.size();
  int cols = inputs[0].size();
  vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
  int max_side = 0;

  for (int i = 1; i < rows; ++i) {
    for (int j = 1; j < cols; ++j) {
      if (inputs[i - 1][j - 1] == '1') {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
      }
      max_side = std::max(max_side, dp[i][j]);
    }
  }
  return max_side * max_side;
}

int main() { return 0; }