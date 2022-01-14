/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:25:18 by wei.zhao          #+#    #+#             */
/*   Updated: 2021/11/17 10:18:30 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

//inside core execute
int partition(int *arr, int left, int right) {
  int index = left;
  int pivot = arr[index];
  swap(arr[index], arr[right]);

  for (int i = left; i < right; ++i) {
    if (arr[i] > pivot)
      swap(arr[index++], arr[i]);
  }
  swap(arr[right], arr[index]);
  return index;
}


// core 0 execute
void qsort(int *arr, int left, int right) {
  if(left>= right)
    return;
  int index = partition(arr, left, right);
  cout << "index: " << index << endl;
  
  qsort(arr, left, index - 1);
  qsort(arr, index + 1, right);
}

int main() {
  int arr[] = {0, 3, 1, 5, 4, 9, 8, 7, 2, 6};
  int arg_sort[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  qsort(arr, 0, 9);
  
  for (auto &elem : arr) {
    cout << elem << ", ";
  }
  cout << endl;
  
  for(auto & index: arg_sort){
    cout << index << ", ";
  }
  cout << endl;
  
}