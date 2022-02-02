/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:35:25 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/19 19:41:52 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &inputs) {
  int len = inputs.size();
  for (int i = 0; i < len; ++i) {
    bool state = true;
    for (int j = 1; j < len - i; ++j) {
      if (inputs[j - 1] > inputs[j]) {
        swap(inputs[j], inputs[j - 1]);
        state = false;
      }
    }
    if (state)
      break;
  }
}

int main() {
  vector<int> arr = {0, 3, 1, 5, 4, 9, 8, 7, 2, 6};
  bubble_sort(arr);
  for (auto &elem : arr) {
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}