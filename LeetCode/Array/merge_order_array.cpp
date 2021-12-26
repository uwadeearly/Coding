/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_order_array.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:12:14 by wei.zhao          #+#    #+#             */
/*   Updated: 2021/11/18 20:13:05 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void merge_order_arr(int *arr_one, int *arr_two, int *arr, int len_one,
                     int len_two) {
  int one_i = 0;
  int two_i = 0;
  int k = 0;
  
  while (one_i < len_one && two_i < len_two) {
    arr[k++] =
        arr_one[one_i] < arr_two[two_i] ? arr_one[one_i++] : arr_two[two_i++];
  }

  while (one_i < len_one)
    arr[k++] = arr_one[one_i++];

  while (two_i < len_two)
    arr[k++] = arr_two[two_i++];
}

int main() {
  int arr_one[] = {1, 3, 4, 5};
  int arr_two[] = {2, 6, 7};
  const int len = 7;
  int arr[len];
  
  merge_order_arr(arr_one, arr_two, arr, 4, 3);
  for (int i = 0; i < len; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << std::endl;
  return 0;
}