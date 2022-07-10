/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/math/prime.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/math
 * Created Date: Sunday, July 10th 2022, 8:02:15 pm
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <vector>
using namespace std;

int countPrime(int nums) {
  if (nums <= 2) return 0;
  vector<bool> prime(nums - 2, true);
  int count = nums - 2;
  for (int i = 0; i < nums; ++i) {
    if (prime[i]) {
      for (int j = 2 * i; j < nums; j += i) {
        if(prime[i]){
          prime[i] = false;
          --count;
        }
      }
    }
  }
  return count;
}

int main() { return 0; }