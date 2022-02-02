/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:23:59 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/19 19:28:20 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

void insert_sort(vector<int> &inputs) {
  int len = inputs.size();
  for (int i = 0; i < len; ++i) {
    for (int j = i; j > 0; --j) {
      if (inputs[j - 1] > inputs[j]) {
        swap(inputs[j], inputs[j - 1]);
      }
    }
  }
}

int main() {
  vector<int> arr = {0, 3, 1, 5, 4, 9, 8, 7, 2, 6};
  insert_sort(arr);
  for(auto& elem: arr){
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}