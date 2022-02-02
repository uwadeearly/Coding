/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:06:01 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/11 19:40:12 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

float sqrt(float val) {
  if (val <= 0)
    return 0;

  float esp = 0.01;
  float l, r, err;
  if (val > 1.0) {
    l = 1.0;
    r = val;
  } else if (val < 1.0) {
    l = 0;
    r = 1.0;
  } else {
    return 1.0;
  }
  
  float ret = (r + l) / 2.0;
  err = ret * ret - val;
  while (std::abs(err) > esp) {
    if (err > 0) {
      r = ret;
    } else if (err < 0) {
      l = ret;
    }
    ret = (r + l) / 2.0;
    err = ret * ret - val;
  }
  return ret;
}

int main() {
  float a = 9.0;
  float ret = sqrt(a);
  printf("ret: %.3f...\n", ret);
  return 0;
}
