/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Combinations.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:29:28 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/02/25 20:14:25 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;
/* 给定一个整数n 和一个整数k，求在1 到n 中选取k 个数字的所有组合方法。
 * 输入是两个正整数n 和k，输出是一个二维数组，表示所有组合方式。
 * Input: n = 4, k = 2
 * Output: [[2,4], [3,4], [2,3], [1,2], [1,3], [1,4]]
 */

void backtracking(vector<vector<int>> &ans, vector<int> &comb, int &count,
                  int pos, int n, int k) {
  if (count == k) {
    ans.push_back(comb);
    return;
  }
  for (int i = pos; i < n; ++i) {
    comb[count++] = i;
    backtracking(ans, comb, count, i + 1, n, k);
    --count;
  }
}

vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> ans;
  vector<int> comb(k, 0);
  int count = 0;
  backtracking(ans, comb, count, 1, n, k);
  return ans;
}

int main() { 
  vector<vector<int>> ans = combine(5, 2);
  int rows = ans.size();
  int cols = ans[0].size();
  
  for(int i=0; i<rows; ++i){
    cout << "[";
    for(int j=0; j<cols; ++j){
      cout << ans[i][j] << ", ";
    }
    cout << "]" << endl;
  }
  
  return 0; }