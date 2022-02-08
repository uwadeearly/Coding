/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topKFrequent.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:54:28 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/02/08 10:59:21 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& arr, int k){
  unordered_map<int, int>counts;
  int max_count = 0;
  for(auto num: arr){
    max_count = max(max_count, ++counts[num]);
  }

  vector<vector<int>> buckets(max_count+1);
  for(auto p: counts){
    buckets[p.second].push_back(p.first);
  }

  vector<int> ans;
  for(int i=max_count; i>0 && ans.size() < k; --i){
    for(auto elem: buckets[i]){
      ans.push_back(elem);
      if(ans.size() == k)
        break;
    }
  }
  
  return ans;
}


int main(){
  vector<int> inputs = {1,1,1,1,2,2,3,4};
  vector<int> ret = topKFrequent(inputs, 2);
  for(auto& elem: ret){
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}