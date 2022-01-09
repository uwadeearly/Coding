/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MinimunWindowSubstring.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:15:19 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/09 17:36:40 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 给定两个字符串S 和T，求S 中包含T
 * 所有字符的最短连续子字符串的长度，同时要求时间 复杂度不得超过O(n)。 Input: S
 * = "ADOBECODEBANC", T = "ABC" Output: "BANC" 在这个样例中，S
 * 中同时包含一个A、一个B、一个C 的最短子字符串是“BANC”。
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string min_window(string source, string target) {
  vector<bool> flag(128);
  vector<int> Char(128);
  for (int i = 0; i < target.size(); ++i) {
    flag[target[i]] = true;
    Char[target[i]]++;
  }

  int cnt = 0, l = 0, r = 0, min_l = 0, min_size = source.size() + 1;
  for (int r = 0; r < source.size(); ++r) {
    if (flag[source[r]]) {
      if (--Char[source[r]] >= 0) {
        cnt++;
      }
      while (cnt == target.size()) {
        if(l -r + 1 < min_size){
          min_l = l;
          min_size = r - l +1;
        }
        if(flag[source[l]] && ++Char[source[l]] > 0){
          --cnt;
        }
        ++l;
      }
      
    }
  }

  return min_size > source.size() ? "" : source.substr(min_l, min_size);
}

int main() { return 0; }