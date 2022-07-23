/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/Math/AddString.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/Math
 * Created Date: Saturday, July 23rd 2022, 9:50:06 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <string>
using namespace std;

int stringAdd(string one, string two) {
  char one_front = one[0];
  char two_front = two[0];
  int one_len = one.size();
  int two_len = two.size();
  string one_tmp, two_tmp;
  if (one_front == '-' && two_front == '-') {
    int length = one_len > two_len ? one_len : two_len;
    for (int i = 1; i < length; ++i) {
      if (i < one.size() - 1) one_tmp.push_back(one[i]);
      if (i < two.size() - 1) two_tmp.push_back(two[i]);
    }
    return -1 * (std::stoi(one) + std::stoi(two));
  } else if (one_front == '-' && two_front != '-') {
    for (int i = 1; i < one_len; ++i) {
      one_tmp.push_back(one[i]);
    }
    return std::stoi(two) - std::stoi(one_tmp);

  } else if (one_front != '-' && two_front == '-') {
    for (int i = 1; i < two_len; ++i) {
      two_tmp.push_back(two[i]);
    }
    return std::stoi(one) - std::stoi(two_tmp);
  } else {
    return std::stoi(one) + std::stoi(two);
  }
}

int main() {
  int ret = stringAdd("-1000", "200");
  cout << ret << endl;
}