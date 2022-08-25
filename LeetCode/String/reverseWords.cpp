/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/String/reverseWords.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/String
 * Created Date: Tuesday, August 23rd 2022, 9:48:39 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string stripString(string& s) {
  int m = 0, n = s.size() - 1;
  while (m < n && s[m] == ' ') {
    ++m;
  }
  while (m < n && s[n] == ' ') {
    --n;
  }
  return s.substr(m, n - m + 1);
}

string reverseString(string s) {
  string str = stripString(s);
  int i = 0;
  stack<string> strStack;

  for (int j = 0; j < str.size(); ++j) {
    if (str[j] == ' ' || j == str.size() - 1) {
      string elem = str.substr(i, j - i + 1);
      cout << "elem: " << elem << endl;
      if (elem != " ") {
        strStack.push(stripString(elem));
      }
      i = j + 1;
    }
  }
  string ret;
  while (!strStack.empty()) {
    ret += strStack.top();
    strStack.pop();
    ret += " ";
  }
  return stripString(ret);
}

int main() {
  string a = "a";
  string ret = reverseString(a);
  cout << ret << endl;
  return 0;
}