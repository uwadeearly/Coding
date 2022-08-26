/*
 * Filename:
 * /home/wei.zhao/cpp_code/Coding/LeetCode/BackTracking/CellphoneNumsCom.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/BackTracking
 * Created Date: Friday, August 26th 2022, 10:16:13 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void backTracking(vector<string>& ret, string& str, string& nums,
                  unordered_map<char, string>& numsMap, int start) {
  if (str.size() == nums.size()) {
    ret.push_back(str);
    return;
  }

  string num = numsMap[nums[start]];
  for (int i = 0; i < num.size(); ++i) {
    str += num[i];
    
    backTracking(ret, str, nums, numsMap, start + 1);
    str.pop_back();
  }
}

vector<string> solution(string& nums) {
  vector<string> ret;
  unordered_map<char, string> numsMap;
  string str = "";
  numsMap['2'] = "abc";
  numsMap['3'] = "def";
  numsMap['4'] = "ghi";
  numsMap['5'] = "jkl";
  numsMap['6'] = "mno";
  numsMap['7'] = "pqrs";
  numsMap['8'] = "tuv";
  numsMap['9'] = "wxyz";
  
  backTracking(ret, str, nums, numsMap, 0);
  return ret;
}

int main() {
  string nums = "234";
  auto result = solution(nums);
  for (const auto& elem : result) {
    cout << elem << ", ";
  }
  cout << endl;

  return 0;
}