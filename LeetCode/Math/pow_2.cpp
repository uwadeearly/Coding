/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/Math/pow_2.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/Math
 * Created Date: Wednesday, July 20th 2022, 10:57:03 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
using namespace std;

float pow(float x, int y) {
  if (y == 0) {
    return 1;
  }

  if (y == 1) {
    return x;
  } else {
    return pow(x, y / 2) * pow(x, y / 2) * pow(x, y % 2);
  }
}

int main() {
  float ret = pow(2, 10);
  cout << "result: " << ret << endl;
  return 0;
}