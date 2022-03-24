/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordSearch.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:29:26 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/03/22 14:14:35 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 给定一个字母矩阵，所有的字母都与上下左右四个方向上的字母相连。给定一个字符串，求
 * 字符串能不能在字母矩阵中寻找到。
 * 输入是一个二维字符数组和一个字符串，输出是一个布尔值，表示字符串是否可以被寻找
 * 到。
 * Input: word = "ABCCED", board =
 * [[’A’,’B’,’C’,’E’],
 * [’S’,’F’,’C’,’S’],
 * [’A’,’D’,’E’,’E’]]
 * Output: true
 * 从左上角的’A’ 开始，我们可以先向右、再向下、最后向左，找到连续的"ABCCED"。
 */

void in_search(vector<vector<char>> &mat_char, vector<vector<bool>> &state,
               const string str, int i, int j, bool &ret) {
  static int count = 0;
  int rows = mat_char.size();
  int cols = mat_char[0].size();

  if (i >= rows || j >= cols || i < 0 || j < 0) {
    return;
  }

  if (count == str.size() - 1) {
    ret = true;
    return;
  }

  if (state[i][j] || mat_char[i][j] != str[count]) {
    return;
  }

  state[i][j] = true;
  if (mat_char[i][j] == str[count]) {
    ++count;
  }

  in_search(mat_char, state, str, i, j + 1, ret);
  in_search(mat_char, state, str, i + 1, j, ret);
  in_search(mat_char, state, str, i, j - 1, ret);
  in_search(mat_char, state, str, i - 1, j, ret);
}

bool word_seach(vector<vector<char>> &mat_char, const string str) {
  int rows = mat_char.size();
  int cols = mat_char[0].size();
  vector<vector<bool>> state(rows, vector<bool>(cols, false));
  bool ret = false;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      in_search(mat_char, state, str, i, j, ret);
      if (ret) {
        return ret;
      }
    }
  }
  return ret;
}

int main() {
  string inputs = "ABCCED";
  vector<vector<char>> mat_char = {
      {'C', 'B', 'A', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  int rows = mat_char.size();
  int cols = mat_char[0].size();
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << mat_char[i][j] << ", ";
    }
    cout << endl;
  }

  bool ret = word_seach(mat_char, inputs);
  cout << "search result: " << ret << endl;
}