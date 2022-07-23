/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/Math/FactionalTileZeroes.cpp Path:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/Math Created Date: Saturday, July
 * 23rd 2022, 9:38:03 am Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
using namespace std;

/* 给定一个非负整数，判断它的阶乘结果的结尾有几个0。
 * Input: 12
 * 12 != 479001600
 * Output: 2
 */

int solution(unsigned int inputs) {
  size_t result = 1, i = 1;
  int count = 0;
  for (; i <= inputs; ++i) {
    result *= i;
  }

  while (!(result % 10)) {
    ++count;
    result /= 10;
  }

  return count;
}

int main() {
  int count = solution(12);
  cout << "tile zeroes: " << count << endl;
  return 0;
}