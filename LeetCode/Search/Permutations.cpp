/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Permutations.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:34:40 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/02/24 21:00:09 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 给定一个无重复数字的整数数组，求其所有的排列方式。
 */

void backtracking(vector<int> &arr, int level, vector<vector<int>> &ans) {
  if (level == arr.size() - 1) {
    ans.push_back(arr);
    return;
  }

  for (int i = level; i < arr.size(); ++i) {
    swap(arr[i], arr[level]);
    backtracking(arr, level + 1, ans);
    swap(arr[i], arr[level]);
  }
}

vector<vector<int>> permutations(vector<int> &arr) {
  vector<vector<int>> ans;
  backtracking(arr, 0, ans);
  return ans;
}

int main() {
  vector<int> inputs = {1, 2, 3};
  vector<vector<int>> ret = permutations(inputs);
  int rows = ret.size();
  int cols = ret[0].size();
  
  for (int i = 0; i < rows; ++i) {
    cout << "[";
    for (int j = 0; j < cols; ++j) {
      cout << ret[i][j] << ", ";
    }
    cout << "]" << endl;
  }

  return 0;
}