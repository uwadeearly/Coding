/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/Array/treeSum.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/Array
 * Created Date: Thursday, August 11th 2022, 9:50:12 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

/*
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得
 * a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<int>& nums) {
  vector<vector<int>> ret;
  sort(nums.begin(), nums.end());
  int len = nums.size();
  for (int i = 0; i < len; ++i) {
    if (nums[i] > 0) {
      break;
    }
    if (i > 0 && nums[i - 1] == nums[i]) {
      continue;
    }
    unordered_set<int> set;
    for (int j = i + 1; j < len; ++j) {
      if (j > i + 2 && nums[j - 2] == nums[j - 1] && nums[j - 1] == nums[j]) {
        continue;
      }
      int c = 0 - nums[i] - nums[j];
      if (set.find(c) != set.end()) {
        ret.push_back({nums[i], nums[j], c});
        set.erase(c);
      } else {
        set.insert(nums[j]);
      }
    }
  }

  return ret;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ret = solution(nums);
  for(const auto& elems: ret){
    for(const auto& elem: elems){
      cout << elem << ", ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}