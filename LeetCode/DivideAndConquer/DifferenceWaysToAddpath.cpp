/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/DivideAndConquer/DifferenceWaysToAddpath.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/DivideAndConquer
 * Created Date: Sunday, July 10th 2022, 7:13:43 pm
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

/* 给定一个只包含加、减和乘法的数学表达式，求通过加括号可以得到多少种不同的结果
 * Input: "2-1-1"
 * Output: [0, 2]
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string inputs) {
  vector<int> ways;
  for (int i = 0; i < inputs.length(); ++i) {
    char c = inputs[i];
    if (c == '=' || c == '-' || c == '*') {
      vector<int> left = solution(inputs.substr(0, i));
      vector<int> right = solution(inputs.substr(i + 1));

      for (auto l : left) {
        for (auto r : right) {
          switch (c) {
            case '+':
              ways.push_back(l + r);
              break;
            case '-':
              ways.push_back(l - r);
              break;
            case '*':
              ways.push_back(l * r);
              break;
          }
        }
      }

    }
  }
  if (ways.empty()) ways.push_back(stoi(inputs));
  return ways;
}

int main() { 
  string str = "2-1-1-1";
  vector<int> ret = solution(str);
  for(const auto& elem: ret){
    cout << elem << " ";
  }
  cout <<endl;
  return 0; }