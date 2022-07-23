/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/Math/Base7.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/Math
 * Created Date: Saturday, July 23rd 2022, 9:09:42 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <string>
using namespace std;

/* 给定一个十进制整数，求它在七进制下的表示.
 * Input: 100
 * Output: "202"
 */
string base_7(int inputs) {
  if (inputs == 0) return "0";
  int div = 0, mod = 0, tmp_inputs = inputs;
  string ret;

  while (tmp_inputs != 0) {
    mod = tmp_inputs % 7;
    tmp_inputs = tmp_inputs / 7;
    string tmp = std::to_string(mod) + ret;
    ret = tmp;
  }

  return inputs > 0 ? ret : "-" + ret;
}

int main() {
  string ret = base_7(14);
  cout << "ret: " << ret << endl;
  return 0;
}