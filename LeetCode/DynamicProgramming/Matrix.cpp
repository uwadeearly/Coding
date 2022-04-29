/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:22:02 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/04/29 16:36:09 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 给定一个由0 和1 组成的二维矩阵，求每个位置到最近的0 的距离。
 * 输入是一个二维0-1
 数组，输出是一个同样大小的非负整数数组，表示每个位置到最近的0的距离。
 * Input:
    [[0,0,0],
     [0,1,0],
     [1,1,1]]0
    Output:
    [[0,0,0],
     [0,1,0],
     [1,2,1]]
  * 需要两次的动态搜索，一次是从左上到右下，
 一次是从右下到左上；这是没有想到的。。。
 */

vector<vector<int>> get_distance(vector<vector<int>> &inputs) {
  int rows = inputs.size();
  int cols = inputs[0].size();
  vector<vector<int>> result(rows, vector<int>(cols, INT32_MAX));

  /*from left_top to right_bottom*/
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (inputs[i][j] == 0) {
        result[i][j] = 0;
      } else {
        if (i > 0 && j > 0) {
          result[i][j] =
              inputs[i][j] + std::min(result[i - 1][j], result[i][j - 1]);
        } else if (i > 0) {
          result[i][j] = inputs[i][j] + result[i - 1][j];
        } else {
          result[i][j] = inputs[i][j] + result[i][j - 1];
        }
      }
    }
  }

  /*from right_bottom to left_top*/
  for(int i=rows-1; i>=0; --i){
    for(int j=cols-1; j>=0; --j){
      if(inputs[i][j]){
        if(i<rows-1 && j < cols-1){
          result[i][j] = inputs[i][j] + std::min(result[i+1][j], result[i][j+1]);
        }else if(i < rows-1){
          result[i][j] = inputs[i][j] + result[i+1][j];
        }else{
          result[i][j] = inputs[i][j] + result[i][j+1];
        }
      }
    }
  }


  return result;
}

int main() { return 0; }