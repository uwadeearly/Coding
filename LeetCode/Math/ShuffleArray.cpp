/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/Math/ShuffleArray.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/Math
 * Created Date: Saturday, July 23rd 2022, 11:11:48 am
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 给定一个数组，要求实现两个指令函数。第一个函数“shuffle”可以随机打乱这个数组，第
 * 二个函数“reset”可以恢复原来的顺序。
 * 
 */
void shuflleArr(vector<int>& arr){
  int length = arr.size();
  for(int i=0; i<length; ++i){
    int tmp = std::rand() % (i + 1);
    std::swap(arr[i], arr[tmp]);
  }
}

int main(){
  vector<int> arr = {1,3,4,5};
  shuflleArr(arr);
  for(const auto elem: arr){
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}