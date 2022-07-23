/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/BitComputing/ReverseBit.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/BitComputing
 * Created Date: Saturday, July 23rd 2022, 5:03:32 pm
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
using namespace std;

uint32_t solution(uint32_t nums){
  uint32_t ans = 0;
  for(int i=0; i<32; ++i){
    ans <<= 1;
    ans += nums & 1;
    nums >>= 1;
  }
  return ans;
}

int main(){
  uint32_t ret = solution(43261596);
  cout << "ret: " << ret << endl;
  return 0;
}