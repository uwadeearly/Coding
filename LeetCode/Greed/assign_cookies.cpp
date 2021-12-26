/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_cookies.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:04:01 by wei.zhao          #+#    #+#             */
/*   Updated: 2021/12/12 15:42:27 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/* 有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
 * 最多一个饼干，且只有饼干的大小大于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩
 * 子可以吃饱
 */
int findContentCookies(vector<int> &childern, vector<int> &cookies) {
  sort(childern.begin(), childern.end());
  sort(cookies.begin(), cookies.end());

  int child=0, cookie=0;
  while(child < childern.size() && cookie < cookies.size()){
    if(childern[child] < cookies[cookie]) ++child;
    ++cookie; 
  }
  return child;
}

int main() {
  vector<int> childern = {1, 2};
  vector<int> cookies = {1, 3, 2};
  int count = findContentCookies(childern, cookies);
  cout << "max childern: " << count << endl;
  return 0;
}