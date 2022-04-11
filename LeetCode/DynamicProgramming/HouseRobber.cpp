/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HouseRobber.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:14:10 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/04/11 20:33:00 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 假如你是一个劫匪，并且决定抢劫一条街上的房子，每个房子内的钱财数量各不相同。如果
 * 你抢了两栋相邻的房子，则会触发警报机关。求在不触发机关的情况下最多可以抢劫多少钱.
 *
 * 输入是一个一维数组，表示每个房子的钱财数量；输出是劫匪可以最多抢劫的钱财数量。
 * Input: [2,7,9,3,1]
 * Output: 12
 */

int get_money(vector<int> &inputs) {
  int len = inputs.size();
  vector<int> money(len, 0);
  money[0] = inputs[0];
  money[1] = std::max(inputs[0], inputs[1]);

  for (int i = 2; i < len; ++i) {
    money[i] = std::max(inputs[i] + money[i - 2], money[i - 1]);
  }
  return money[len - 1];
}

int main() {
  vector<int> nums = {2, 7, 9, 3, 1};
  int ret = get_money(nums);
  cout << "max money: " << ret << endl;
  return 0;
}