/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/DynamicProgramming/SequenceLength.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/DynamicProgramming
 * Created Date: Wednesday, July 6th 2022, 2:08:55 pm
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

/* 给定一个数组，求其连续子数组的长度(在原数组中可以是非连续的)，计算复杂度O(n)
 * 比如：[3, 100, 200, 2, 4, 1]，连续子数组[1, 2, 3, 4]长度为4
*/

#include <iostream>
#include <vector>
using namespace std;

//原数组中连续的
int SequenLen(vector<int>& nums){
  int low = nums[0], up = nums[0];
  int tmp = 1, len = 1;

  for(int i=1; i<nums.size(); ++i){
    if(nums[i] == low-1){
      tmp++;
      low -= 1;
    }else if(nums[i] == up+1){
      tmp++;
      up += 1;
    }else{
      if(tmp > len) len = tmp;
      low = nums[i];
      up = nums[i];
    }
  }

  return len;
}

//原数组中非连续的
int SequenLen2(vector<int>& nums){
  int max_val = nums[0];
  for(int i=1; i<nums.size(); ++i){
    if(max_val < nums[i]){
      max_val = nums[i];
    }
  }
  vector<bool> set(max_val, false);
  
  for(const auto& elem: nums){
    set[elem] = true;
  }

  int len = 0, tmp = 1;
  if(!set[0]){
    tmp = 0;
  }
  
  for(int i=1; i<set.size(); ++i){
    if(set[i]){
      tmp++;
    }else{
      if(tmp > len){
        len = tmp;
      }
      tmp = 0;
    }
  }
  return len;
}

int main(){

  vector<int> nums = {3, 5, 100, 6, 200, 4, 2, 1};
  // int length = SequenLen(nums);
  int length = SequenLen2(nums);
  cout << "sub sequence length: " << length << endl;
  return 0;
}