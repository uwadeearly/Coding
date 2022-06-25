/*
 * Filename: /home/wei.zhao/cpp_code/Coding/AlphaPhi/operation/operation.hpp
 * Path: /home/wei.zhao/cpp_code/Coding/AlphaPhi/operation
 * Created Date: Saturday, June 25th 2022, 9:41:08 am
 * Author: Zhao Wei
 * 
 * Copyright (c) 2022 The StreamComputing Inc
 */

#ifndef OPERATION_HPP
#define OPERATION_HPP
#include "../Tensor.hpp"
#include <exception>


template<typename T>
void dot(Tensor<T>& dst, Tensor<T>& left, Tensor<T>& right){

}

template<typename T>
void conv2d(Tensor<T>& dst, Tensor<T>& featMap, Tensor<T>&kernel){

}

template<typename T>
void bn(Tensor<T>&dst, Tensor<T>& featMap){

}

template<typename T>
void relu(Tensor<T>& dst, Tensor<T>& featMap){

}

template<typename T>
void softmax(Tensor<T>& dst, Tensor<T>& featMap){

}

template<typename T>
void conv2dTranspose(Tensor<T>&dst, Tensor<T>& featMap, Tensor<T>& kernel){

}

template<typename T>
void transpose(Tensor<T>& dst, Tensor<T>& src){
  auto inShape = dst.getShape();
  auto outShape src.getShape();
  size_t inSize = dst.getSize();
  size_t outSize = src.getSize();

  if(inShape.getSize() != outShape.getSize() || inSize != outSize){
      throw std::length_error("two tensor shape is not eq...");
    }

  

}

#endif