/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/Array/arrayWalk.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/Array
 * Created Date: Friday, August 12th 2022, 3:16:01 pm
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;

/* 数组对应位置的数表示能前进的最大步数，前进对应位置后，再根据对应位置的数前进。
 * 判断数组是否否能走到末尾
 */
bool solution(vector<int>& nums){
  int len = nums.size();
  int i=0;
  while(i < len){
    int step = nums[i];
    i += step;
    if(step == 0 && i < len-1){
      return false;
    }
    if(step == 0 && i == len-1){
      break;
    }
  }
  return true;

}

int main(){
  const char* a = "fav";
  int val = 123;
  cout << to_string(val) << endl;
  string str(a);
  cout << str << endl;

  vector<int> nums = {1, 1, 1, 0};
  cout << solution(nums) << endl;
}