/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderTwoArrayMedian.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:38:22 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/22 11:39:41 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

/* 要求两个有序数组的中位数
 * 输入：nums1 = [1,3], nums2 = [2] 输出：2.00000 解释：合并数组 = [1,2,3] ，中位数 2 
 * 输入：nums1 = [1,2], nums2 = [3,4] 输出：2.50000 解释：合并数组 = [1,2,3,4] ，中位数
 * (2 + 3) / 2 = 2.5
 */

int co_rank(vector<int>& in_one, vector<int>& in_two, int k){

}

int get_median(vector<int>& in_one, vector<int>&in_two){
  // merge two array -> one array
  // search question and array is ordered
  int m = in_one.size(), n = in_two.size();
  int mid = (m + n) / 2;
  
}

int main(){
  return 0;
}