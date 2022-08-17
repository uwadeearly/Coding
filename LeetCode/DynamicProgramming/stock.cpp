/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/DynamicProgramming/stock.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/DynamicProgramming
 * Created Date: Wednesday, August 17th 2022, 10:21:07 am
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include<iostream>
#include<vector>
using namespace std;
/* stock max price
 * 7, 2, 5, 1, 3, 6, 4
 * 1 buy 6 sell
 */
int solution(vector<int>& prices){
  int len = prices.size();
  int index = 0;
  int maxVal = 0;
  for(int i=1; i<len; ++i){
    if(prices[i] > prices[i-1]){
      index = i-1;
      break;
    }
  }
  cout << index << endl;

  for(int j=index+1; j<len; ++j){
    if(prices[j] > prices[index]){
      maxVal = max(maxVal, (prices[j] - prices[index]));
    }else{
      index = j;
    }
  }
  return maxVal;

}

int main(){
  vector<int> arr = {7,1,5,3,6,4};
  int ret = solution(arr);
  cout << "ret: " << ret << endl;
  return 0;
}