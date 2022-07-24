/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure/MinStack.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/DataStructure
 * Created Date: Sunday, July 24th 2022, 9:28:59 am
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <stack>
#include <limits>
using namespace std;

class MinStack{
public:
  MinStack()=default;
  ~MinStack(){}

 void pop(){
    mStack.pop();
 }
 
 int getMin(){
  if(mStack.empty()){
    return std::numeric_limits<int>::min();
  }else{
    return MinVal;
  }
 }

 void push(int val){
    if(mStack.empty()){
      MinVal = val;
      mStack.push(val);
    }else{
      MinVal = std::min(MinVal, val);
      mStack.push(val);
    }
    
 }

private:
  int MinVal;
  stack<int> mStack;
};

int main(){
  MinStack minStack;
  minStack.push(3);
  minStack.push(8);
  minStack.push(2);
  cout << "min: " << minStack.getMin() << endl; 
  return 0;
}