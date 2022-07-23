/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure/FindAllnums.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure
 * Created Date: Saturday, July 23rd 2022, 5:27:52 pm
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;
/* 
 * 输入是一个一维整数数组，输出也是一个一维整数数组，表示输入数组内没出现过的数字。
 */

vector<int> solution(vector<int>& nums){
  vector<bool> indexMap(nums.size()+1, false);
  vector<int> ret;
  for(const auto& elem: nums){
    indexMap[elem] = true;
  }

  for(int i=1; i<nums.size()+1; ++i){
    if(!indexMap[i]){
      ret.push_back(i);
    }
  }
  return ret;
}

int main(){
  vector<int> inputs = {4,3,2,7,7,2,3,1};
  auto ret = solution(inputs);
  for(auto elem: ret){
    cout << elem << " ";
  }
  cout << endl;
}