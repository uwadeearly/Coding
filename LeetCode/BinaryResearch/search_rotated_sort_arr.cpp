/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_rotated_sort_arr.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:38:35 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/11 21:05:04 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

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

  for (int i = 0; i < len; ++i) {
    if (arr[i - 1] > arr[i]) {
      pos = i + 1;
      break;
    }
  }
  state = binary_search(arr, 0, pos, target);
  state = binary_search(arr, pos + 1, len - 1, target);
  return state;
}

int main() { return 0; }