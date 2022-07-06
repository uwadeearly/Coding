/*
 * Filename: /home/wei.zhao/cpp_code/Coding/AlphaPhi/test/test_tensor.cpp
 * Path: /home/wei.zhao/cpp_code/Coding/AlphaPhi/test
 * Created Date: Sunday, June 26th 2022, 10:52:33 am
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#include <iostream>
#include <Tensor.hpp>


int main(){
  float data[] = {0, 1., 2., 3., 4., 5., 6., 7.};

  alphaphi::Tensor<float> tensor({2, 4});
  size_t size =tensor.getSize();
  tensor(0, 2) = 5.4;
  std::cout << "size: "<< size << std::endl;
  std::cout << "dims: " << tensor.getDims() << std::endl;
  std::cout << tensor << std::endl;
  tensor.reshape({4, 2});
  std::cout << tensor << std::endl;
  return 0;
}