/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure/MaxChunksTpMakeSorted.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure
 * Created Date: Sunday, July 24th 2022, 9:18:31 am
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;
/* 给定一个含有0 到n 整数的数组，每个整数只出现一次，求这个数组最多可以分割成多少个
 * 子数组，使得对每个子数组进行增序排序后，原数组也是增序的
 * Input: [1,0,2,3,4]
 * Output: 4
 * 最多分割是[1, 0], [2], [3], [4]
 * 题目不理解
 */

int solution(vector<int>& inputs){
 int chunks =0, max_val = 0;
 for(int i=0; i<inputs.size(); ++i){
  max_val = max(i, inputs[i]);
  if(max_val == i){
    ++chunks;
  }
  return chunks;
 }
}

int main(){
  return 0;
}