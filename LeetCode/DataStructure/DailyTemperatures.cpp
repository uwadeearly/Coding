/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure/DailyTemperatures.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure
 * Created Date: Sunday, July 24th 2022, 10:01:46 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* 给定每天的温度，求对于每一天需要等几天才可以等到更暖和的一天。如果该天之后不存在
 * 更暖和的天气，则记为0。
 * Input: [73, 74, 75, 71, 69, 72, 76, 73]
 * Output: [1, 1, 4, 2, 1, 1, 0, 0]
 */

vector<int> solution(vector<int>& temperatures) {
  /* LeetCode 超时。。。
   */
  int len = temperatures.size();
  vector<int> ret(len, 0);
  int index, initial;

  for (int i = 0; i < len; ++i) {
    index = i + 1;
    initial = temperatures[i];
    while (index < len) {
      if (temperatures[index] > initial) {
        ret[i] = index - i;
        initial = temperatures[++i];
        index = i + 1;
      } else {
        index++;
      }
    }
  }

  return ret;
}

vector<int> dailyTemp(vector<int>& temp){
  int len = temp.size();
  vector<int> ans(len, 0);
  stack<int> index;
  
  for(int i=0; i<len; ++i){
    while(!index.empty()){
      int pre_i = index.top();
      if(temp[i] <= temp[pre_i]){
        break;
      }
      ans[pre_i] = i-pre_i;
      index.pop();
    }
    index.push(i);
  }
  return ans;
}

int main() {
  vector<int> inputs = {55,38,53,81,61,93,97,32,43,78};
  auto ret = dailyTemp(inputs);
  for (const auto& elem : ret) {
    cout << elem << ", ";
  }
  cout << endl;
}