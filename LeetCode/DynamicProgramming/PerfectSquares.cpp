/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PerfectSquares.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:08:13 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/05/05 17:48:05 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 给定一个正整数，求其最少可以由几个完全平方数相加构成。
 * 输入是给定的正整数，输出也是一个正整数，表示输入的数字最少可以由几个完全平方数相
 * 加构成。
 * Input: n = 13
 * Output: 2
 * c = a**2 + b**2
 */

int min_num(int nums) {
  vector<int> ret(nums + 1, INT8_MAX);
  ret[0] = 0;
  for (int i = 1; i <= nums; ++i) {
    for (int j = 1; j*j <= i; ++j) {
      ret[i] = std::min(ret[i], ret[i-j*j] + 1);
    }
  }
  return ret[nums];
}

int main() {
  int nums = 13;
  int ret = min_num(nums);
  cout << "result: " << ret << endl;
  return 0;
}