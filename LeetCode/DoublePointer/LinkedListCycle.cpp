/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedListCycle.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:36:47 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/05 19:13:42 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/* 给定一个链表，如果有环路，找出环路的开始点。
 *
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *get_cycle_point(ListNode *list) {
  ListNode *one_ptr = list;
  ListNode *two_ptr = list;
  do{
    if(!(one_ptr && one_ptr))
      return nullptr;
    if (one_ptr == two_ptr) {
      break;
    } else {
      one_ptr = one_ptr->next;
      two_ptr = two_ptr->next->next;
    }
  }while (one_ptr != two_ptr);
  
  one_ptr = list;
  while(one_ptr != two_ptr){
      one_ptr = one_ptr->next;
      two_ptr = two_ptr->next;
  }
  return one_ptr;
}

int main() { return 0; }