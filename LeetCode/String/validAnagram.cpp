/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/String/validAnagram.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/String
 * Created Date: Monday, January 24th 2022, 9:56:10 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 判断两个字符串包含的字符是否完全相同.
 */

bool valid_anagram(string source, string target) {
  if (source.length() != target.length()) {
    return false;
  }

  int len = source.length();
  vector<bool> map(26, false);
  for (int i = 0; i < len; ++i) {
    int k = source[i] - 'a';
    int j = target[i] - 'a';
    map[k] = !map[k];
    map[j] = !map[j];
  }

  for (int i = 0; i < 26; ++i) {
    if (map[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  string a = "anagram", b = "nagaram";
  bool ret = valid_anagram(a, b);
  cout << "result: " << ret << endl;
  return 0;
}