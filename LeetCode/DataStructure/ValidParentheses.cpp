/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure/ValidParentheses.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure
 * Created Date: Sunday, July 24th 2022, 9:44:47 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool isPair(char left, char right) {
  switch (left) {
    case '[':
      if (right == ']') {
        return true;
      } else {
        return false;
      }
    case '{':
      if (right == '}') {
        return true;
      } else {
        return false;
      }
    case '(':
      if (right == ')') {
        return true;
      } else {
        return false;
      }
  }
}

bool isValid(string str) {
  stack<char> match;
  for (int i = 0; i < str.size(); ++i) {
    char strChar = str[i];
    if (strChar == '[' || strChar == '{' || strChar == '(') {
      match.push(strChar);
    }
    if (strChar == ']' || strChar == '}' || strChar == ')') {
      char leftChar = match.top();
      if (!isPair(leftChar, strChar)) {
        return false;
      }
      match.pop();
    }
  }
  return true;
}

int main() {
  bool ret = isValid("{[]}()");
  cout << "result: " << ret << endl;
  return 0;
}