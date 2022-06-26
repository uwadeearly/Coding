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
#include <exception>

#include "../Tensor.hpp"

template <typename T>
void dot(Tensor<T>& dst, Tensor<T>& left, Tensor<T>& right) {}

template <typename T>
void conv2d(Tensor<T>& dst, Tensor<T>& featMap, Tensor<T>& kernel) {}

template <typename T>
void bn(Tensor<T>& dst, Tensor<T>& featMap) {}

template <typename T>
void relu(Tensor<T>& dst, Tensor<T>& featMap) {}

template <typename T>
void softmax(Tensor<T>& dst, Tensor<T>& featMap) {}

template <typename T>
void conv2dTranspose(Tensor<T>& dst, Tensor<T>& featMap, Tensor<T>& kernel) {}

template <typename T>
void transpose2D(Tensor<T>& dst, Tensor<T>& src) {
  if (src.getDims() != dst.getDims() || src.getSize() != dst.getSize()) {
    throw std::length_error("two tensor shape is not eq...");
  }

  size_t rows = inShape[0];
  size_t cols = inShape[1];

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      dst[j * rows + i] = src[i * cols + j];
    }
  }
}

#endif