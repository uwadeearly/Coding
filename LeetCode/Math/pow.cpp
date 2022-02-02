/*
 * @Author: Micheal Enigma
 * @Date: 2022-01-22 21:32:22
 * @LastEditTime: 2022-01-23 08:52:26
 * @LastEditors: Do not edit
 * @FilePath: \Coding\LeetCode\Math\pow.cpp
 * @Description:
 */
#include <stdio.h>


double pow(double x, int n) {
  if(n==0) return 1.0;

  double ret = 1;
  for (int i = n; i > 0; i /= 2) {
    ret *= ret;
    if (i % 2 != 0) ret *= x;
  }
  return n > 0 ? ret : 1.0 / ret;
}

int main(){
  double ret = pow(2.0, 7);
  printf("result: %.3f", ret);
}
