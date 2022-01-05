/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TwoSum.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:15:11 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/04 16:39:33 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/* 在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。
 * 输入是一个数组（numbers）和一个给定值（target）。输出是两个数的位置，从1
 * 开始计数。 Input: numbers = [2,7,11,15], target = 9 Output: [1,2]
 * 在这个样例中，第一个数字（2）和第二个数字（7）的和等于给定值（9）。
 */

vector<int> two_sum(vector<int> &numbers, int target) {
  vector<int> ret(2);
  int len = numbers.size(), ret_tmp;

  for (int i = 0; i < len; ++i) {
    for (int j = i; j < len; ++j) {
      ret_tmp = numbers[i] + numbers[j];

      if (ret_tmp == target) {
        ret[0] = i + 1;
        ret[1] = j + 1;
        break;
      }
    }
  }
  return ret;
}

vector<int> TwoSum(vector<int> &numbers, int target) {
  int len = numbers.size();
  int l = 0, r = len - 1, sum = 0;

  while (l < r) {
    sum = numbers[l] + numbers[r];
    if (sum == target)
      break;
    else if (sum < target)
      l++;
    else
      r--;
  }
  return vector<int> {l + 1, r + 1};
}

int main() {
  vector<int> inputs = {2, 7, 9, 11, 15};
  // vector<int> ret = two_sum(inputs, 9);
  vector<int> ret = TwoSum(inputs, 9);
  for (auto &elem : ret) {
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}