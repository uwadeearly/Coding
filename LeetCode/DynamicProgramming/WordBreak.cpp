/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordBreak.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:09:14 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/05/06 11:09:39 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 
 * 给定一个字符串和一个字符串集合，求是否存在一种分割方式，使得原字符串分割后的子字
 * 符串都可以在集合内找到。
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 */


bool get_word_break(string str, vector<string>& word_dict){
  int len = str.length();
  vector<bool> dp(len+1, false);
  dp[0] = true;
  for(int i=1; i<=len; ++i){
    for(auto& word : word_dict){
      int word_len = word.length();
      if(i >= word_len && str.substr(i-word_len, word_len) == word){
        dp[i] = dp[i] || dp[i-word_len];
        break;
      }
    }
  }
  return dp[len];

}

int main(){
  string str = "applepenapple";
  vector<string> word_dict = {"apple", "pen"};
  
  bool state = get_word_break(str, word_dict);
  cout << "result: " << state << endl;
  return 0;
}