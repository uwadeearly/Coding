/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LongestCommonSubsequence.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:19:17 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/05/06 14:37:31 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 给定两个字符串，求它们最长的公共子序列长度。
 * 输入是两个字符串，输出是一个整数，表示它们满足题目条件的长度。
 * Input: text1 = "abcde", text2 = "ace"
 *  Output: 3
 */

int longest_common_subsquence(string left, string right) {
  int m = left.length();
  int n = right.length();
  if (m == 0 || n == 0) {
    return 0;
  }
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (left[i - 1] == right[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}

int main() {
  int ret = longest_common_subsquence("abcde", "ace");
  cout << "result: " << ret << endl;
  return 0;
}