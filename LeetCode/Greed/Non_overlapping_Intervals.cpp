/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Non-overlapping_Intervals.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 10:45:04 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/04 10:28:28 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
 * Input: [[1,2], [2,4], [1,3]]
 * Output: 1
 * 在这个样例中，我们可以移除区间[1,3]，使得剩余的区间[[1,2], [2,4]] 互不重叠。
 * Note: 默认子array就有两个元素。
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int min_count(vector<vector<int>> &intervals) {
  if (intervals.empty())
    return 0;
  int n = intervals.size();

  sort(intervals.begin(), intervals.end(),
       [](vector<int> a, vector<int> b) { return a[1] < b[1]; });

  int prev = intervals[0][1], total = 0;

  for (int i = 1; i < n; ++i) {
    if (intervals[i][0] < prev) {
      total++;
    } else {
      prev = intervals[i][1];
    }
  }
  return total;
}

int main() {
  vector<vector<int>> intervals = {{1, 2}, {2, 4}, {1, 3}};
  int ret = min_count(intervals);
  cout << "result is: " << ret << endl;
  for(auto& elem: intervals){
    for(int i=0; i<2; ++i){
      cout << elem[i] << ", ";
    }
    cout << endl;
  }
  return 0;
}