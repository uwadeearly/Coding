/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/Array/subSequenSum.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/Array
 * Created Date: Thursday, August 18th 2022, 10:16:59 am
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;
/* Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum. 
 * [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * ret = 6
 */
int solution(vector<int>& nums){
  int len = nums.size();
  vector<int> dp(len, 0);
  dp[0] = nums[0];
  for(int i=1; i<len; ++i){
    dp[i] = nums[i] + max(dp[i-1], 0);
  }
  int ret = dp[0];
  for(int i=1; i<len; ++i){
    if(ret < dp[i]){
      ret = dp[i];
    }
  }
  return ret;
}


int main(){
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int ret = 0;
  ret = solution(arr);
  cout << "result: " << ret << endl;
  return 0; 
}