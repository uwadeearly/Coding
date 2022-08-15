/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/Array/rotaArray.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/Array
 * Created Date: Thursday, August 11th 2022, 8:37:16 pm
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <vector>
using namespace std;

/* 整数数组 nums 按升序排列，数组中的值 互不相同.
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了
 * 旋转， 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ...,
 * nums[k-1]]（下标 从 0 开始 计数）。 例如， [0,1,2,4,5,6,7] 在下标 3
 * 处经旋转后可能变为 [4,5,6,7,0,1,2] 给你 旋转后 的数组 nums 和一个整数 target
 * ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1
 * 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题
 */

int binarySearch(vector<int>& arr, int l, int r, int target) {
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] > target) {
      r = mid - 1;
    } else if (arr[mid] < target) {
      l = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int func(vector<int>& arr, int l, int r, int target) {
  if (l > r) {
    return -1;
  }
  int mid = l + (r - l) / 2;
  int tmp = arr[mid];
  if (target == tmp) {
    return mid;
  }

  if (tmp > arr[r]) {
    if (tmp > target && target > arr[l]) {
      return binarySearch(arr, l, mid, target);
    } else {
      return func(arr, mid + 1, r, target);
    }
  } else if (tmp < arr[r]) {
    if (tmp < target && target < arr[r]) {
      return binarySearch(arr, mid, r, target);
    } else {
      return func(arr, l, mid - 1, target);
    }
  }
}

int solution(vector<int>& arr, int target) {
  //[4,5,6,7,0,1,2]
  int len = arr.size();
  int r = len - 1;
  int l = 0;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (target == arr[mid]) {
      return mid;
    } else if (arr[mid] < arr[r]) {
      if (target > arr[mid] && target <= arr[r]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    } else {
      if (target >= arr[l] && target < arr[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }

  return -1;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int ret = solution(arr, 2);
  cout << "result: " << ret << endl;
  return 0;
}