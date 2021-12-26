/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_k.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:11:37 by wei.zhao          #+#    #+#             */
/*   Updated: 2021/11/16 20:38:05 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// search top k index
void select_k_num(int *arr, int k_num, int left, int right) {
  if (arr == nullptr || k_num < 0 || left >= right)
    return;

  int index = left;
  int pivot = arr[index];
  std::swap(arr[index], arr[right]);

  for (int i = left; i < right; ++i) {
    if (arr[i] > pivot)
      std::swap(arr[index++], arr[i]);
  }
  std::swap(arr[right], arr[index]);

  if (index == k_num) {
    std::cout << "index: " << index << std::endl;
    return;
  }

  else if (index < k_num)
    select_k_num(arr, k_num, index + 1, right);
  else
    select_k_num(arr, k_num, left, index - 1);
}

int main() {
  int top_k = 5;
  int array[] = {0, 3, 1, 5, 4, 9, 8, 7, 2, 6};
  select_k_num(array, top_k, 0, 9);
  for(int i=0; i<top_k; ++i){
    std::cout << array[i] << ", ";
  }
  std::cout << std::endl;
  std::cout << "array: " << std::endl;

  for (auto elem : array) {
    std::cout << elem << ", ";
  }
  std::cout << std::endl;
  return 0;
}