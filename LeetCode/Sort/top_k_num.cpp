/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_k_num.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:55:49 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/19 20:22:00 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 在一个未排序的数组中，找到第k 大的数字。
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 */

// last poor
int top_k_num(vector<int> &arr, int k) {
  int len = arr.size(), count = 0, ret;
  for (int i = 0; i < len; ++i) {
    count = 0;
    for (int j = 0; j < len; ++j) {
      if (arr[j] > arr[i]) {
        count++;
      }
    }
    if (count == (k-1)) {
      ret = arr[i];
      break;
    }
  }
  return ret;
}

int main() {
  vector<int> arr = {3, 2, 1, 5, 6, 4};
  int ret = top_k_num(arr, 2);
  cout << "result: " << ret << endl;
  return 0;
}