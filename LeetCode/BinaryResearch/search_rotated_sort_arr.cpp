/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_rotated_sort_arr.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:38:35 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/13 10:44:17 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;
/* 一个原本增序的数组被首尾相连后按某个位置断开（如[1,2,2,3,4,5] !
 * [2,3,4,5,1,2]，在第一
 * 位和第二位断开），我们称其为旋转数组。给定一个值，判断这个值是否存在于这个为旋转数组中。
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 */

bool binary_search(vector<int> &arr, int left, int right, int target) {
  int mid, l = left, r = right;
  while (l <= r) {
    mid = (l + r) / 2;
    if (target < arr[mid]) {
      r = mid - 1;
    } else if (target > arr[mid]) {
      l = mid + 1;
    } else {
      return true;
    }
  }
  return false;
}
bool search_rotated_array(vector<int> &arr, int target) {
  int len = arr.size(), pos;
  bool state;

  for (int i = 1; i < len; ++i) {
    if (arr[i - 1] > arr[i]) {
      pos = i + 1;
      break;
    }
  }
  cout << "bounary: " << pos << endl;
  state = binary_search(arr, 0, pos-1, target);
  state = binary_search(arr, pos, len - 1, target);
  return state;
}

int main() {
  vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
  int target = 0;
  bool state = search_rotated_array(arr, target);
  cout << "state: " << state << endl;
  return 0;
}