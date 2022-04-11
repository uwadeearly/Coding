/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClimbingStairs.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:03:39 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/04/11 20:11:10 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;
/*
 * 给定n 节台阶，每次可以走一步或走两步，求一共有多少种方式可以走完这些台阶。 
*/

int get_stairs(int n){
  
  if(n <= 0)
    return 0;
  int a = 1, b = 2;
  if(n == 1)
    return a;
  if(n == 2)
  return b;

  int ret = 0;
  for(int i=2; i<n; ++i){
    ret = a + b;
    a = b;
    b = ret;
  }
  return ret;
  
}

int main(){
  int ret = get_stairs(4);
  cout << "get stairs: " << ret << endl;
  return 0;
}