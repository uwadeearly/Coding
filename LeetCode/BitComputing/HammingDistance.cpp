/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/BitComputing/HammingDistance.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/BitComputing
 * Created Date: Saturday, July 23rd 2022, 4:37:40 pm
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
using namespace std;

int distance(int one, int two){
  int count = 0;
  while(one || two){
    int a = one % 2;
    int b = two % 2;
    
    if(a^b){
      ++count;
    }
    one = one >> 1;
    two = two >> 1;
  }
  return count;
}

int main(){
  int ret = distance(1, 4);
  cout << "result: " << ret << endl;
  return 0;
}