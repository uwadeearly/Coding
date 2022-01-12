/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_last_position.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:38:49 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/12 10:01:21 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 给定一个增序的整数数组和一个值，查找该值第一次和最后一次出现的位置。
 * 输入是一个数组和一个值，输出为该值第一次出现的位置和最后一次出现的位置（从0
 * 开 始）；如果不存在该值，则两个返回值都设为-1。 Input: nums = [5,7,7,8,8,10],
 * target = 8 Output: [3,4]
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> find_first_last_position(vector<int> &inputs, int target) {
  int len = inputs.size();
  int l = 0, r = len - 1, mid, record;
  if (inputs[l] > target || inputs[r] < target)
    return {-1};

  vector<int> pos;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (target == inputs[mid]) {
      break;
    } else if (target < inputs[mid]) {
      r = mid - 1;
    } else if (target > inputs[mid]) {
      l = mid + 1;
    }
  }
  cout << "mid: " << mid << endl;
  record = mid;
  while (target == inputs[mid]) {
    mid--;
  }
  pos.push_back(++mid);
  mid = record;
  while (target == inputs[mid]) {
    mid++;
  }
  pos.push_back(--mid);

  return pos;
}

//bottom boundary function
int bottom_boundary(vector<int>& arr, int target){
  
}

//up boundary function

int main() {
  vector<int> inputs = {5, 7, 7, 8, 8, 10};
  int target = 8;
  vector<int> ret = find_first_last_position(inputs, target);
  for (auto &elem : ret) {
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}