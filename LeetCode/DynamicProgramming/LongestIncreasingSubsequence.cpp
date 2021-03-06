/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LongestIncreasingSubsequence.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:11:01 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/05/06 14:14:05 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 输入是一个一维数组，输出是一个正整数，表示最长递增子序列的长度。
    Input: [10,9,2,5,3,7,101,18]
    Output: 4
 */

int longest_increasing_nums(vector<int> &inputs) {
  int len = inputs.size();
  vector<int> dp(len, 1);
  if (len <= 1) {
    return len;
  }

  for (int i = 1; i < len; ++i) {
    for (int j = 0; j < i; ++j) {
      if (inputs[i] > inputs[j]) {
        dp[i] = std::max(dp[i], dp[j]+1);
      } 
    }
  }

  for (auto &elem : dp) {
    cout << elem << ", ";
  }
  cout << endl;

  int ret = dp[len-1];
  return ret;
}

int main() {
  vector<int> inputs = {10, 9, 3, 5, 1, 1, 6};
  int ret = longest_increasing_nums(inputs);
  cout << "result: " << ret << endl;
  return 0;
}