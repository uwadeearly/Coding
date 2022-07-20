/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/math/prime.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/math
 * Created Date: Sunday, July 10th 2022, 8:02:15 pm
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;

int countPrime(int nums) {
  if (nums <= 2) return 0;
  vector<bool> prime(nums, true);
  int count = nums - 2;

  for (int i = 2; i <= nums; ++i) {
    if (prime[i]) {
      for (int j = 2 * i; j < nums; j += i) {
        if (prime[j]) {
          prime[j] = false;
          --count;
        }
      }
    }
  }
  
  return count;
}

int main() {
  int ret = countPrime(10);
  cout << "prime: " << ret << endl;
  return 0;
}