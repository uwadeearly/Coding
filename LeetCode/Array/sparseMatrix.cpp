/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sparseMatrix.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:45:06 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/09 17:57:09 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 这个不是LeetCode题目，只是sparse matrix的计算方法，
 * sparse matrix的表示方法是CSR,
 * 具体参考 programming massively parallel processes
 * Nonzero values data[7] {3,1,2,4,1,1,1}
 * Column indices col_index[7]{0,2,1,2,3,0,3}
 * Row Pointers row_ptr[5] { 0, 2,2,5,7}
 */

void Computing(float *data, int *col_index, int *row_ptr, float *x, float *y,
               int row_nums) {
  for (int row = 0; row < row_nums; ++row) {
    int left = row_ptr[row];
    int right = row_ptr[row + 1];
    float dot = 0;

    for (int i = left; i < right; ++i) {
      dot += data[i] * x[col_index[i]];
    }
    y[row] += dot;
  }
}

int main(){
  return 0;
}