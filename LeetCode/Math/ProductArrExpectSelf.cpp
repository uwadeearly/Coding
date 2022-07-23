/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/Math/ProductArrExpectSelf.cpp Path:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/Math Created Date: Saturday, July
 * 23rd 2022, 4:08:12 pm Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  int len = nums.size();
  vector<int> left_ret(len, 1);
  vector<int> right_ret(len, 1);
  vector<int> ret(len, 1);

  for (int i = 1; i < len; ++i) {
    left_ret[i] = left_ret[i - 1] * nums[i - 1];
    right_ret[len-i-1] = right_ret[len-i] * nums[len-i];
  }

  for (int i = 0; i < len; ++i) {
    ret[i] = left_ret[i] * right_ret[i];
  }
  return ret;
}

int main() {
  vector<int> inputs = {1, 2, 3, 4};
  vector<int> ret = productExceptSelf(inputs);
  for (const auto& elem : ret) {
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}