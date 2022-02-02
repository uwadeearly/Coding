/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergSortArray.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:42:55 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/05 14:36:08 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 给定两个有序数组，把两个数组合并为一个。
 * 输入是两个数组和它们分别的长度m 和n。其中第一个数组的长度被延长至m +
 * n，多出的 n 位被0
 * 填补。题目要求把第二个数组归并到第一个数组上，不需要开辟额外空间。 Input:
 * nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 Output: nums1 =
 * [1,2,2,3,5,6]
 */
void merge_sort_arr(vector<int> &num1, vector<int> &num2, int m, int n) {
  int len = m, index_one = m - n - 1, index_two = n - 1;
  int one, two;
  for (int i = len - 1; i >= 0; --i) {
    one = index_one >= 0 ? num1[index_one] : 0;
    two = index_two >= 0 ? num2[index_two] : 0;

    if (one >= two) {
      num1[i] = one;
      --index_one;
    } else {
      num1[i] = two;
      --index_two;
    }
  }
}

int main() {
  vector<int> num1 = {1, 2, 3, 0, 0, 0};
  vector<int> num2 = {2, 5, 6};

  merge_sort_arr(num1, num2, 6, 3);
  for (auto &elem : num1) {
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}