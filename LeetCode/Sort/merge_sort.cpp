/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:28:13 by wei.zhao          #+#    #+#             */
/*   Updated: 2021/11/18 20:15:07 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

void merge(int *arr, int *ret, int left, int right) {

  if (left >= right)
    return;

  int mid = ((right - left) >> 1) + left;
  int start_one = left;
  int end_one = mid;
  int start_two = mid + 1;
  int end_two = right;

  merge(arr, ret, start_one, end_one);
  merge(arr, ret, start_two, end_two);
  int k = left;

  while (start_one <= end_one && start_two <= end_two)
    ret[k++] =
        arr[start_one] > arr[start_two] ? arr[start_one++] : arr[start_two++];

  while (start_one <= end_one)
    ret[k++] = arr[start_one++];

  while (start_two <= end_two)
    ret[k++] = arr[start_two++];
  
    /*copy array*/
  for (int i = left; i <= right; ++i) {
    arr[i] = ret[i];
  }
}

void merge_sort(int *arr, int*tmp, const int len) {
  merge(arr, tmp, 0, len - 1);
}

int main() {
  const int length = 8;
  int array[] = {0, 3, 1, 5, 4, 7, 2, 6};
  int tmp[length];
  merge_sort(array, tmp, length);

  for (int i = 0; i < length; ++i) {
    cout << array[i] << ", ";
  }
  cout << endl;

  return 0;
}