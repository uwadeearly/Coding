/*
 * Filename: /home/wei.zhao/cpp_code/Coding/LeetCode/math/GreatCommonDivisor.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/LeetCode/math
 * Created Date: Sunday, July 10th 2022, 7:50:39 pm
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

/* 求最大公约数和最小公倍数
*/
#include<iostream>
using namespace std;

//最大公约数
int gcd(int one, int two){
  return two == 0? one: gcd(two, one % two);
}

//最小公倍数
int lcm(int one , int two){
  return one * two / gcd(one, two);
}

int main(){
  int cd = gcd(12, 8);
  cout << "(12, 8) great common divisionor: " << cd << endl;
  int cm = lcm(12, 8);
  cout << "(12, 8) max common multiple: " << cm << endl;
}