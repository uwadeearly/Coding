/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure/Search2DMatrix.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure
 * Created Date: Saturday, July 23rd 2022, 7:02:02 pm
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;

/* 给定一个二维矩阵，已知每行和每列都是增序的，尝试设计一个快速搜索一个数字是否在矩
 * 阵中存在的算法。
 *
 * 这道题有一个简单的技巧：我们可以从右上角开始查找，若当前值大于待搜索值，我们向左 
 * 移动一位；若当前值小于待搜索值，我们向下移动一位。如果最终移动到左下角时仍不等于待搜
 * 索值，则说明待搜索值不存在于矩阵中
*/

bool solution1(vector<vector<int>>& inputs, int target) {
  int left = 0, mid = 0;
  int right = inputs[0].size();

  while (left <= right) {
    mid = (left + right) / 2;
    if (target > inputs[0][mid]) {
      left = mid + 1;
    }
    if (target < inputs[0][mid]) {
      right = mid - 1;
    } else if (target == inputs[0][mid]) {
      return true;
    }
  }

  int cols = mid;
  left = 0;
  right = inputs.size();

  while (left <= right) {
    mid = (left + right) / 2;
    if (target > inputs[mid][cols]) {
      left = mid + 1;
    } else if (target < inputs[mid][cols]) {
      right = mid - 1;
    } else if (target = inputs[mid][cols]) {
      return true;
    }
  }

  return false;
}

bool solution2(vector<vector<int>>& inputs, int target, int c_lower, int c_uper,
               int r_lower, int r_uper) {
  int c_mid = (c_lower + c_uper) / 2;
  int r_mid = (r_lower + r_uper) / 2;
  if (target == inputs[r_mid][c_mid]){
    return true;
  }
  if (target < inputs[r_mid][c_uper]) {
    if (target < inputs[r_mid][c_mid]) {
      solution2(inputs, target, c_lower, c_mid, r_lower, r_mid);
    } else {
      solution2(inputs, target, c_mid, c_uper, r_lower, r_mid);
    }
  } else if (target < inputs[r_uper][c_uper]) {
    if (target < inputs[r_uper][c_mid]) {
      solution2(inputs, target, c_lower, c_mid, r_mid, r_uper);
    } else {
      solution2(inputs, target, c_mid, c_uper, r_mid, r_uper);
    }
  }
}

bool search(vector<vector<int>>& inputs, int target){
  int rows = inputs.size();
  int cols = inputs[0].size();
  int i =0;
  int j = cols -1;
  while(i < rows && j >=0){
    if(target == inputs[i][j]){
      return true;
    }else if(target < inputs[i][j]){
      --j;
    }else{
      ++i;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> m = {{1, 4, 7, 11, 15},
                           {2, 5, 8, 12, 19},
                           {3, 6, 9, 16, 22},
                           {10, 13, 14, 17, 24},
                           {18, 21, 23, 26, 30}};
  bool ret = search(m, 50);
  cout << "result: " << ret << endl;
  return 0;
}