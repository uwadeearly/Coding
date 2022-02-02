/*
 * @Author: Micheal Enigma
 * @Date: 2022-01-21 08:48:20
 * @LastEditTime: 2022-01-21 08:53:12
 * @LastEditors: Do not edit
 * @FilePath: \Coding\LeetCode\Array\test_two_dims.c
 * @Description: 
 */
#include <stdio.h>

int main(){
  int arr[2][4];
  for(int i=0; i<2; ++i){
    for(int j=0; j<4; ++j){
      arr[i][j] = i*4+j;
    }
  }

  int *a_p = arr[1];
  for(int i=0; i<4; ++i){
    printf("%d, ", a_p[i]);
  }
  return 0;
}