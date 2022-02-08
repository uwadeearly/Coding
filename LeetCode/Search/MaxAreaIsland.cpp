/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaxAreaIsland.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:12:44 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/02/08 20:13:23 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/* 给定一个二维的0-1 矩阵，其中0 表示海洋，1
 * 表示陆地。单独的或相邻的陆地可以形成岛
 * 屿，每个格子只与其上下左右四个格子相邻。求最大的岛屿面积。
 * 输入是一个二维数组，输出是一个整数，表示最大的岛屿面积。
 * Input:
 * [[1,0,1,1,0,1,0,1],
 *  [1,0,1,1,0,1,1,1],
 *  [0,0,0,0,0,0,0,1]]
 * Output: 6
 */

int maxAreaIsland(vector<vector<int>> &inputs) {
  stack<pair<int, int>> island;
  int rows = inputs.size();
  int cols = inputs[0].size();
  vector<int> direction = {-1, 0, 1, 0, -1};
  int max_area = 0;
  
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (inputs[i][j]) {
        island.push({i, j});
        inputs[i][j] = 0;
        int area = 1;

        while (!island.empty()) {
          auto [r, c] = island.top();
          island.pop();
          for (int k = 0; k < 4; ++k) {
            int x = r + direction[k];
            int y = c + direction[k + 1];
            if (x >= 0 && y >= 0 && x < rows && y < cols && inputs[x][y]) {
              area++;
              island.push({x, y});
              inputs[x][y] = 0;
            }
          }
        }
        max_area = max(max_area, area);
      }
    }
  }
  return max_area;
}

int main() {
  vector<vector<int>> inputs = {{1, 0, 1, 1, 0, 1, 0, 1},
                                {1, 0, 1, 1, 0, 1, 1, 1},
                                {0, 0, 0, 0, 0, 0, 0, 1}};
  int ret = maxAreaIsland(inputs);
  cout << "max island: " << ret << endl;
  return 0;
}