/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:49:30 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/19 19:54:22 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

void select_sort(vector<int> &inputs) {
  int len = inputs.size();
  for (int i = 0; i < len - 1; ++i) {
    int mid = i;
    for (int j = i + 1; j < len; ++j) {
      if (inputs[j] < inputs[mid])
        mid = j;
    }
    swap(inputs[i], inputs[mid]);
  }
}

int main() {
  vector<int> arr = {0, 3, 1, 5, 4, 9, 8, 7, 2, 6};
  select_sort(arr);
  for (auto &elem : arr) {
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}