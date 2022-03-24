/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   N_queens.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:56:44 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/03/24 10:51:02 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void back_tracking(vector<vector<string>> &ans, vector<string> &board,
                   vector<bool> &columns, vector<bool> &ldiag,
                   vector<bool> &rdiag, int row, int n) {
  if (row == n) {
    ans.push_back(board);
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (columns[i] || ldiag[n - row + i - 1] || rdiag[row + i]) {
      continue;
    }
    columns[i] = true;
    ldiag[n - row + i - 1] = true;
    rdiag[row + i] = true;
    board[row][i] = 'Q';

    back_tracking(ans, board, columns, ldiag, rdiag, row + 1, n);

    columns[i] = false;
    ldiag[n - row + i - 1] = false;
    rdiag[row + i] = false;
    board[row][i] = '.';
  }
}

vector<vector<string>> solution_queens(int n) {
  vector<vector<string>> ans;
  if (n <= 0) {
    return ans;
  }

  vector<bool> columns(n, false);
  vector<bool> ldiag(2 * n - 1, false);
  vector<bool> rdiag(2 * n - 1, false);
  vector<string> board(n, string(n, '.'));
  back_tracking(ans, board, columns, ldiag, rdiag, 0, n);
  return ans;
}

void show_ans(vector<string> &str) {
  int rows = str.size();
  int cols = str[0].size();
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << str[i][j] << ", ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<string>> ans = solution_queens(8);
  for (auto elem : ans) {
    show_ans(elem);
    cout << "<<<<***>>>>>" << endl;
  }
  cout << "total size: " << ans.size() << endl;
  return 0;
}