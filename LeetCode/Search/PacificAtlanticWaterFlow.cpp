/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PacificAtlanticWaterFlow.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:10 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/03/16 10:00:48 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 给定一个二维的非负整数矩阵，每个位置的值表示海拔高度。假设左边和上边是太平洋，右
 * 边和下边是大西洋，求从哪些位置向下流水，可以流到太平洋和大西洋。水只能从海拔高的位置
 * 流到海拔低或相同的位置。
 * 
 * 输入是一个二维的非负整数数组，表示海拔高度。输出是一个二维的数组，其中第二个维度
 * 大小固定为2，表示满足条件的位置坐标。
 * Input:
 *   太平洋~ ~ ~ ~ ~
 *   ~ 1 2 2 3  (5) *
 *   ~ 3 2 3 (4) (4) *
 *   ~ 2 4 (5) 3 1 *
 *   ~ (6) (7) 1 4 5 *
 *   ~ (5) 1 1 2 4 *
 *   * * * * * 大西洋
 *   Output: [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]
*/
//TODO
bool dfs(vector<vector<int>>& arr, int i, int j, int rows, int cols){
  if((i>=0 && i<rows) && (j >=0 && j<cols)){
    bool state;
    if(arr[i][j] > arr[i-1][j]){
      state = dfs(arr, i-1, j, rows, cols);  
    }
    else if(arr[i][j] > arr[i][j-1]){
      state = dfs(arr, i, j-1, rows, cols);
    }else{
      state = false;
    }
    return state;
  }else{
    return true;
  }
  
}
vector<int> pacificAtlanticWaterFlow(vector<vector<int>>& arr){
  const int rows = arr.size();
  const int cols = arr[0].size();
  for(int i=0; i<rows; ++i){
    for(int j=0; j<cols; ++j){

      
    }
  }
}

int main(){
  return 0;
}