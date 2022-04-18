/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MinimumPathSum.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:00:12 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/04/18 15:56:55 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int get_min_path_sum(vector<vector<int>>& path){
  int rows = path.size();
  int cols = path[0].size();
  vector<vector<int>> sum(rows, vector<int>(cols, 0));
  
  for(int i=0; i<rows; ++i){
    for(int j=0; j<cols; ++j){
      if(i==0 && j==0){
        sum[i][j] = path[i][j];
      }
      else if(i==0){
        sum[i][j] = path[i][j] + sum[i][j-1];
      }
      else if(j==0){
        sum[i][j] = path[i][j] + sum[i-1][j];
      }
      else{
        sum[i][j] = path[i][j] + std::min(sum[i-1][j], sum[i][j-1]);
      }
    }
  }
  return sum[rows-1][cols-1];
}

int main(){
  vector<vector<int>> inputs = {{1, 3,  1}, {1, 5 ,1}, {4, 2 ,1}};
  int res = get_min_path_sum(inputs);
  cout << "min path val: " << res << endl;
  return 0;
}