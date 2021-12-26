/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:22:29 by wei.zhao          #+#    #+#             */
/*   Updated: 2021/12/15 20:09:28 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
 * 个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
 * 有孩子至少要有一个糖果。求解最少需要多少个糖果。
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int candy(vector<int> &ratings) {
  int minCandy = 0;
  int size = ratings.size();
  if(size < 2)return size;
  vector<int> candyNums(size, 1);

  for (int i = 0; i < size - 2; i += 2) {
    int left = ratings[i];
    int mid = ratings[i + 1];
    int right = i + 2 < size ? ratings[i + 2] : 0;

    if (mid > left && candyNums[i + 1] <= candyNums[i]) {
      candyNums[i + 1] += 1;
    } else if (mid < left && candyNums[i] >= candyNums[i + 1]) {
      candyNums[i] += 1;
    }

    if (i + 2 < size) {
      if (right < mid && candyNums[i + 1] <= candyNums[i + 2]) {
        candyNums[i + 1] += 1;
      } else if (right > mid && candyNums[i+1] >= candyNums[i+2]) {
        candyNums[i + 2] += 1;
      }
    }
  }

  for (int i = 0; i < candyNums.size(); ++i) {
    minCandy += candyNums[i];
    cout << candyNums[i] << ", " << endl;
  }
  return accumulate(candyNums.begin(), candyNums.end(), 0);
}

int main() {
  vector<int> ratings = {1, 0, 2};
  int ret = candy(ratings);

  cout << "result: " << ret << endl;
}