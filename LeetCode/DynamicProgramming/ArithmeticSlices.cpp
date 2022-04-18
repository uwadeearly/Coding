/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArithmeticSlices.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:45:20 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/04/18 14:51:43 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/*
 * 给定一个数组，求这个数组中连续且等差的子数组一共有多少个。
 * 输入是一个一维数组，输出是满足等差条件的连续字数组个数。
 * Input: nums = [1,2,3,4]
 * Output: 3
 * 在这个样例中，等差数列有[1,2,3]、[2,3,4] 和[1,2,3,4]
 */

int arithmetic_slices(vector<int> &inputs) {
  int len = inputs.size();
  if (len < 3)
    return 0;
  if (len == 3)
    return 1;
  int count = 0;

  for (int i = 2; i < len; ++i) {
    if (inputs[i] - inputs[i - 1] == inputs[i - 1] - inputs[i - 2])
      count += i - 1;
  }
  return count;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  int res = arithmetic_slices(nums);
  cout << "result: " << res << endl;

  return 0;
}