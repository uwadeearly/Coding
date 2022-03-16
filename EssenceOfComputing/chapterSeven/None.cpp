/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   None.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:01:39 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/03/16 10:05:43 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int get_one_n(int num) {
  int count = 0;
  while (num > 0) {
    count++;
    num = num & (num - 1);
  }
  return count;
}

int main() {
  /*test*/
  for (int i = 0; i < 16; ++i) {
    int ret = get_one_n(i);
    cout << i << " havce one nums is: " << ret << endl;
  }
  return 0;
}