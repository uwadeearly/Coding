/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FriendCircles.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:01:33 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/02/09 11:03:42 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* 给定一个二维的0-1 矩阵，如果第(i, j) 位置是1，则表示第i 个人和第j
 * 个人是朋友。已知 朋友关系是可以传递的，即如果a 是b 的朋友，b 是c
 * 的朋友，那么a 和c 也是朋友，换言之这
 * 三个人处于同一个朋友圈之内。求一共有多少个朋友圈。
 *
 * 输入是一个二维数组，输出是一个整数，表示朋友圈数量。因为朋友关系具有对称性，该二
 * 维数组为对称矩阵。同时，因为自己是自己的朋友，对角线上的值全部为1。
 *
 * Input:
 *  [[1,1,0],
 *   [1,1,0],
 *   [0,0,1]]
 *  Output: 2
 * 
 * 要善于使用递归
 */

int friendCircles(vector<vector<int>> inputs) {
  int friends = inputs.size();
  int friendsCir = 0;

  for (int i = 0; i < friends; ++i) {
    stack<pair<int, int>> records;
    if (inputs[i][i]) {
      records.push({i, i});
      inputs[i][i] = 0;
      friendsCir++;
    }

    while (!records.empty()) {
      auto [a, b] = records.top();
      records.pop();
      inputs[b][a] = 0;
      inputs[b][b] = 0;
      inputs[a][b] = 0;
      for (int j = 0; j < friends; ++j) {
        if (inputs[i][j]) {
          records.push({i, j});
        }
      }
    }
  }
  return friendsCir;
}

int main() {
  vector<vector<int>> inputs = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  int ret = friendCircles(inputs);
  cout << "ret: " << ret << endl;
  return 0;
}