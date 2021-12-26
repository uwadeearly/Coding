/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_sort.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:20:10 by wei.zhao          #+#    #+#             */
/*   Updated: 2021/11/18 20:07:27 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int partition(int* arr, int left, int right){
  int index = left;
  int pivot = arr[index];
  swap(arr[index], arr[right]);
  
  for(int i=left; i<right; ++i){
    if(arr[i] > pivot)
      swap(arr[index++], arr[i]);  
  }
  
  swap(arr[right], arr[index]);
  return index;
}

void arg_sort(int*arr, int len, int* sort_index){
  int count =0;
  for(int i=0; i<len; ++i){
    for(int j=0; j<len; ++j){
      if(arr[i] > arr[j])
        count++;
    }
    sort_index[i] = count;
    count = 0;
  }
}

int main(){
  int arr[] = {0, 3, 1, 5, 4, 7, 2, 6};
  const int len = 8;
  int index[len];
  arg_sort(arr, len, index);
  
  for(auto i: index){
    cout << i << ",  ";
  }
  cout << endl;
  
  return 0;
}