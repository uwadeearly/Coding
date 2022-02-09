/*
 * @Author: Michael Enigma
 * @Date: 2022-02-02 10:53:00
 * @LastEditTime: 2022-02-04 09:30:35
 * @LastEditors: Do not edit
 * @FilePath: \Coding\SoulOfComputing\MaxVal.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&arr, int left, int right){
  int l = left, r = right;
  int base = arr[left];

  while(l < r){
    while(l < r && arr[r] > base){
      r--;
    }
    arr[l] = arr[r];
    while(l < r && arr[l] < base){
      l++;
    }
    arr[r] = arr[l];
  }
  arr[l] = base;
  return l;
}

void qsort(vector<int>&arr, int left, int right){
  if(left>=right) return;
  else{
    int index = partition(arr, left, right);
    qsort(arr, left, index-1);
    qsort(arr, index+1, right);
  }
}

int main(){
  vector<int> arr = {9, 3, 5, 1, 2, 7, 8};
  qsort(arr, 0, 6);
  
  for(auto& elem:arr){
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}