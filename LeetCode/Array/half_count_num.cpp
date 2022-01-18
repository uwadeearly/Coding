/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_count_num.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:39:46 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/18 20:48:58 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;
/* 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
 * 输出: 2
 */

int half_num(vector<int> &input) {
  int len = input.size();
  int half = len / 2, ret = -1;
  vector<int> record(len, 0);

  for (int i = 0; i < len; ++i) {
    record[input[i]]++;
  }
  for (int j = 0; j < len; ++j) {
    if (record[j] > half)
      ret = j;
  }

  return ret;
}

int main() {
  vector<int> input = {1, 2, 3, 2, 2, 2, 5, 4, 2};
  int ret = half_num(input);
  cout << "ret: " << ret << endl;
  return 0;
}