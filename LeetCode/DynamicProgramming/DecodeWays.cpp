/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecodeWays.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:38:40 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/05/05 20:09:16 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 已知字母A-Z
 * 可以表示成数字1-26。给定一个数字串，求有多少种不同的字符串等价于这个 数字串。
 * Input: "226"
 * Output: 3
 */
int decode_ways(string str) {
  int len = str.size();
  if (len < 1)
    return 0;

  vector<int> dp(len + 1, 1);

  for (int i = 2; i <= len; ++i) {
    if (str[i - 2] - '2' <= 0) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = dp[i - 1];
    }
  }
  return dp[len];
}

int main() {
  string str = "446";
  int ret = decode_ways(str);
  cout << "result: " << ret << endl;
  return 0;
}